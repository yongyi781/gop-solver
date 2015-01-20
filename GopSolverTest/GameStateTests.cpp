#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GopSolverTest
{
	TEST_CLASS(GameStateTests)
	{
	public:
		static std::string airAltarFile;
		static std::string mindAltarFile;

		TEST_CLASS_INITIALIZE(InitializeClass)
		{
			airAltarFile = "C:\\Users\\Yongyi\\Documents\\Visual Studio 2015\\Projects\\GopSolver\\GopSolverLib\\air.txt";
			mindAltarFile = "C:\\Users\\Yongyi\\Documents\\Visual Studio 2015\\Projects\\GopSolver\\GopSolverLib\\mind.txt";
		}

		TEST_METHOD_INITIALIZE(InitializeMethods)
		{
			GopEngine::loadAltarFromFile(mindAltarFile);
		}

		TEST_METHOD(SameOrbsEqual)
		{
			Orb orb1{ Point(3, 4), Point(3, 6) };
			Orb orb2{ Point(3, 4), Point(3, 6) };

			Assert::IsTrue(orb1 == orb2);
		}

		TEST_METHOD(DifferentOrbTargetsNotEqual)
		{
			Orb orb1{ Point(3, 4), Point(3, 6) };
			Orb orb2{ Point(3, 4), Point(3, 8) };

			Assert::IsTrue(orb1 != orb2);
		}

		TEST_METHOD(GameActionToStringIsCorrect)
		{
			GameAction attractA = GameAction::attract(0, true, true);
			GameAction attractB = GameAction::attract(1, false, true);
			GameAction attractC = GameAction::attract(2, true, false, false);

			GameAction idle = GameAction::idle(true, true);
			GameAction move = GameAction::move(Point(-3, 4), true, false);

			Assert::AreEqual("{r}{q}*A", attractA.toString().c_str());
			Assert::AreEqual("{q}*B", attractB.toString().c_str());
			Assert::AreEqual("{r}C", attractC.toString().c_str());

			Assert::AreEqual("{r}{q}-", idle.toString().c_str());
			Assert::AreEqual("{r}(-3,4)", move.toString().c_str());
		}

		TEST_METHOD(FormatActionsIsCorrect)
		{
			GameAction attractA = GameAction::attract(0, true, true);
			GameAction move = GameAction::move(Point(-3, 4), true, false);
			GameAction attractB = GameAction::attract(1, false, true);
			GameAction attractB2 = GameAction::attract(1, false, false, false);

			std::deque<GameAction> actions{ attractA, move, attractB, attractB2, attractB2, attractB2, attractB2 };

			Assert::AreEqual("{r}{q}*A{r}(-3,4){q}*BB[4]", GameAction::formatActions(actions).c_str());
		}

		TEST_METHOD(CopyIsDistinct)
		{
			GameState gs1{ { { 2, 0 } },{ { { 4, 2 } } } };
			GameState gs2{ gs1 };

			gs1.player.action = GameAction::attract(0);
			gs1.step();

			Assert::IsTrue(gs1 != gs2);
		}

		TEST_METHOD(SameStatesAreEqualAndHaveSameHash)
		{
			GameState gs1{ { { 2, 0 } },{ { { 4, 2 } } } };
			GameState gs2{ gs1 };

			Assert::IsTrue(gs1 == gs2);
			Assert::AreEqual(std::hash<GameState>()(gs1), std::hash<GameState>()(gs2));
		}

		TEST_METHOD(SameStatesDifferentActionsAreEqualAndHaveSameHash)
		{
			GameState gs1{ { { 2, 0 } },{ { { 4, 2 } } } };
			GameState gs2{ gs1 };

			gs1.player.action = GameAction::move(Point(0, 2));
			gs2.player.action = GameAction::move(Point(-2, 2));

			Assert::IsTrue(gs1 == gs2);
			Assert::AreEqual(std::hash<GameState>()(gs1), std::hash<GameState>()(gs2));
		}

		TEST_METHOD(MovingDifferentTargetsSamePositionAreEqualAndHaveSameHash)
		{
			GameState gs1{ { { 2, 0 } },{ { { 4, 2 } } } };
			GameState gs2{ gs1 };

			gs1.player.action = GameAction::move(Point(0, 2));
			gs2.player.action = GameAction::move(Point(-2, 2));

			gs1.step();
			gs2.step();

			Assert::IsTrue(gs1 == gs2);
			Assert::AreEqual(std::hash<GameState>()(gs1), std::hash<GameState>()(gs2));
		}

		TEST_METHOD(MovingAndDraggingBeforeForceAreDifferent)
		{
			GameState gs1{ { { 0, -2 } },{ { { -5, 1 } } } };
			GameState gs2{ gs1 };

			gs1.player.action = GameAction::move(Point(-2, 2));
			gs2.player.action = GameAction::attract(0);

			gs1.step();
			gs2.step();

			Assert::IsTrue(gs1 != gs2);
		}

		TEST_METHOD(AttractAndIdleAreDifferent)
		{
			GameState gs1{ { { 0, -2 } },{ { { 0, 5 } } } };
			GameState gs2{ gs1 };

			gs1.player.action = GameAction::attract(0);
			gs2.player.action = GameAction::idle();

			gs1.step();
			gs2.step();

			Assert::IsTrue(gs1 != gs2);
		}

		//TEST_METHOD(HeuristicNonDecreasing)
		//{
		//	// Not implemented yet
		//}
	};

	std::string GameStateTests::airAltarFile;
	std::string GameStateTests::mindAltarFile;
}
