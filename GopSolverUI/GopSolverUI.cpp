// GopSolverUI.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "GopSolverUI.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
HFONT hWindowFont;
HWND hWindow;
HWND hSolutionsListBox;
HWND hPlayButton;
HWND hCopyButton;
HWND hCopyUrlButton;
HWND hNumExpandedLabel;
const TCHAR* playSymbol = _T("\u25b6");
const TCHAR* stopSymbol = _T("\u25a0");
const int PANEL_INITIALWIDTH = 300;
int gridUISize;
int cellSize;
HBRUSH blackBrush;
HBRUSH playerIdleBrush;
HBRUSH playerDraggingBrush;
HBRUSH playerAttractingBrush;
HBRUSH orbBrush;
HBRUSH orbHighlightBrush;
HBRUSH stateBrushes[9];
GameState gs;
GameState tempGs;
std::vector<std::deque<std::pair<GameState, GameAction>>> solutions;
bool isPlaying;
int solutionIndex = -1;
int solutionPathIndex = -1;
int currentAltar = 1;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR lpCmdLine,
	_In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_GOPSOLVERUI, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
		return FALSE;

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GOPSOLVERUI));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GOPSOLVERUI));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_GOPSOLVERUI);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

	const int WIDTH = 652;
	const int HEIGHT = 694;
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		(GetSystemMetrics(SM_CXSCREEN) - WIDTH) / 2, (GetSystemMetrics(SM_CYSCREEN) - HEIGHT - 30) / 2,
		WIDTH + PANEL_INITIALWIDTH, HEIGHT, NULL, NULL, hInstance, NULL);

	if (!hWnd)
		return FALSE;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

inline int clamp(int x, int minimum, int maximum)
{
	return std::min(std::max(x, minimum), maximum);
}

Point fromClientCoords(POINT pt)
{
	return Point((int8_t)(pt.x / cellSize) - GRID_MAX, GRID_MAX - (int8_t)(pt.y / cellSize));
}

// Returns the upper-left corner of the client point.
POINT toClientCoords(Point p)
{
	POINT pt = { (p.x + GRID_MAX) * cellSize, (GRID_MAX - p.y) * cellSize };
	return pt;
}

void FillSquare(HDC hdc, Point p, HBRUSH hbr)
{
	POINT pt = toClientCoords(p);
	RECT rc = { pt.x, pt.y, pt.x + cellSize - 1, pt.y + cellSize - 1 };
	FillRect(hdc, &rc, hbr);
}

void FillSquare(HDC hdc, int8_t x, int8_t y, HBRUSH hbr)
{
	FillSquare(hdc, Point(x, y), hbr);
}

void DrawGrid(HDC hdc, const RECT& rcClient)
{
	FillRect(hdc, &rcClient, blackBrush);
	for (int8_t y = -GRID_MAX; y <= GRID_MAX; ++y)
		for (int8_t x = -GRID_MAX; x <= GRID_MAX; ++x)
		FillSquare(hdc, x, y, stateBrushes[(int)GopBoard::get(x, y)]);
	for (size_t i = 0; i < gs.orbs.size(); ++i)
		if (gs.orbs[i].location != Point::invalid)
		FillSquare(hdc, gs.orbs[i].location, gs.player.currentOrb == (int)i && gs.orbs[i].target != Point::invalid ? orbHighlightBrush : orbBrush);
	FillSquare(hdc, gs.player.location, gs.player.action.getType() == GameActionType::Attract ? gs.player.currentOrb != -1 ? playerAttractingBrush : playerDraggingBrush : playerIdleBrush);

	// Finally, mini-pillars and walls.
	for (int8_t y = -GRID_MAX; y <= GRID_MAX; ++y)
	{
		for (int8_t x = -GRID_MAX; x <= GRID_MAX; ++x)
		{
			POINT p = toClientCoords(Point(x, y));
			if (GopBoard::get(x, y) == Tile::MiniPillar1 || GopBoard::get(x, y) == Tile::MiniPillar2)
			{
				RECT rc = { p.x - 3, p.y + cellSize - 3, p.x + 2, p.y + cellSize + 2 };
				FillRect(hdc, &rc, blackBrush);
			}
			else
			{
				if (GopBoard::get(x, y) == Tile::PanelW || GopBoard::get(x, y) == Tile::PanelSW)
				{
					RECT rc = { p.x - 2, p.y, p.x + 1, p.y + cellSize };
					FillRect(hdc, &rc, blackBrush);
				}
				if (GopBoard::get(x, y) == Tile::PanelS || GopBoard::get(x, y) == Tile::PanelSW)
				{
					RECT rc = { p.x, p.y + cellSize - 2, p.x + cellSize, p.y + cellSize + 1 };
					FillRect(hdc, &rc, blackBrush);
				}
			}
		}
	}
}

void InitializeBrushes()
{
	blackBrush = CreateSolidBrush(RGB(0, 0, 0));
	playerIdleBrush = CreateSolidBrush(RGB(0, 128, 0));
	playerDraggingBrush = CreateSolidBrush(RGB(0, 128, 128));
	playerAttractingBrush = CreateSolidBrush(RGB(0, 255, 255));
	orbBrush = CreateSolidBrush(RGB(255, 255, 0));
	orbHighlightBrush = CreateSolidBrush(RGB(255, 255, 204));
	stateBrushes[0] = CreateSolidBrush(RGB(34, 34, 34));	// Floor
	stateBrushes[1] = blackBrush;							// Wall
	stateBrushes[2] = CreateSolidBrush(RGB(68, 68, 68));	// Rock
	stateBrushes[3] = CreateSolidBrush(RGB(0, 22, 34));		// Water
	stateBrushes[4] = stateBrushes[5] = stateBrushes[6] = stateBrushes[7] = stateBrushes[8] = stateBrushes[0];
}

void InitializeControls(HWND hWnd)
{
	NONCLIENTMETRICS ncm;
	ncm.cbSize = sizeof(NONCLIENTMETRICS);
	SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(NONCLIENTMETRICS), &ncm, 0);
	hWindowFont = CreateFontIndirect(&ncm.lfMessageFont);
	hSolutionsListBox = CreateWindow(_T("ListBox"), _T("Hello"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP | WS_VSCROLL | LBS_NOTIFY, 0, 0,
		1, 1, hWnd, NULL, hInst, NULL);
	hPlayButton = CreateWindow(_T("Button"), playSymbol, WS_CHILD | WS_VISIBLE | WS_TABSTOP, 0, 0,
		1, 1, hWnd, (HMENU)IDB_PLAY, hInst, NULL);
	hCopyButton = CreateWindow(_T("Button"), _T("&Copy"), WS_CHILD | WS_VISIBLE | WS_TABSTOP, 0, 0,
		75, 23, hWnd, (HMENU)IDB_COPY, hInst, NULL);
	hCopyUrlButton = CreateWindow(_T("Button"), _T("Copy &URL"), WS_CHILD | WS_VISIBLE | WS_TABSTOP, 0, 0,
		75, 23, hWnd, (HMENU)IDB_COPYURL, hInst, NULL);
	hNumExpandedLabel = CreateWindow(_T("Static"), _T("Number of nodes explored: "), WS_CHILD | WS_VISIBLE | SS_LEFT, 0, 0,
		200, 19, hWnd, NULL, hInst, NULL);
}

void LoadFileInResource(int name, LPCTSTR type, const char*& data)
{
	HMODULE handle = GetModuleHandle(NULL);
	HRSRC rc = FindResource(handle, MAKEINTRESOURCE(name), type);
	if (rc)
	{
		HGLOBAL rcData = LoadResource(handle, rc);
		if (rcData)
			data = static_cast<const char*>(LockResource(rcData));
	}
}

void SetCurrentAltar(HWND hWnd, int id)
{
	const char* data;
	LoadFileInResource(id, _T("ALTAR"), data);
	GopBoard::loadAltar(data);
	gs.freeze();
	InvalidateRect(hWnd, NULL, false);
	CheckMenuRadioItem(GetMenu(hWnd), ID_ALTAR_NONE, ID_ALTAR_BODY, id, MF_BYCOMMAND);
	// Current altar is a number from 1 (air) to 6 (body).
	currentAltar = id - ID_ALTAR_AIR + 1;
}

void SetPlaying(bool play)
{
	isPlaying = play;
	Button_SetText(hPlayButton, play ? stopSymbol : playSymbol);
	if (!play)
	{
		solutionPathIndex = -1;
		gs = tempGs;
		gs.player.action = GameAction::idle();
	}
}

void LoadSolutionsIntoListBox()
{
	ListBox_ResetContent(hSolutionsListBox);
	for (const auto& solution : solutions)
	{
		std::wostringstream sstr;
		sstr << "[" << solution.size() + 1 << "] ";
		sstr << GameStateNode::getActions(solution).c_str();
		ListBox_AddString(hSolutionsListBox, sstr.str().c_str());
	}
	ListBox_SetCurSel(hSolutionsListBox, 0);
}

void LoadCurrentSolution(int pathIndex = 0)
{
	solutionIndex = ListBox_GetCurSel(hSolutionsListBox);
	solutionPathIndex = pathIndex;
}

void CopyToClipboard(HWND hwnd, const std::string &s) {
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}

void CopyCurrentSolution(bool copyUrl = false)
{
	solutionIndex = ListBox_GetCurSel(hSolutionsListBox);
	if (solutionIndex >= 0)
	{
		auto solution = solutions[solutionIndex];
		std::string actions = GameStateNode::getActions(solution);
		if (!copyUrl)
		{
			CopyToClipboard(hWindow, actions);
		}
		else
		{
			auto startLocation = solution[0].first.player.location;
			auto orbs = solution[0].first.orbs;
			std::ostringstream urlStr;
			urlStr << "http://vief.tk/Solo?numorbs=" << orbs.size() << "&spawns=[";
			for (auto iter = std::begin(orbs); iter != std::end(orbs); iter++)
			{
				if (iter != std::begin(orbs))
					urlStr << ",";
				urlStr << "[" << (int)iter->location.x << "," << (int)iter->location.y << "]";
			}
			urlStr << "]&code={0 " << currentAltar << " " << startLocation.toString() << "r}"
				<< actions;
			CopyToClipboard(hWindow, urlStr.str());
		}
	}
}

void DoSolve()
{
	gs.freeze();
	int numExpanded;
	auto nodes = Solver::solve(gs, &numExpanded, IsDebuggerPresent());
	SetWindowText(hNumExpandedLabel, (_T("Number of nodes explored: ") + std::to_wstring(numExpanded)).c_str());
	solutions.clear();
	for (const auto& node : nodes)
		solutions.push_back(node->getPath());
	LoadSolutionsIntoListBox();
	solutionIndex = 0;
	solutionPathIndex = 1;
	tempGs = gs;
	SetPlaying(true);
}

void CALLBACK TimerProc(HWND hWnd, UINT, UINT_PTR, DWORD)
{
	if (!isPlaying || solutionIndex == -1 || solutionPathIndex == -1)
	{
		gs.step();
		if (gs.player.action.getType() == GameActionType::Attract)
			gs.player.action = gs.player.action.copyWithSettings(false, false, false);
	}
	else if (!solutions.empty() && solutionIndex >= 0 && solutionIndex < (int)solutions.size())
	{
		auto path = solutions[solutionIndex];
		if (!path.empty() && solutionPathIndex < (int)path.size())
		{
			gs.player.action = path[solutionPathIndex++].second;
			gs.step();
		}
		else
			SetPlaying(false);
	}
	InvalidateRect(hWnd, NULL, false);
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rcClient;

	switch (message)
	{
	case WM_CREATE:
		hWindow = hWnd;
		InitializeBrushes();
		InitializeControls(hWnd);
		SetCurrentAltar(hWnd, ID_ALTAR_AIR);
		gs = GameState(Player(Point(0, -2)), { Orb(Point(-9, -3)) });
		SetTimer(hWnd, 1, 600, TimerProc);
		break;
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDB_PLAY:
			LoadCurrentSolution();
			SetPlaying(!isPlaying);
			break;
		case IDB_COPY:
			CopyCurrentSolution();
			break;
		case IDB_COPYURL:
			CopyCurrentSolution(true);
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case ID_ALTAR_NONE:
		case ID_ALTAR_AIR:
		case ID_ALTAR_MIND:
		case ID_ALTAR_WATER:
		case ID_ALTAR_EARTH:
		case ID_ALTAR_FIRE:
		case ID_ALTAR_BODY:
			SetCurrentAltar(hWnd, wmId);
			break;
		case ID_ALTAR_SOLVE:
			DoSolve();
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_LBUTTONDOWN:
	{
		POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
		Point p = fromClientCoords(pt);
		bool b = false;
		for (int i = 0; i < gs.orbs.size(); ++i)
		{
			if (p == gs.orbs[i].location)
			{
				gs.player.action = GameAction::attract(i);
				b = true;
				break;
			}
		}
		if (!b)
		{
			if (p == gs.player.location)
				gs.player.action = GameAction::idle();
			else if (isInRange(p))
				gs.player.action = GameAction::move(p);
		}
		SetFocus(hWnd);
	}
	break;
	case WM_RBUTTONDOWN:
	{
		POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
		Point p = fromClientCoords(pt);
		if (isInRange(p))
		{
			gs.freeze();
			gs.orbs[0].location = p;
		}
		SetFocus(hWnd);
	}
	break;
	case WM_MBUTTONDOWN:
	{
		POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
		Point p = fromClientCoords(pt);
		if (isInRange(p))
		{
			gs.freeze();
			if (gs.orbs.size() < 2)
				gs.orbs.push_back(Orb());
			gs.orbs[1].location = p;
		}
		SetFocus(hWnd);
	}
	break;
	case WM_KEYDOWN:
		if (wParam == 0x53)
			DoSolve();
		break;
	case WM_SIZE:
	{
		int width = LOWORD(lParam);
		int height = HIWORD(lParam);
		gridUISize = std::min(width - PANEL_INITIALWIDTH, height - 29);
		gridUISize = (gridUISize / GRID_SIZE) * GRID_SIZE;
		cellSize = gridUISize / GRID_SIZE;
		int panelWidth = width - gridUISize;

		SetWindowPos(hSolutionsListBox, NULL, gridUISize, 0, panelWidth, height - 40, SWP_SHOWWINDOW);
		SetWindowPos(hPlayButton, NULL, gridUISize + panelWidth / 2 - 52, height - 34, 23, 23, SWP_SHOWWINDOW);
		SetWindowPos(hCopyButton, NULL, gridUISize + panelWidth / 2 - 26, height - 34, 75, 23, SWP_SHOWWINDOW);
		SetWindowPos(hCopyUrlButton, NULL, gridUISize + panelWidth / 2 - 26 + 78, height - 34, 75, 23, SWP_SHOWWINDOW);
		SetWindowPos(hNumExpandedLabel, NULL, 11, height - 29, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
	}
	break;
	case WM_PAINT:
	{
		GetClientRect(hWnd, &rcClient);

		hdc = BeginPaint(hWnd, &ps);
		HDC hdcMem = CreateCompatibleDC(hdc);
		HBITMAP hbm = CreateCompatibleBitmap(hdc, gridUISize, gridUISize);
		SelectObject(hdcMem, hbm);
		DrawGrid(hdcMem, rcClient);
		BitBlt(hdc, 0, 0, gridUISize, gridUISize, hdcMem, 0, 0, SRCCOPY);
		DeleteObject(hbm);
		DeleteObject(hdcMem);

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_PARENTNOTIFY:
		if (LOWORD(wParam) == WM_CREATE)
			SendMessage((HWND)lParam, WM_SETFONT, (WPARAM)hWindowFont, NULL);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
