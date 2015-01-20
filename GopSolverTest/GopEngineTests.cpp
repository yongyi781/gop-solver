#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GopSolverTest
{
	TEST_CLASS(GopEngineTests)
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

		TEST_METHOD(DistanceToReachableWorksCorrectly)
		{
			Assert::AreEqual(2, GopEngine::distanceToReachable({ 0, -2 }, { 12, -10 }));
			Assert::AreEqual(13, GopEngine::distanceToReachable({ 0, -2 }, { -16, 1 }));
		}

		TEST_METHOD(DistanceToPointWorksCorrectly)
		{
			Assert::AreEqual(0, GopEngine::distanceToPoint({ 0, -2 }, { 0, -2 }));
			Assert::AreEqual(1, GopEngine::distanceToPoint({ 0, -2 }, { 1, -2 }));
			Assert::AreEqual(2, GopEngine::distanceToPoint({ 0, -2 }, { 2, -2 }));
			Assert::AreEqual(13, GopEngine::distanceToPoint({ 0, -2 }, { -9, -10 }));
			Assert::AreEqual(-1, GopEngine::distanceToPoint({ 0, -2 }, { 13, 7 }));
		}

		TEST_METHOD(GetPlayerPathWorksCorrectly)
		{
			GopEngine::loadAltarFromFile(airAltarFile);
			auto path1 = GopEngine::getPlayerPath({ 2, 0 }, { -7, 0 });
			auto path2 = GopEngine::getPlayerPath({ 2, 0 }, { 2, -1 });
			auto path3 = GopEngine::getPlayerPath({ 2, 0 }, { -3, -7 }, true);
			auto path4 = GopEngine::getPlayerPath({ 0, -2 }, { 7,-16 }, true);

			std::deque<Point> expectedPath1 =
			{
				{2, -1}, {2,-2}, {1, -2}, {0,-2}, {-1,-2},
				{-2,-2}, {-3,-2}, {-4,-2}, {-5,-2}, {-6,-1},
				{-7,0}
			};

			std::deque<Point> expectedPath2 =
			{
				{ 2, -1 }
			};

			std::deque<Point> expectedPath3 =
			{
				{ 2, -1 },{ 2,-2 },{ 1, -2 },{ 0,-3 },{ 0,-4 },
				{ 0,-5 }, {-1, -6}, {-2, -7}
			};

			std::deque<Point> expectedPath4 =
			{
				{ 1, -2 },{ 2, -3}, {2, -4}, {3, -4}, {4, -5}, {5, -6}
			};

			Assert::IsTrue(expectedPath1 == path1);
			Assert::IsTrue(expectedPath2 == path2);
			Assert::IsTrue(expectedPath3 == path3);
			Assert::IsTrue(expectedPath4 == path4);
		}
	};

	std::string GopEngineTests::airAltarFile;
	std::string GopEngineTests::mindAltarFile;
}