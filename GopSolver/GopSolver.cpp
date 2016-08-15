// GopSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma region Spawns

std::vector<Point> airSpawns{ Point(-5, -9), Point(-4, -9), Point(-3, -9), Point(-2, -9), Point(-1, -9), Point(0, -9), Point(-6, -8), Point(-5, -8), Point(-4, -8), Point(-3, -8), Point(-2, -8), Point(-1, -8), Point(0, -8), Point(1, -8), Point(2, -8), Point(3, -8), Point(-6, -7), Point(-5, -7), Point(-4, -7), Point(-3, -7), Point(-2, -7), Point(-1, -7), Point(0, -7), Point(1, -7), Point(2, -7), Point(3, -7), Point(4, -7), Point(5, -7), Point(6, -7), Point(-6, -6), Point(-5, -6), Point(-4, -6), Point(-2, -6), Point(-1, -6), Point(0, -6), Point(1, -6), Point(2, -6), Point(3, -6), Point(4, -6), Point(5, -6), Point(6, -6), Point(7, -6), Point(-6, -5), Point(-5, -5), Point(-4, -5), Point(-3, -5), Point(-2, -5), Point(-1, -5), Point(0, -5), Point(1, -5), Point(2, -5), Point(3, -5), Point(4, -5), Point(5, -5), Point(6, -5), Point(7, -5), Point(-7, -4), Point(-6, -4), Point(-5, -4), Point(-4, -4), Point(-3, -4), Point(-2, -4), Point(2, -4), Point(3, -4), Point(4, -4), Point(5, -4), Point(6, -4), Point(7, -4), Point(-8, -3), Point(-7, -3), Point(-6, -3), Point(-5, -3), Point(-4, -3), Point(4, -3), Point(5, -3), Point(6, -3), Point(7, -3), Point(-8, -2), Point(-7, -2), Point(-6, -2), Point(-5, -2), Point(-4, -2), Point(4, -2), Point(5, -2), Point(6, -2), Point(7, -2), Point(-8, -1), Point(-7, -1), Point(-6, -1), Point(-5, -1), Point(5, -1), Point(6, -1), Point(7, -1), Point(-8, 0), Point(-7, 0), Point(-6, 0), Point(-5, 0), Point(5, 0), Point(6, 0), Point(7, 0), Point(-8, 1), Point(-7, 1), Point(-6, 1), Point(-5, 1), Point(5, 1), Point(6, 1), Point(7, 1), Point(-8, 2), Point(-7, 2), Point(-6, 2), Point(-5, 2), Point(-4, 2), Point(4, 2), Point(5, 2), Point(6, 2), Point(7, 2), Point(-8, 3), Point(-7, 3), Point(-6, 3), Point(-5, 3), Point(-4, 3), Point(4, 3), Point(5, 3), Point(6, 3), Point(7, 3), Point(-7, 4), Point(-6, 4), Point(-5, 4), Point(-4, 4), Point(-3, 4), Point(-2, 4), Point(2, 4), Point(3, 4), Point(4, 4), Point(5, 4), Point(6, 4), Point(7, 4), Point(-7, 5), Point(-6, 5), Point(-5, 5), Point(-4, 5), Point(-3, 5), Point(-2, 5), Point(-1, 5), Point(0, 5), Point(1, 5), Point(2, 5), Point(3, 5), Point(4, 5), Point(5, 5), Point(6, 5), Point(7, 5), Point(-6, 6), Point(-5, 6), Point(-4, 6), Point(-3, 6), Point(-2, 6), Point(-1, 6), Point(0, 6), Point(1, 6), Point(2, 6), Point(3, 6), Point(4, 6), Point(5, 6), Point(6, 6), Point(7, 6), Point(-6, 7), Point(-5, 7), Point(-4, 7), Point(-3, 7), Point(-2, 7), Point(-1, 7), Point(0, 7), Point(1, 7), Point(2, 7), Point(3, 7), Point(4, 7), Point(5, 7), Point(6, 7), Point(-5, 8), Point(-4, 8), Point(-3, 8), Point(-2, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(3, 8), Point(4, 8), Point(5, 8) };
std::vector<Point> mindSpawns{ Point(-4, -16), Point(-3, -16), Point(-2, -16), Point(-1, -16), Point(0, -16), Point(1, -16), Point(2, -16), Point(3, -16), Point(4, -16), Point(5, -16), Point(6, -16), Point(7, -16), Point(8, -16), Point(9, -16), Point(10, -16), Point(11, -16), Point(13, -16), Point(-3, -15), Point(-2, -15), Point(-1, -15), Point(0, -15), Point(1, -15), Point(2, -15), Point(3, -15), Point(4, -15), Point(5, -15), Point(6, -15), Point(7, -15), Point(8, -15), Point(9, -15), Point(10, -15), Point(12, -15), Point(13, -15), Point(-4, -14), Point(-3, -14), Point(-2, -14), Point(-1, -14), Point(0, -14), Point(1, -14), Point(2, -14), Point(3, -14), Point(4, -14), Point(5, -14), Point(6, -14), Point(8, -14), Point(9, -14), Point(10, -14), Point(11, -14), Point(12, -14), Point(13, -14), Point(-4, -13), Point(-3, -13), Point(-2, -13), Point(-1, -13), Point(0, -13), Point(1, -13), Point(2, -13), Point(3, -13), Point(4, -13), Point(5, -13), Point(6, -13), Point(7, -13), Point(8, -13), Point(9, -13), Point(10, -13), Point(11, -13), Point(12, -13), Point(13, -13), Point(-6, -12), Point(-5, -12), Point(-4, -12), Point(-3, -12), Point(-2, -12), Point(-1, -12), Point(0, -12), Point(1, -12), Point(2, -12), Point(3, -12), Point(4, -12), Point(5, -12), Point(6, -12), Point(7, -12), Point(8, -12), Point(9, -12), Point(10, -12), Point(11, -12), Point(12, -12), Point(-6, -11), Point(-5, -11), Point(-4, -11), Point(-3, -11), Point(-2, -11), Point(-1, -11), Point(0, -11), Point(1, -11), Point(2, -11), Point(3, -11), Point(4, -11), Point(5, -11), Point(6, -11), Point(7, -11), Point(8, -11), Point(9, -11), Point(10, -11), Point(11, -11), Point(12, -11), Point(13, -11), Point(-13, -10), Point(-12, -10), Point(-10, -10), Point(-9, -10), Point(-7, -10), Point(-6, -10), Point(-5, -10), Point(-4, -10), Point(-3, -10), Point(-2, -10), Point(0, -10), Point(2, -10), Point(3, -10), Point(4, -10), Point(5, -10), Point(6, -10), Point(7, -10), Point(8, -10), Point(9, -10), Point(10, -10), Point(11, -10), Point(12, -10), Point(13, -10), Point(14, -10), Point(-14, -9), Point(-13, -9), Point(-12, -9), Point(-11, -9), Point(-10, -9), Point(-9, -9), Point(-8, -9), Point(-7, -9), Point(-6, -9), Point(-5, -9), Point(-4, -9), Point(-3, -9), Point(-2, -9), Point(-1, -9), Point(0, -9), Point(1, -9), Point(2, -9), Point(3, -9), Point(4, -9), Point(5, -9), Point(6, -9), Point(7, -9), Point(8, -9), Point(9, -9), Point(10, -9), Point(11, -9), Point(12, -9), Point(13, -9), Point(14, -9), Point(15, -9), Point(-15, -8), Point(-14, -8), Point(-13, -8), Point(-12, -8), Point(-11, -8), Point(-10, -8), Point(-9, -8), Point(-8, -8), Point(-7, -8), Point(-6, -8), Point(-5, -8), Point(-4, -8), Point(-3, -8), Point(-2, -8), Point(-1, -8), Point(0, -8), Point(1, -8), Point(2, -8), Point(3, -8), Point(4, -8), Point(5, -8), Point(6, -8), Point(7, -8), Point(8, -8), Point(9, -8), Point(10, -8), Point(11, -8), Point(12, -8), Point(13, -8), Point(14, -8), Point(15, -8), Point(-16, -7), Point(-15, -7), Point(-14, -7), Point(-13, -7), Point(-12, -7), Point(-11, -7), Point(-10, -7), Point(-9, -7), Point(-8, -7), Point(-7, -7), Point(6, -7), Point(7, -7), Point(8, -7), Point(9, -7), Point(10, -7), Point(11, -7), Point(12, -7), Point(13, -7), Point(14, -7), Point(15, -7), Point(-16, -6), Point(-15, -6), Point(-14, -6), Point(-13, -6), Point(-12, -6), Point(-11, -6), Point(-10, -6), Point(-9, -6), Point(-8, -6), Point(7, -6), Point(8, -6), Point(9, -6), Point(10, -6), Point(11, -6), Point(12, -6), Point(13, -6), Point(14, -6), Point(15, -6), Point(-16, -5), Point(-15, -5), Point(-14, -5), Point(-13, -5), Point(-12, -5), Point(-11, -5), Point(-10, -5), Point(-9, -5), Point(8, -5), Point(9, -5), Point(10, -5), Point(11, -5), Point(12, -5), Point(13, -5), Point(14, -5), Point(15, -5), Point(-16, -4), Point(-15, -4), Point(-14, -4), Point(-13, -4), Point(-12, -4), Point(-11, -4), Point(-10, -4), Point(8, -4), Point(9, -4), Point(10, -4), Point(11, -4), Point(13, -4), Point(14, -4), Point(-16, -3), Point(-15, -3), Point(-14, -3), Point(-13, -3), Point(-12, -3), Point(-11, -3), Point(-10, -3), Point(8, -3), Point(9, -3), Point(10, -3), Point(11, -3), Point(12, -3), Point(13, -3), Point(14, -3), Point(15, -3), Point(-16, -2), Point(-15, -2), Point(-14, -2), Point(-13, -2), Point(-12, -2), Point(-11, -2), Point(-10, -2), Point(8, -2), Point(9, -2), Point(10, -2), Point(11, -2), Point(12, -2), Point(13, -2), Point(14, -2), Point(15, -2), Point(-16, -1), Point(-15, -1), Point(-14, -1), Point(-13, -1), Point(-12, -1), Point(-11, -1), Point(8, -1), Point(9, -1), Point(11, -1), Point(12, -1), Point(13, -1), Point(14, -1), Point(15, -1), Point(-16, 0), Point(-15, 0), Point(-14, 0), Point(-13, 0), Point(-12, 0), Point(-11, 0), Point(-10, 0), Point(8, 0), Point(9, 0), Point(10, 0), Point(11, 0), Point(12, 0), Point(13, 0), Point(14, 0), Point(15, 0), Point(-16, 1), Point(-15, 1), Point(-14, 1), Point(-13, 1), Point(-12, 1), Point(-11, 1), Point(8, 1), Point(9, 1), Point(11, 1), Point(12, 1), Point(13, 1), Point(14, 1), Point(15, 1), Point(-16, 2), Point(-15, 2), Point(-14, 2), Point(-13, 2), Point(-12, 2), Point(-11, 2), Point(-10, 2), Point(8, 2), Point(9, 2), Point(10, 2), Point(11, 2), Point(12, 2), Point(13, 2), Point(14, 2), Point(-16, 3), Point(-15, 3), Point(-14, 3), Point(-13, 3), Point(-12, 3), Point(-11, 3), Point(-10, 3), Point(8, 3), Point(9, 3), Point(10, 3), Point(11, 3), Point(12, 3), Point(13, 3), Point(-16, 4), Point(-15, 4), Point(-14, 4), Point(-13, 4), Point(-12, 4), Point(-11, 4), Point(-10, 4), Point(8, 4), Point(9, 4), Point(10, 4), Point(11, 4), Point(12, 4), Point(13, 4), Point(14, 4), Point(-16, 5), Point(-15, 5), Point(-14, 5), Point(-13, 5), Point(-12, 5), Point(-11, 5), Point(-10, 5), Point(-9, 5), Point(8, 5), Point(9, 5), Point(10, 5), Point(11, 5), Point(12, 5), Point(13, 5), Point(14, 5), Point(-16, 6), Point(-15, 6), Point(-14, 6), Point(-13, 6), Point(-12, 6), Point(-11, 6), Point(-10, 6), Point(-9, 6), Point(-8, 6), Point(7, 6), Point(8, 6), Point(9, 6), Point(10, 6), Point(11, 6), Point(-16, 7), Point(-15, 7), Point(-14, 7), Point(-13, 7), Point(-12, 7), Point(-11, 7), Point(-10, 7), Point(-9, 7), Point(-8, 7), Point(-7, 7), Point(6, 7), Point(7, 7), Point(8, 7), Point(9, 7), Point(10, 7), Point(-16, 8), Point(-15, 8), Point(-14, 8), Point(-13, 8), Point(-12, 8), Point(-11, 8), Point(-10, 8), Point(-9, 8), Point(-8, 8), Point(-7, 8), Point(-6, 8), Point(-5, 8), Point(-4, 8), Point(-3, 8), Point(-2, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(3, 8), Point(4, 8), Point(5, 8), Point(6, 8), Point(7, 8), Point(8, 8), Point(9, 8), Point(-16, 9), Point(-15, 9), Point(-14, 9), Point(-13, 9), Point(-11, 9), Point(-10, 9), Point(-9, 9), Point(-8, 9), Point(-7, 9), Point(-6, 9), Point(-5, 9), Point(-4, 9), Point(-3, 9), Point(-2, 9), Point(-1, 9), Point(0, 9), Point(1, 9), Point(2, 9), Point(3, 9), Point(4, 9), Point(5, 9), Point(6, 9), Point(-16, 10), Point(-15, 10), Point(-14, 10), Point(-13, 10), Point(-12, 10), Point(-11, 10), Point(-10, 10), Point(-9, 10), Point(-8, 10), Point(-7, 10), Point(-6, 10), Point(-5, 10), Point(-4, 10), Point(-3, 10), Point(-2, 10), Point(0, 10), Point(2, 10), Point(3, 10), Point(4, 10), Point(5, 10), Point(-15, 11), Point(-14, 11), Point(-13, 11), Point(-12, 11), Point(-11, 11), Point(-10, 11), Point(-9, 11), Point(-8, 11), Point(-7, 11), Point(-6, 11), Point(-5, 11), Point(-4, 11), Point(-3, 11), Point(-2, 11), Point(-1, 11), Point(0, 11), Point(1, 11), Point(2, 11), Point(3, 11), Point(4, 11), Point(-15, 12), Point(-14, 12), Point(-12, 12), Point(-10, 12), Point(-8, 12), Point(-7, 12), Point(-6, 12), Point(-5, 12), Point(-4, 12), Point(-3, 12), Point(-2, 12), Point(-1, 12), Point(1, 12), Point(2, 12), Point(3, 12), Point(-7, 13), Point(-3, 13) };
std::vector<Point> newMindSpawns{ Point(-4, -16), Point(-3, -16), Point(-2, -16), Point(-1, -16), Point(0, -16), Point(1, -16), Point(2, -16), Point(3, -16), Point(4, -16), Point(5, -16), Point(6, -16), Point(7, -16), Point(8, -16), Point(9, -16), Point(10, -16), Point(11, -16), Point(13, -16), Point(-3, -15), Point(-2, -15), Point(-1, -15), Point(0, -15), Point(1, -15), Point(2, -15), Point(3, -15), Point(4, -15), Point(5, -15), Point(6, -15), Point(7, -15), Point(8, -15), Point(9, -15), Point(10, -15), Point(12, -15), Point(13, -15), Point(-4, -14), Point(-3, -14), Point(-2, -14), Point(-1, -14), Point(0, -14), Point(1, -14), Point(2, -14), Point(3, -14), Point(4, -14), Point(5, -14), Point(6, -14), Point(8, -14), Point(9, -14), Point(10, -14), Point(11, -14), Point(12, -14), Point(13, -14), Point(-4, -13), Point(-3, -13), Point(-2, -13), Point(-1, -13), Point(0, -13), Point(1, -13), Point(2, -13), Point(3, -13), Point(4, -13), Point(5, -13), Point(6, -13), Point(7, -13), Point(8, -13), Point(9, -13), Point(10, -13), Point(11, -13), Point(12, -13), Point(13, -13), Point(-4, -12), Point(-3, -12), Point(-2, -12), Point(-1, -12), Point(0, -12), Point(1, -12), Point(2, -12), Point(3, -12), Point(4, -12), Point(5, -12), Point(6, -12), Point(7, -12), Point(8, -12), Point(9, -12), Point(10, -12), Point(11, -12), Point(12, -12), Point(-6, -11), Point(-5, -11), Point(-4, -11), Point(-3, -11), Point(-2, -11), Point(-1, -11), Point(0, -11), Point(1, -11), Point(2, -11), Point(3, -11), Point(4, -11), Point(5, -11), Point(6, -11), Point(7, -11), Point(8, -11), Point(9, -11), Point(10, -11), Point(11, -11), Point(12, -11), Point(13, -11), Point(-13, -10), Point(-12, -10), Point(-10, -10), Point(-9, -10), Point(-7, -10), Point(-6, -10), Point(-5, -10), Point(-4, -10), Point(-3, -10), Point(-2, -10), Point(0, -10), Point(2, -10), Point(3, -10), Point(4, -10), Point(5, -10), Point(6, -10), Point(7, -10), Point(8, -10), Point(9, -10), Point(10, -10), Point(11, -10), Point(12, -10), Point(13, -10), Point(14, -10), Point(-14, -9), Point(-13, -9), Point(-12, -9), Point(-11, -9), Point(-10, -9), Point(-9, -9), Point(-8, -9), Point(-7, -9), Point(-6, -9), Point(-5, -9), Point(-4, -9), Point(-3, -9), Point(-2, -9), Point(-1, -9), Point(0, -9), Point(1, -9), Point(2, -9), Point(3, -9), Point(4, -9), Point(5, -9), Point(6, -9), Point(7, -9), Point(8, -9), Point(9, -9), Point(10, -9), Point(11, -9), Point(12, -9), Point(13, -9), Point(14, -9), Point(15, -9), Point(-15, -8), Point(-14, -8), Point(-13, -8), Point(-12, -8), Point(-11, -8), Point(-10, -8), Point(-9, -8), Point(-8, -8), Point(-7, -8), Point(-6, -8), Point(-5, -8), Point(-4, -8), Point(-3, -8), Point(-2, -8), Point(-1, -8), Point(0, -8), Point(1, -8), Point(2, -8), Point(3, -8), Point(4, -8), Point(5, -8), Point(6, -8), Point(7, -8), Point(8, -8), Point(9, -8), Point(10, -8), Point(11, -8), Point(12, -8), Point(13, -8), Point(14, -8), Point(15, -8), Point(-16, -7), Point(-15, -7), Point(-14, -7), Point(-13, -7), Point(-12, -7), Point(-11, -7), Point(-10, -7), Point(-9, -7), Point(-8, -7), Point(-7, -7), Point(6, -7), Point(7, -7), Point(8, -7), Point(9, -7), Point(10, -7), Point(11, -7), Point(12, -7), Point(13, -7), Point(14, -7), Point(15, -7), Point(-16, -6), Point(-15, -6), Point(-14, -6), Point(-13, -6), Point(-12, -6), Point(-11, -6), Point(-10, -6), Point(-9, -6), Point(-8, -6), Point(7, -6), Point(8, -6), Point(9, -6), Point(10, -6), Point(11, -6), Point(12, -6), Point(13, -6), Point(14, -6), Point(15, -6), Point(-16, -5), Point(-15, -5), Point(-14, -5), Point(-13, -5), Point(-12, -5), Point(-11, -5), Point(-10, -5), Point(-9, -5), Point(8, -5), Point(9, -5), Point(10, -5), Point(11, -5), Point(12, -5), Point(13, -5), Point(14, -5), Point(15, -5), Point(-16, -4), Point(-15, -4), Point(-14, -4), Point(-13, -4), Point(-12, -4), Point(-11, -4), Point(-10, -4), Point(8, -4), Point(9, -4), Point(10, -4), Point(11, -4), Point(13, -4), Point(14, -4), Point(-16, -3), Point(-15, -3), Point(-14, -3), Point(-13, -3), Point(-12, -3), Point(-11, -3), Point(-10, -3), Point(8, -3), Point(9, -3), Point(10, -3), Point(11, -3), Point(12, -3), Point(13, -3), Point(14, -3), Point(15, -3), Point(-16, -2), Point(-15, -2), Point(-14, -2), Point(-13, -2), Point(-12, -2), Point(-11, -2), Point(-10, -2), Point(8, -2), Point(9, -2), Point(10, -2), Point(11, -2), Point(12, -2), Point(13, -2), Point(14, -2), Point(15, -2), Point(-16, -1), Point(-15, -1), Point(-14, -1), Point(-13, -1), Point(-12, -1), Point(-11, -1), Point(8, -1), Point(9, -1), Point(11, -1), Point(12, -1), Point(13, -1), Point(14, -1), Point(15, -1), Point(-16, 0), Point(-15, 0), Point(-14, 0), Point(-13, 0), Point(-12, 0), Point(-11, 0), Point(-10, 0), Point(8, 0), Point(9, 0), Point(10, 0), Point(11, 0), Point(12, 0), Point(13, 0), Point(14, 0), Point(15, 0), Point(-16, 1), Point(-15, 1), Point(-14, 1), Point(-13, 1), Point(-12, 1), Point(-11, 1), Point(8, 1), Point(9, 1), Point(11, 1), Point(12, 1), Point(13, 1), Point(14, 1), Point(15, 1), Point(-16, 2), Point(-15, 2), Point(-14, 2), Point(-13, 2), Point(-12, 2), Point(-11, 2), Point(-10, 2), Point(8, 2), Point(9, 2), Point(10, 2), Point(11, 2), Point(12, 2), Point(13, 2), Point(14, 2), Point(-16, 3), Point(-15, 3), Point(-14, 3), Point(-13, 3), Point(-12, 3), Point(-11, 3), Point(-10, 3), Point(8, 3), Point(9, 3), Point(10, 3), Point(11, 3), Point(12, 3), Point(13, 3), Point(-16, 4), Point(-15, 4), Point(-14, 4), Point(-13, 4), Point(-12, 4), Point(-11, 4), Point(-10, 4), Point(8, 4), Point(9, 4), Point(10, 4), Point(11, 4), Point(12, 4), Point(13, 4), Point(14, 4), Point(-16, 5), Point(-15, 5), Point(-14, 5), Point(-13, 5), Point(-12, 5), Point(-11, 5), Point(-10, 5), Point(-9, 5), Point(7, 5), Point(8, 5), Point(9, 5), Point(10, 5), Point(11, 5), Point(12, 5), Point(13, 5), Point(14, 5), Point(-16, 6), Point(-15, 6), Point(-14, 6), Point(-13, 6), Point(-12, 6), Point(-11, 6), Point(-10, 6), Point(-9, 6), Point(-8, 6), Point(7, 6), Point(8, 6), Point(9, 6), Point(10, 6), Point(11, 6), Point(-16, 7), Point(-15, 7), Point(-14, 7), Point(-13, 7), Point(-12, 7), Point(-11, 7), Point(-10, 7), Point(-9, 7), Point(-8, 7), Point(-7, 7), Point(6, 7), Point(7, 7), Point(8, 7), Point(9, 7), Point(10, 7), Point(-16, 8), Point(-15, 8), Point(-14, 8), Point(-13, 8), Point(-12, 8), Point(-11, 8), Point(-10, 8), Point(-9, 8), Point(-8, 8), Point(-7, 8), Point(-6, 8), Point(-5, 8), Point(-4, 8), Point(-3, 8), Point(-2, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(3, 8), Point(4, 8), Point(5, 8), Point(6, 8), Point(7, 8), Point(8, 8), Point(9, 8), Point(-16, 9), Point(-15, 9), Point(-14, 9), Point(-13, 9), Point(-11, 9), Point(-10, 9), Point(-9, 9), Point(-8, 9), Point(-7, 9), Point(-6, 9), Point(-5, 9), Point(-4, 9), Point(-3, 9), Point(-2, 9), Point(-1, 9), Point(0, 9), Point(1, 9), Point(2, 9), Point(3, 9), Point(4, 9), Point(5, 9), Point(6, 9), Point(-16, 10), Point(-15, 10), Point(-14, 10), Point(-13, 10), Point(-12, 10), Point(-11, 10), Point(-10, 10), Point(-9, 10), Point(-8, 10), Point(-7, 10), Point(-6, 10), Point(-5, 10), Point(-4, 10), Point(-3, 10), Point(-2, 10), Point(0, 10), Point(2, 10), Point(3, 10), Point(4, 10), Point(5, 10), Point(-15, 11), Point(-14, 11), Point(-13, 11), Point(-12, 11), Point(-11, 11), Point(-10, 11), Point(-9, 11), Point(-8, 11), Point(-7, 11), Point(-6, 11), Point(-5, 11), Point(-4, 11), Point(-3, 11), Point(-2, 11), Point(-1, 11), Point(0, 11), Point(1, 11), Point(2, 11), Point(3, 11), Point(4, 11), Point(-15, 12), Point(-14, 12), Point(-12, 12), Point(-10, 12), Point(-8, 12), Point(-7, 12), Point(-6, 12), Point(-5, 12), Point(-4, 12), Point(-3, 12), Point(-2, 12), Point(-1, 12), Point(1, 12), Point(2, 12), Point(3, 12), Point(-7, 13), Point(-3, 13) };
std::vector<Point> waterSpawns{ Point(1, -15), Point(2, -15), Point(3, -15), Point(1, -14), Point(2, -14), Point(3, -14), Point(4, -14), Point(5, -14), Point(1, -13), Point(2, -13), Point(3, -13), Point(4, -13), Point(5, -13), Point(6, -13), Point(2, -12), Point(3, -12), Point(4, -12), Point(5, -12), Point(6, -12), Point(7, -12), Point(8, -12), Point(9, -12), Point(3, -11), Point(4, -11), Point(5, -11), Point(6, -11), Point(7, -11), Point(8, -11), Point(9, -11), Point(10, -11), Point(4, -10), Point(5, -10), Point(6, -10), Point(7, -10), Point(8, -10), Point(9, -10), Point(10, -10), Point(-2, -9), Point(-1, -9), Point(0, -9), Point(3, -9), Point(4, -9), Point(5, -9), Point(6, -9), Point(7, -9), Point(8, -9), Point(9, -9), Point(10, -9), Point(11, -9), Point(-7, -8), Point(-6, -8), Point(-5, -8), Point(-2, -8), Point(-1, -8), Point(0, -8), Point(1, -8), Point(2, -8), Point(3, -8), Point(4, -8), Point(5, -8), Point(6, -8), Point(7, -8), Point(9, -8), Point(10, -8), Point(12, -8), Point(-7, -7), Point(-6, -7), Point(-5, -7), Point(-2, -7), Point(-1, -7), Point(0, -7), Point(1, -7), Point(2, -7), Point(3, -7), Point(4, -7), Point(5, -7), Point(6, -7), Point(7, -7), Point(8, -7), Point(9, -7), Point(11, -7), Point(12, -7), Point(-7, -6), Point(-6, -6), Point(-5, -6), Point(-4, -6), Point(-3, -6), Point(-2, -6), Point(-1, -6), Point(0, -6), Point(1, -6), Point(2, -6), Point(3, -6), Point(4, -6), Point(5, -6), Point(6, -6), Point(9, -6), Point(10, -6), Point(11, -6), Point(12, -6), Point(13, -6), Point(-7, -5), Point(-6, -5), Point(-5, -5), Point(-4, -5), Point(-3, -5), Point(-2, -5), Point(-1, -5), Point(0, -5), Point(1, -5), Point(2, -5), Point(3, -5), Point(4, -5), Point(5, -5), Point(6, -5), Point(8, -5), Point(9, -5), Point(10, -5), Point(11, -5), Point(12, -5), Point(13, -5), Point(14, -5), Point(-7, -4), Point(-6, -4), Point(-5, -4), Point(-4, -4), Point(-3, -4), Point(-2, -4), Point(0, -4), Point(2, -4), Point(3, -4), Point(4, -4), Point(5, -4), Point(6, -4), Point(7, -4), Point(8, -4), Point(9, -4), Point(10, -4), Point(12, -4), Point(13, -4), Point(14, -4), Point(15, -4), Point(-7, -3), Point(-6, -3), Point(-5, -3), Point(-4, -3), Point(4, -3), Point(5, -3), Point(6, -3), Point(7, -3), Point(8, -3), Point(9, -3), Point(10, -3), Point(11, -3), Point(12, -3), Point(13, -3), Point(14, -3), Point(15, -3), Point(-8, -2), Point(-7, -2), Point(-6, -2), Point(-5, -2), Point(-4, -2), Point(4, -2), Point(5, -2), Point(6, -2), Point(7, -2), Point(8, -2), Point(9, -2), Point(10, -2), Point(11, -2), Point(12, -2), Point(13, -2), Point(14, -2), Point(-9, -1), Point(-8, -1), Point(-7, -1), Point(-6, -1), Point(-5, -1), Point(5, -1), Point(6, -1), Point(7, -1), Point(8, -1), Point(9, -1), Point(11, -1), Point(13, -1), Point(14, -1), Point(15, -1), Point(-9, 0), Point(-8, 0), Point(-7, 0), Point(-6, 0), Point(-5, 0), Point(-4, 0), Point(4, 0), Point(5, 0), Point(6, 0), Point(7, 0), Point(8, 0), Point(9, 0), Point(10, 0), Point(11, 0), Point(13, 0), Point(14, 0), Point(15, 0), Point(-9, 1), Point(-8, 1), Point(-7, 1), Point(-6, 1), Point(-5, 1), Point(5, 1), Point(6, 1), Point(7, 1), Point(8, 1), Point(9, 1), Point(12, 1), Point(13, 1), Point(14, 1), Point(15, 1), Point(-9, 2), Point(-8, 2), Point(-7, 2), Point(-6, 2), Point(-5, 2), Point(-4, 2), Point(4, 2), Point(5, 2), Point(6, 2), Point(7, 2), Point(8, 2), Point(12, 2), Point(13, 2), Point(14, 2), Point(-9, 3), Point(-8, 3), Point(-7, 3), Point(-6, 3), Point(-5, 3), Point(-4, 3), Point(4, 3), Point(6, 3), Point(7, 3), Point(10, 3), Point(11, 3), Point(12, 3), Point(13, 3), Point(14, 3), Point(-8, 4), Point(-7, 4), Point(-5, 4), Point(-4, 4), Point(-3, 4), Point(-2, 4), Point(0, 4), Point(2, 4), Point(3, 4), Point(4, 4), Point(5, 4), Point(6, 4), Point(9, 4), Point(10, 4), Point(11, 4), Point(12, 4), Point(13, 4), Point(-11, 5), Point(-10, 5), Point(-9, 5), Point(-8, 5), Point(-7, 5), Point(-6, 5), Point(-5, 5), Point(-4, 5), Point(-3, 5), Point(-2, 5), Point(-1, 5), Point(0, 5), Point(1, 5), Point(2, 5), Point(3, 5), Point(4, 5), Point(5, 5), Point(6, 5), Point(7, 5), Point(8, 5), Point(9, 5), Point(10, 5), Point(11, 5), Point(12, 5), Point(-11, 6), Point(-10, 6), Point(-9, 6), Point(-7, 6), Point(-4, 6), Point(-2, 6), Point(0, 6), Point(2, 6), Point(3, 6), Point(4, 6), Point(5, 6), Point(7, 6), Point(8, 6), Point(10, 6), Point(11, 6), Point(12, 6), Point(-10, 7), Point(-9, 7), Point(-8, 7), Point(-7, 7), Point(-2, 7), Point(-1, 7), Point(1, 7), Point(2, 7), Point(3, 7), Point(4, 7), Point(5, 7), Point(8, 7), Point(9, 7), Point(10, 7), Point(11, 7), Point(-9, 8), Point(-8, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(3, 8), Point(4, 8), Point(5, 8), Point(0, 9), Point(1, 9), Point(2, 9), Point(3, 9) };
std::vector<Point> earthSpawns{ Point(-16, -16), Point(-15, -16), Point(-8, -16), Point(-7, -16), Point(2, -16), Point(3, -16), Point(4, -16), Point(5, -16), Point(6, -16), Point(7, -16), Point(8, -16), Point(10, -16), Point(11, -16), Point(12, -16), Point(13, -16), Point(14, -16), Point(-16, -15), Point(-15, -15), Point(-9, -15), Point(-8, -15), Point(-7, -15), Point(4, -15), Point(5, -15), Point(11, -15), Point(12, -15), Point(13, -15), Point(14, -15), Point(-16, -14), Point(-15, -14), Point(-8, -14), Point(-7, -14), Point(-3, -14), Point(4, -14), Point(5, -14), Point(12, -14), Point(13, -14), Point(14, -14), Point(15, -14), Point(-16, -13), Point(-15, -13), Point(-8, -13), Point(-7, -13), Point(-4, -13), Point(-3, -13), Point(-2, -13), Point(-1, -13), Point(4, -13), Point(5, -13), Point(10, -13), Point(11, -13), Point(12, -13), Point(14, -13), Point(15, -13), Point(-16, -12), Point(-15, -12), Point(-14, -12), Point(-13, -12), Point(-12, -12), Point(-9, -12), Point(-8, -12), Point(-7, -12), Point(-4, -12), Point(-2, -12), Point(-1, -12), Point(4, -12), Point(5, -12), Point(11, -12), Point(12, -12), Point(-16, -11), Point(-15, -11), Point(-14, -11), Point(-13, -11), Point(-12, -11), Point(-11, -11), Point(-10, -11), Point(-9, -11), Point(-8, -11), Point(-7, -11), Point(-6, -11), Point(-4, -11), Point(-3, -11), Point(-2, -11), Point(-1, -11), Point(0, -11), Point(1, -11), Point(2, -11), Point(3, -11), Point(4, -11), Point(5, -11), Point(8, -11), Point(11, -11), Point(12, -11), Point(-16, -10), Point(-15, -10), Point(-12, -10), Point(-11, -10), Point(-10, -10), Point(-9, -10), Point(-8, -10), Point(-7, -10), Point(-6, -10), Point(-5, -10), Point(-4, -10), Point(-3, -10), Point(-2, -10), Point(-1, -10), Point(0, -10), Point(1, -10), Point(2, -10), Point(3, -10), Point(4, -10), Point(5, -10), Point(6, -10), Point(7, -10), Point(8, -10), Point(11, -10), Point(12, -10), Point(-16, -9), Point(-15, -9), Point(-14, -9), Point(10, -9), Point(11, -9), Point(12, -9), Point(-15, -8), Point(-14, -8), Point(10, -8), Point(11, -8), Point(12, -8), Point(13, -8), Point(-14, -7), Point(10, -7), Point(-14, -6), Point(15, -6), Point(-14, -5), Point(-13, -5), Point(15, -5), Point(-14, -4), Point(-13, -4), Point(-12, -4), Point(-11, -4), Point(-10, -4), Point(-9, -4), Point(15, -4), Point(-14, -3), Point(-13, -3), Point(-12, -3), Point(-11, -3), Point(-10, -3), Point(-9, -3), Point(15, -3), Point(-14, -2), Point(-13, -2), Point(-12, -2), Point(-11, -2), Point(-10, -2), Point(-9, -2), Point(10, -2), Point(11, -2), Point(12, -2), Point(13, -2), Point(15, -2), Point(-16, -1), Point(-15, -1), Point(-14, -1), Point(-13, -1), Point(-12, -1), Point(10, -1), Point(11, -1), Point(12, -1), Point(-16, 0), Point(-15, 0), Point(-14, 0), Point(10, 0), Point(-16, 1), Point(10, 1), Point(-16, 2), Point(10, 2), Point(11, 2), Point(12, 2), Point(-16, 3), Point(-15, 3), Point(-12, 3), Point(-11, 3), Point(-10, 3), Point(-9, 3), Point(10, 3), Point(11, 3), Point(12, 3), Point(13, 3), Point(-16, 4), Point(-15, 4), Point(-12, 4), Point(-11, 4), Point(-10, 4), Point(-9, 4), Point(10, 4), Point(11, 4), Point(12, 4), Point(13, 4), Point(14, 4), Point(15, 4), Point(-16, 5), Point(-15, 5), Point(-14, 5), Point(-13, 5), Point(-12, 5), Point(10, 5), Point(11, 5), Point(12, 5), Point(15, 5), Point(-16, 6), Point(-15, 6), Point(-14, 6), Point(-13, 6), Point(-12, 6), Point(10, 6), Point(12, 6), Point(15, 6), Point(-14, 7), Point(-13, 7), Point(-12, 7), Point(-11, 7), Point(10, 7), Point(11, 7), Point(12, 7), Point(13, 7), Point(14, 7), Point(15, 7), Point(-14, 8), Point(-13, 8), Point(-12, 8), Point(-7, 8), Point(-6, 8), Point(-5, 8), Point(-4, 8), Point(-3, 8), Point(-2, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(11, 8), Point(12, 8), Point(13, 8), Point(14, 8), Point(15, 8), Point(-14, 9), Point(-13, 9), Point(-12, 9), Point(-7, 9), Point(-6, 9), Point(-5, 9), Point(-4, 9), Point(-3, 9), Point(-2, 9), Point(-1, 9), Point(0, 9), Point(1, 9), Point(2, 9), Point(3, 9), Point(5, 9), Point(6, 9), Point(7, 9), Point(8, 9), Point(-14, 10), Point(-13, 10), Point(-12, 10), Point(-11, 10), Point(-10, 10), Point(-9, 10), Point(-8, 10), Point(-7, 10), Point(-6, 10), Point(-5, 10), Point(-4, 10), Point(-3, 10), Point(-2, 10), Point(-1, 10), Point(1, 10), Point(2, 10), Point(3, 10), Point(4, 10), Point(5, 10), Point(6, 10), Point(7, 10), Point(-13, 11), Point(-12, 11), Point(-11, 11), Point(-10, 11), Point(-9, 11), Point(-8, 11), Point(-7, 11), Point(-4, 11), Point(-3, 11), Point(-2, 11), Point(2, 11), Point(3, 11), Point(4, 11), Point(5, 11), Point(6, 11), Point(7, 11), Point(-12, 12), Point(-11, 12), Point(-10, 12), Point(-9, 12), Point(-7, 12), Point(-4, 12), Point(-3, 12), Point(2, 12), Point(5, 12), Point(-11, 13), Point(-10, 13), Point(-3, 13), Point(-11, 14), Point(-10, 14), Point(-9, 14) };
std::vector<Point> newEarthSpawns{ { -16, -16 },{ -15, -16 },{ -8, -16 },{ -7, -16 },{ 2, -16 },{ 3, -16 },{ 4, -16 },{ 5, -16 },{ 6, -16 },{ 7, -16 },{ 8, -16 },{ 10, -16 },{ 11, -16 },{ 12, -16 },{ 13, -16 },{ 14, -16 },{ -16, -15 },{ -15, -15 },{ -9, -15 },{ -8, -15 },{ -7, -15 },{ 4, -15 },{ 5, -15 },{ 11, -15 },{ 12, -15 },{ 13, -15 },{ 14, -15 },{ -16, -14 },{ -15, -14 },{ -8, -14 },{ -7, -14 },{ -3, -14 },{ 4, -14 },{ 5, -14 },{ 12, -14 },{ 13, -14 },{ 14, -14 },{ 15, -14 },{ -16, -13 },{ -15, -13 },{ -8, -13 },{ -7, -13 },{ -4, -13 },{ -3, -13 },{ -2, -13 },{ -1, -13 },{ 4, -13 },{ 5, -13 },{ 10, -13 },{ 11, -13 },{ 12, -13 },{ 14, -13 },{ 15, -13 },{ -16, -12 },{ -15, -12 },{ -14, -12 },{ -13, -12 },{ -12, -12 },{ -9, -12 },{ -8, -12 },{ -7, -12 },{ -4, -12 },{ -2, -12 },{ -1, -12 },{ 4, -12 },{ 5, -12 },{ 11, -12 },{ 12, -12 },{ -16, -11 },{ -15, -11 },{ -14, -11 },{ -13, -11 },{ -12, -11 },{ -11, -11 },{ -10, -11 },{ -9, -11 },{ -8, -11 },{ -7, -11 },{ -6, -11 },{ -4, -11 },{ -3, -11 },{ -2, -11 },{ -1, -11 },{ 0, -11 },{ 1, -11 },{ 2, -11 },{ 3, -11 },{ 4, -11 },{ 5, -11 },{ 11, -11 },{ 12, -11 },{ -16, -10 },{ -15, -10 },{ -12, -10 },{ -11, -10 },{ -10, -10 },{ -9, -10 },{ -8, -10 },{ -7, -10 },{ -6, -10 },{ -5, -10 },{ -4, -10 },{ -3, -10 },{ -2, -10 },{ -1, -10 },{ 0, -10 },{ 1, -10 },{ 2, -10 },{ 3, -10 },{ 4, -10 },{ 5, -10 },{ 6, -10 },{ 7, -10 },{ 8, -10 },{ 11, -10 },{ 12, -10 },{ -16, -9 },{ -15, -9 },{ -14, -9 },{ 10, -9 },{ 11, -9 },{ 12, -9 },{ -15, -8 },{ -14, -8 },{ 10, -8 },{ 11, -8 },{ 12, -8 },{ 13, -8 },{ -14, -7 },{ 10, -7 },{ -14, -6 },{ 15, -6 },{ -14, -5 },{ -13, -5 },{ 15, -5 },{ -14, -4 },{ -13, -4 },{ -12, -4 },{ -11, -4 },{ -10, -4 },{ -9, -4 },{ 15, -4 },{ -14, -3 },{ -13, -3 },{ -12, -3 },{ -11, -3 },{ -10, -3 },{ -9, -3 },{ 15, -3 },{ -14, -2 },{ -13, -2 },{ -12, -2 },{ -11, -2 },{ -10, -2 },{ -9, -2 },{ 11, -2 },{ 12, -2 },{ 13, -2 },{ 15, -2 },{ -16, -1 },{ -15, -1 },{ -14, -1 },{ -13, -1 },{ -12, -1 },{ 11, -1 },{ 12, -1 },{ -16, 0 },{ -15, 0 },{ -14, 0 },{ -16, 1 },{ -16, 2 },{ 11, 2 },{ 12, 2 },{ -16, 3 },{ -15, 3 },{ -12, 3 },{ -11, 3 },{ -10, 3 },{ -9, 3 },{ 11, 3 },{ 12, 3 },{ 13, 3 },{ -16, 4 },{ -15, 4 },{ -12, 4 },{ -11, 4 },{ -10, 4 },{ -9, 4 },{ 11, 4 },{ 12, 4 },{ 13, 4 },{ 14, 4 },{ 15, 4 },{ -16, 5 },{ -15, 5 },{ -14, 5 },{ -13, 5 },{ -12, 5 },{ 11, 5 },{ 12, 5 },{ 15, 5 },{ -16, 6 },{ -15, 6 },{ -14, 6 },{ -13, 6 },{ -12, 6 },{ 10, 6 },{ 12, 6 },{ 15, 6 },{ -14, 7 },{ -13, 7 },{ -12, 7 },{ -11, 7 },{ 10, 7 },{ 11, 7 },{ 12, 7 },{ 13, 7 },{ 14, 7 },{ 15, 7 },{ -14, 8 },{ -13, 8 },{ -12, 8 },{ -7, 8 },{ -6, 8 },{ -5, 8 },{ -4, 8 },{ -3, 8 },{ -2, 8 },{ -1, 8 },{ 0, 8 },{ 1, 8 },{ 2, 8 },{ 11, 8 },{ 12, 8 },{ 13, 8 },{ 14, 8 },{ 15, 8 },{ -14, 9 },{ -13, 9 },{ -12, 9 },{ -7, 9 },{ -6, 9 },{ -5, 9 },{ -4, 9 },{ -3, 9 },{ -2, 9 },{ -1, 9 },{ 0, 9 },{ 1, 9 },{ 2, 9 },{ 3, 9 },{ 5, 9 },{ 6, 9 },{ 7, 9 },{ 8, 9 },{ -14, 10 },{ -13, 10 },{ -12, 10 },{ -11, 10 },{ -10, 10 },{ -9, 10 },{ -8, 10 },{ -7, 10 },{ -6, 10 },{ -5, 10 },{ -4, 10 },{ -3, 10 },{ -2, 10 },{ -1, 10 },{ 1, 10 },{ 2, 10 },{ 3, 10 },{ 4, 10 },{ 5, 10 },{ 6, 10 },{ 7, 10 },{ -13, 11 },{ -12, 11 },{ -11, 11 },{ -10, 11 },{ -9, 11 },{ -8, 11 },{ -7, 11 },{ -4, 11 },{ -3, 11 },{ -2, 11 },{ 2, 11 },{ 3, 11 },{ 4, 11 },{ 5, 11 },{ 6, 11 },{ 7, 11 },{ -12, 12 },{ -11, 12 },{ -10, 12 },{ -9, 12 },{ -7, 12 },{ -4, 12 },{ -3, 12 },{ 2, 12 },{ 5, 12 },{ -11, 13 },{ -10, 13 },{ -11, 14 },{ -10, 14 },{ -9, 14 } };
std::vector<Point> fireSpawns{ Point(-8, -7), Point(-5, -7), Point(-8, -6), Point(-7, -6), Point(-6, -6), Point(-5, -6), Point(-4, -6), Point(-1, -6), Point(2, -6), Point(3, -6), Point(4, -6), Point(-8, -5), Point(-7, -5), Point(-6, -5), Point(-4, -5), Point(-3, -5), Point(-2, -5), Point(-1, -5), Point(0, -5), Point(1, -5), Point(2, -5), Point(3, -5), Point(4, -5), Point(-8, -4), Point(-7, -4), Point(-6, -4), Point(-5, -4), Point(-4, -4), Point(-3, -4), Point(-2, -4), Point(0, -4), Point(2, -4), Point(3, -4), Point(4, -4), Point(5, -4), Point(-9, -3), Point(-8, -3), Point(-7, -3), Point(-6, -3), Point(-5, -3), Point(-4, -3), Point(4, -3), Point(5, -3), Point(6, -3), Point(7, -3), Point(-8, -2), Point(-7, -2), Point(-6, -2), Point(-5, -2), Point(-4, -2), Point(4, -2), Point(5, -2), Point(6, -2), Point(7, -2), Point(-8, -1), Point(-7, -1), Point(-6, -1), Point(-5, -1), Point(5, -1), Point(6, -1), Point(-8, 0), Point(-7, 0), Point(-6, 0), Point(-5, 0), Point(-4, 0), Point(4, 0), Point(5, 0), Point(6, 0), Point(-8, 1), Point(-7, 1), Point(-6, 1), Point(-5, 1), Point(5, 1), Point(6, 1), Point(7, 1), Point(-7, 2), Point(-6, 2), Point(-5, 2), Point(-4, 2), Point(4, 2), Point(5, 2), Point(7, 2), Point(-6, 3), Point(-5, 3), Point(-4, 3), Point(4, 3), Point(5, 3), Point(6, 3), Point(-6, 4), Point(-5, 4), Point(-4, 4), Point(-3, 4), Point(-2, 4), Point(0, 4), Point(2, 4), Point(3, 4), Point(4, 4), Point(5, 4), Point(6, 4), Point(7, 4), Point(-8, 5), Point(-7, 5), Point(-6, 5), Point(-4, 5), Point(-3, 5), Point(-2, 5), Point(-1, 5), Point(0, 5), Point(1, 5), Point(2, 5), Point(3, 5), Point(4, 5), Point(6, 5), Point(7, 5), Point(-8, 6), Point(-7, 6), Point(-6, 6), Point(-5, 6), Point(-4, 6), Point(-3, 6), Point(-2, 6), Point(-1, 6), Point(0, 6), Point(1, 6), Point(2, 6), Point(3, 6), Point(4, 6), Point(5, 6), Point(6, 6), Point(7, 6), Point(-8, 7), Point(-7, 7), Point(-6, 7), Point(-5, 7), Point(-4, 7), Point(-3, 7), Point(-2, 7), Point(-1, 7), Point(0, 7), Point(1, 7), Point(2, 7), Point(3, 7), Point(4, 7), Point(5, 7), Point(-8, 8), Point(-7, 8), Point(-6, 8), Point(-5, 8), Point(-4, 8), Point(-3, 8), Point(-2, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(4, 8), Point(5, 8), Point(-8, 9), Point(-6, 9), Point(-5, 9), Point(-2, 9), Point(-1, 9), Point(0, 9), Point(1, 9), Point(4, 9), Point(5, 9), Point(6, 9), Point(-8, 10), Point(-7, 10), Point(-6, 10), Point(-5, 10), Point(0, 10), Point(2, 10), Point(3, 10), Point(5, 10), Point(-7, 11), Point(-6, 11), Point(-5, 11), Point(-4, 11), Point(-3, 11), Point(3, 11) };
std::vector<Point> newFireSpawns{ Point(-8, -7), Point(-5, -7), Point(-8, -6), Point(-7, -6), Point(-6, -6), Point(-5, -6), Point(-4, -6), Point(-1, -6), Point(2, -6), Point(3, -6), Point(4, -6), Point(-8, -5), Point(-7, -5), Point(-6, -5), Point(-4, -5), Point(-3, -5), Point(-2, -5), Point(-1, -5), Point(0, -5), Point(1, -5), Point(2, -5), Point(3, -5), Point(4, -5), Point(-8, -4), Point(-7, -4), Point(-6, -4), Point(-5, -4), Point(-4, -4), Point(-3, -4), Point(-2, -4), Point(0, -4), Point(2, -4), Point(3, -4), Point(4, -4), Point(5, -4), Point(-9, -3), Point(-8, -3), Point(-7, -3), Point(-6, -3), Point(-5, -3), Point(-4, -3), Point(4, -3), Point(5, -3), Point(6, -3), Point(7, -3), Point(-8, -2), Point(-7, -2), Point(-6, -2), Point(-5, -2), Point(-4, -2), Point(4, -2), Point(5, -2), Point(6, -2), Point(7, -2), Point(-8, -1), Point(-7, -1), Point(-6, -1), Point(-5, -1), Point(5, -1), Point(6, -1), Point(-8, 0), Point(-7, 0), Point(-6, 0), Point(-5, 0), Point(-4, 0), Point(4, 0), Point(5, 0), Point(6, 0), Point(-8, 1), Point(-7, 1), Point(-6, 1), Point(-5, 1), Point(5, 1), Point(6, 1), Point(7, 1), Point(-7, 2), Point(-6, 2), Point(-5, 2), Point(-4, 2), Point(4, 2), Point(5, 2), Point(7, 2), Point(-6, 3), Point(-5, 3), Point(-4, 3), Point(4, 3), Point(5, 3), Point(6, 3), Point(-6, 4), Point(-5, 4), Point(-4, 4), Point(-3, 4), Point(-2, 4), Point(0, 4), Point(2, 4), Point(3, 4), Point(4, 4), Point(5, 4), Point(6, 4), Point(7, 4), Point(-8, 5), Point(-7, 5), Point(-6, 5), Point(-4, 5), Point(-3, 5), Point(-2, 5), Point(-1, 5), Point(0, 5), Point(1, 5), Point(2, 5), Point(3, 5), Point(4, 5), Point(6, 5), Point(7, 5), Point(-8, 6), Point(-7, 6), Point(-6, 6), Point(-5, 6), Point(-4, 6), Point(-3, 6), Point(-2, 6), Point(-1, 6), Point(0, 6), Point(1, 6), Point(2, 6), Point(3, 6), Point(4, 6), Point(5, 6), Point(6, 6), Point(7, 6), Point(-8, 7), Point(-7, 7), Point(-6, 7), Point(-5, 7), Point(-4, 7), Point(-3, 7), Point(-2, 7), Point(-1, 7), Point(0, 7), Point(1, 7), Point(2, 7), Point(3, 7), Point(4, 7), Point(5, 7), Point(-8, 8), Point(-7, 8), Point(-6, 8), Point(-5, 8), Point(-4, 8), Point(-3, 8), Point(-2, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(4, 8), Point(5, 8), Point(-8, 9), Point(-6, 9), Point(-2, 9), Point(-1, 9), Point(0, 9), Point(1, 9), Point(4, 9), Point(5, 9), Point(6, 9), Point(-8, 10), Point(-7, 10), Point(-6, 10), Point(-5, 10), Point(0, 10), Point(2, 10), Point(3, 10), Point(5, 10), Point(-7, 11), Point(-6, 11), Point(-5, 11), Point(-4, 11), Point(-3, 11), Point(3, 11) };
std::vector<Point> bodySpawns{ Point(3, -10), Point(-2, -9), Point(-1, -9), Point(2, -9), Point(3, -9), Point(-5, -8), Point(-4, -8), Point(-3, -8), Point(-2, -8), Point(-1, -8), Point(0, -8), Point(1, -8), Point(2, -8), Point(-4, -7), Point(-3, -7), Point(-1, -7), Point(0, -7), Point(1, -7), Point(2, -7), Point(3, -7), Point(5, -7), Point(-6, -6), Point(-5, -6), Point(-4, -6), Point(-3, -6), Point(-2, -6), Point(-1, -6), Point(0, -6), Point(1, -6), Point(2, -6), Point(3, -6), Point(4, -6), Point(5, -6), Point(6, -6), Point(-9, -5), Point(-8, -5), Point(-7, -5), Point(-6, -5), Point(-5, -5), Point(-4, -5), Point(-3, -5), Point(-2, -5), Point(-1, -5), Point(0, -5), Point(1, -5), Point(2, -5), Point(3, -5), Point(4, -5), Point(7, -5), Point(-8, -4), Point(-7, -4), Point(-6, -4), Point(-5, -4), Point(-4, -4), Point(-3, -4), Point(-2, -4), Point(0, -4), Point(2, -4), Point(3, -4), Point(4, -4), Point(5, -4), Point(6, -4), Point(7, -4), Point(-11, -3), Point(-10, -3), Point(-8, -3), Point(-7, -3), Point(-6, -3), Point(-5, -3), Point(-4, -3), Point(4, -3), Point(5, -3), Point(6, -3), Point(7, -3), Point(-10, -2), Point(-9, -2), Point(-8, -2), Point(-7, -2), Point(-6, -2), Point(-5, -2), Point(-4, -2), Point(4, -2), Point(5, -2), Point(6, -2), Point(7, -2), Point(-11, -1), Point(-10, -1), Point(-9, -1), Point(-8, -1), Point(-7, -1), Point(-6, -1), Point(-5, -1), Point(5, -1), Point(6, -1), Point(7, -1), Point(8, -1), Point(-10, 0), Point(-9, 0), Point(-8, 0), Point(-7, 0), Point(-6, 0), Point(-5, 0), Point(-4, 0), Point(4, 0), Point(5, 0), Point(6, 0), Point(7, 0), Point(8, 0), Point(9, 0), Point(-11, 1), Point(-10, 1), Point(-9, 1), Point(-8, 1), Point(-7, 1), Point(-6, 1), Point(-5, 1), Point(5, 1), Point(6, 1), Point(7, 1), Point(8, 1), Point(9, 1), Point(-12, 2), Point(-11, 2), Point(-10, 2), Point(-9, 2), Point(-8, 2), Point(-7, 2), Point(-6, 2), Point(-5, 2), Point(-4, 2), Point(4, 2), Point(5, 2), Point(6, 2), Point(7, 2), Point(8, 2), Point(9, 2), Point(-12, 3), Point(-11, 3), Point(-10, 3), Point(-9, 3), Point(-8, 3), Point(-7, 3), Point(-6, 3), Point(-5, 3), Point(-4, 3), Point(4, 3), Point(5, 3), Point(6, 3), Point(7, 3), Point(8, 3), Point(9, 3), Point(10, 3), Point(-14, 4), Point(-13, 4), Point(-12, 4), Point(-11, 4), Point(-9, 4), Point(-8, 4), Point(-7, 4), Point(-6, 4), Point(-5, 4), Point(-4, 4), Point(-3, 4), Point(-2, 4), Point(0, 4), Point(2, 4), Point(3, 4), Point(4, 4), Point(5, 4), Point(6, 4), Point(7, 4), Point(8, 4), Point(9, 4), Point(10, 4), Point(-16, 5), Point(-15, 5), Point(-14, 5), Point(-13, 5), Point(-11, 5), Point(-10, 5), Point(-9, 5), Point(-8, 5), Point(-7, 5), Point(-6, 5), Point(-5, 5), Point(-4, 5), Point(-3, 5), Point(-2, 5), Point(-1, 5), Point(0, 5), Point(1, 5), Point(2, 5), Point(3, 5), Point(4, 5), Point(5, 5), Point(6, 5), Point(7, 5), Point(8, 5), Point(9, 5), Point(-12, 6), Point(-11, 6), Point(-10, 6), Point(-9, 6), Point(-7, 6), Point(-6, 6), Point(-5, 6), Point(-4, 6), Point(-3, 6), Point(-2, 6), Point(0, 6), Point(1, 6), Point(2, 6), Point(3, 6), Point(4, 6), Point(5, 6), Point(6, 6), Point(7, 6), Point(8, 6), Point(-13, 7), Point(-12, 7), Point(-10, 7), Point(-9, 7), Point(-8, 7), Point(-6, 7), Point(-5, 7), Point(-4, 7), Point(-3, 7), Point(-2, 7), Point(-1, 7), Point(0, 7), Point(1, 7), Point(2, 7), Point(3, 7), Point(4, 7), Point(5, 7), Point(6, 7), Point(7, 7), Point(-5, 8), Point(-3, 8), Point(2, 8), Point(4, 8), Point(5, 8), Point(6, 8), Point(7, 8), Point(7, 9), Point(8, 9) };

std::array<std::vector<Point>, 6> altarSpawns{ airSpawns, mindSpawns, waterSpawns, newEarthSpawns, newFireSpawns, bodySpawns };
std::array<std::string, 6> altarFiles{ "..\\GopSolverLib\\air.txt", "..\\GopSolverLib\\mind.txt", "..\\GopSolverLib\\water.txt" , "..\\GopSolverLib\\earth.txt" , "..\\GopSolverLib\\fire.txt" , "..\\GopSolverLib\\body.txt" };
std::array<std::string, 6> altarNames{ "air", "mind", "water", "earth", "fire", "body" };

#pragma endregion

using std::chrono::high_resolution_clock;
using std::chrono::time_point;
using std::chrono::nanoseconds;
using std::cout;
using std::endl;

template<class F0>
double timeFunc(F0 f, int repetitions = 1)
{
	auto t = high_resolution_clock::now();
	for (int i = 0; i < repetitions; ++i)
		f();
	auto x = high_resolution_clock::now() - t;
	return (double)std::chrono::duration_cast<nanoseconds>(x).count() / repetitions / 1000000000;
}

time_point<high_resolution_clock> currentTime()
{
	return high_resolution_clock::now();
}

#define SPAWNS mindSpawns

GopArray<std::shared_ptr<GopArray<int>>> altarPars[6];

void doAverageSolvingCosts(int altar, Point playerLocation, std::function<bool(Point)> filter, std::ostream& out)
{
	GopBoard::loadAltarFromFile(altarFiles[altar]);
	int costSum = 0;
	int spawnNum = 0;
	std::vector<Point> filteredSpawns;
	std::copy_if(std::begin(altarSpawns[altar]), std::end(altarSpawns[altar]), std::back_inserter(filteredSpawns), filter);

	for (auto spawn : filteredSpawns)
	{
		GameState initialState{ Player{ playerLocation },{ Orb{ spawn } } };
		auto solution = Solver::solve(initialState);
		int cost = solution[0]->cost + 2;
		out << "Spawn " << ++spawnNum << " of " << filteredSpawns.size() << ": " << spawn.toString() << ", " << cost << std::endl;
		costSum += cost;
	}

	out << "Average cost from " << playerLocation.toString() << ": " << (double)costSum / filteredSpawns.size() << endl;
}

const GopArray<int>& getPars(int altar, Point playerLocation)
{
	if (altarPars[altar][playerLocation])
		return *altarPars[altar][playerLocation];

	GopArray<int> grid;
	std::string tag = altarNames[altar] + playerLocation.toString();
	std::string fileName = "pars\\" + tag + ".txt";
	std::ifstream fin(fileName);
	if (!fin)
	{
		std::cout << "File does not exist. Calculating pars for " << tag << "..." << std::endl;
		std::ofstream fout(fileName);
		doAverageSolvingCosts(altar, playerLocation, [](Point) { return true; }, fout);
		fout.close();
		fin.open(fileName);
	}

	if (!fin)
	{
		std::cerr << "An error occurred." << std::endl;
		throw std::exception("An error occurred.");
	}

	std::string str;
	std::ostringstream ostr;
	std::regex r{ R"(Spawn (\d+) of (\d+): \((-?\d+),(-?\d+)\), (\d+))" };
	std::smatch m;
	do
	{
		std::getline(fin, str);
		if (!std::regex_search(str, m, r))
			break;
		Point p{ (int8_t)atoi(m[3].str().c_str()), (int8_t)atoi(m[4].str().c_str()) };
		grid[p] = atoi(m[5].str().c_str());
	} while (str[0] == 'S');

	altarPars[altar][playerLocation] = std::make_shared<GopArray<int>>(grid);
	return *altarPars[altar][playerLocation];
}

void doReachable()
{
	GopBoard::loadAltarFromFile("..\\GopSolverLib\\water.txt");
	const int N = 2;
	typedef std::tuple<Point, Point, int> Data;
	std::vector<Data> data;
	for (int8_t y = -N; y <= N; ++y)
	{
		for (int8_t x = -N; x <= N; ++x)
		{
			if (GopBoard::get(x, y) != Tile::Floor)
				continue;
			for (int8_t y2 = -N; y2 <= N; ++y2)
			{
				for (int8_t x2 = -N; x2 <= N; ++x2)
				{
					if (GopBoard::get(x2, y2) != Tile::Floor)
						continue;
					// Count spawns reachable from spot
					int total = 0;
					std::for_each(std::begin(waterSpawns), std::end(waterSpawns), [&](Point p) {
						if (GopBoard::canReach(Point(x, y), p) || GopBoard::canReach(Point(x2, y2), p))
							++total;
					});
					data.push_back(std::make_tuple(Point(x, y), Point(x2, y2), total));
				}
			}
		}
	}
	sort(begin(data), end(data), [](Data t1, Data t2) { return std::get<2>(t1) > std::get<2>(t2); });
	for (auto& x : data)
	{
		auto p1 = std::get<0>(x);
		auto p2 = std::get<1>(x);
		std::cout << "(" << p1.x << "," << p1.y << ")" << ", " << "(" << p2.x << "," << p2.y << ")" << ": " << std::get<2>(x) << std::endl;
		if (std::get<2>(x) < 120)
			break;
	}
}

void benchmarkSolver(std::string altarFile, GameState state, bool debug = false)
{
	GopBoard::loadAltarFromFile(altarFile);
	int numExpanded;
	auto t = currentTime();
	auto solutions = Solver::solve(state, &numExpanded, debug);
	auto diff = currentTime() - t;
	double diffMs = (double)diff.count() / 1000000;
	if (solutions.size() == 0)
	{
		std::cerr << "No solutions! This is an error." << std::endl;;
		return;
	}

	std::cout << "Best solution uses " << solutions[0]->getPath().size() + 1 << " ticks"
		<< "\nExpanded " << numExpanded << " states in " << diffMs << " ms ("
		<< diffMs / numExpanded << " ms per state expanded)" << std::endl;
}

void testHeuristic(std::string altarFile, GameState state, std::string actionsStr)
{
	GopBoard::loadAltarFromFile(altarFile);
	auto actions = GameAction::parseActions(actionsStr);
	std::cout << GameAction::formatActions(actions) << std::endl;
	for (size_t i = 0; i < actions.size(); i++)
	{
		GameAction action = actions[i];
		state.player.action = action;
		state.step();
		std::cout << std::setw(10) << action.toString()
			<< " | Heuristic cost: " << 1 + i + state.getHeuristicCost()
			<< std::endl;
	}
}

void doSolverBenchmarks(bool heuristicsOnly = false)
{
	if (!heuristicsOnly)
	{
		benchmarkSolver("..\\GopSolverLib\\air.txt", { { { 0,-2 } },{ { { 4,6 } } } });
		benchmarkSolver("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { 4,9 } } } });
		benchmarkSolver("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { -13,0 } } } });
		benchmarkSolver("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { 7,-16 } } } });
		benchmarkSolver("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { -16,0 } } } });
		benchmarkSolver("..\\GopSolverLib\\air.txt", { { { 0,-2 } },{ { { -7,5 } },{ { 7,5 } } } });
		benchmarkSolver("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { -11,0 } },{ { 11,0 } } } });
		benchmarkSolver("..\\GopSolverLib\\earth.txt", { { { -2, 0 } },{ { { -15,-8 } } } });
	}

	testHeuristic("..\\GopSolverLib\\earth.txt", { { { -2, 0 } },{ { { -15,-8 } } } }, "(-17,-10)[9]{q}*AA(-19,-11)*AA(-15,-12)*AA[9]-[4]");
	testHeuristic("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { -13,0 } } } }, "(-3,-8)[3]*AA(-1,-5)[2]*AA[4](0,-4)*AAAA--");
	testHeuristic("..\\GopSolverLib\\earth.txt", { { { -3,-1 } },{ { { -13,5 } } } }, "*A(-4,-1)-*A-*A-*AA*A{q}A--");
	testHeuristic("..\\GopSolverLib\\mind.txt", { { { 0, -2 } },{ { { 8, -16 } } } }, "(0,-8)[3]*AAA--*AA(0,-10){r}*A{r}{q}AA[6]--");
	testHeuristic("..\\GopSolverLib\\mind.txt", { { { 0, -2 } },{ { { -1,-13 } },{ { -1,11 } } } }, "(-6,-3)[3]*AA(-6,-2)*BBB(-2,1)[2]*AAA*BB*AA*BB*AA*B-");
	testHeuristic("..\\GopSolverLib\\mind.txt", { {{0,-2}},{{{4,-11}}} }, "(0,-10)[4]{r}*AA{r}(2,-12){q}*AA[9]--");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { -4, 2 } },{ { 4, 2 } } } }, "*A-*B--");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { -5, 3 } },{ { 4, 2 } } } }, "*AA*B--");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { -5, 3 } },{ { 5, 3 } } } }, "*AA*BB--");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { -7, 5 } },{ { 7, 5 } } } }, "*AA*BB*A-*B--");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { -7, 5 } },{ { 4, 2 } } } }, "*AA*BB*A--");
	testHeuristic("..\\GopSolverLib\\water.txt", { { { 1, -2 } },{ { { 11, -2 } },{ { 11, -2 } } } }, "*AA*BB*AA*BB*AA*BB--");
	testHeuristic("..\\GopSolverLib\\water.txt", { { { 1, -2 } },{ { { 11, -2 } },{ { 10, -2 } } } }, "*AA*BB*AA*BB*AA*B--");
	testHeuristic("..\\GopSolverLib\\water.txt", { { { 1, -2 } },{ { { 11, -2 } },{ { 9, -2 } } } }, "*AA*BB*AA*BB*AA*B-");
	testHeuristic("..\\GopSolverLib\\earth.txt", { { { 2, -2 } },{ { { -3, -13 } },{ { -2, -12 } } } }, "(2,-3)*AA(0,-5)*BB(1,-5)[2]*AA*BBBB*A(0,-7){q}(0,-7)*AA*BBB*A-");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 2, 0 } },{ { { -4, 4 } }, {{-3, -5}} } }, "*A-*BB*A-");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { { 6,-1 } } } } }, "(2,-3)*AA(0,-2)A---");
	testHeuristic("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { -12,-10 } },{ { 8,4 } } } }, "*BB(1,-3)[2]*B(-3,-2)[2]*AAA*B*AAAA(-7,-4){q}*AAAA--");
}

void doReachable2(std::string altarFile, const std::vector<Point>& spawns, std::function<bool(Point)> filter)
{
	GopBoard::loadAltarFromFile(altarFile);
	std::vector<Point> filteredSpawns;
	for (Point spawn : spawns)
	{
		if (filter(spawn))
			filteredSpawns.push_back(spawn);
	}

	using MySet = std::set<std::pair<double, Point>, std::less<>>;
	MySet costs;
	for (int8_t x = -10; x <= 10; x++)
	{
		for (int8_t y = -10; y <= 10; y++)
		{
			if (GopBoard::get(x, y) != Tile::Floor)
				continue;
			Point p = { x, y };
			int distSum = 0;
			bool cancel = false;
			for (Point spawn : filteredSpawns)
			{
				int d = GopBoard::distanceToReachable(p, spawn, false, true);
				if (d == std::numeric_limits<int>::max())
				{
					cancel = true;
					break;	// Can't ever reach a spawn, that's bad.
				}
				if (d > 0)
					distSum += (d + 3) / 2;
				if (p.walkingDistanceTo(spawn) > 15)	// Can't see the orb at all
					distSum += 4;
			}
			if (!cancel)
			{
				double averageDist = (double)distSum / filteredSpawns.size();
				costs.insert(std::make_pair(averageDist, p));
			}
		}
	}

	int num = 0;
	for (auto entry : costs)
	{
		if (++num > 20)
			break;
		std::cout << entry.first << ", " << entry.second.toString() << std::endl;
	}
}

int sum(GopArray<int> grid)
{
	return std::accumulate(&grid.data[0][0], &grid.data[GRID_SIZE - 1][GRID_SIZE - 1], 0);
}

template<class T>
void writeParSpreadsheetOutput(GopArray<T> grid)
{
	GopArray<std::string> stringGrid;
	for (int8_t y = -GRID_MAX; y <= GRID_MAX; y++)
	{
		for (int8_t x = -GRID_MAX; x <= GRID_MAX; x++)
		{
			T value = grid.get(x, y);
			stringGrid.set(x, y, value == 0 ? "" : std::to_string(value));
		}
	}
	std::ofstream fout("out.txt");
	fout << stringGrid.toString("\t") << endl;
}

template<>
void writeParSpreadsheetOutput(GopArray<std::string> grid)
{
	std::ofstream fout("out.txt");
	fout << grid.toString("\t") << endl;
}

GopArray<std::string> getGopMinGridWhichPlayer(int altar, std::vector<Point> playerLocations)
{
	std::vector<GopArray<int>> grids;
	for (Point loc : playerLocations)
		grids.push_back(getPars(altar, loc));

	GopArray<std::string> whichPlayerGrid;
	for (int8_t y = -GRID_MAX; y <= GRID_MAX; y++)
	{
		for (int8_t x = -GRID_MAX; x <= GRID_MAX; x++)
		{
			Point p{ x,y };
			int min;
			if (playerLocations.size() == 2)
				min = std::min({ grids[0][p], grids[1][p] });
			else if (playerLocations.size() == 3)
				min = std::min({ grids[0][p], grids[1][p], grids[2][p] });
			else if (playerLocations.size() == 4)
				min = std::min({ grids[0][p], grids[1][p], grids[2][p], grids[3][p] });
			if (min == 0)
				continue;
			for (int i = 0; i < grids.size(); i++)
				if (grids[i][p] == min)
					whichPlayerGrid[p] += std::to_string(i + 1);
		}
	}
	return whichPlayerGrid;
}

GopArray<int> getGopMinGrid(int altar, std::vector<Point> playerLocations)
{
	std::vector<GopArray<int>> grids;
	for (Point loc : playerLocations)
		grids.push_back(getPars(altar, loc));

	GopArray<int> grid;
	for (int8_t y = -GRID_MAX; y <= GRID_MAX; y++)
	{
		for (int8_t x = -GRID_MAX; x <= GRID_MAX; x++)
		{
			Point p{ x,y };
			//if (playerLocations.size() == 2)
			grid[p] = std::min({ grids[0][p], grids[1][p] });
			//else
			//	grid[p] = std::min({ grids[0][p], grids[1][p], grids[2][p] });
		}
	}
	return grid;
}

int getGopMinGridSum(int altar, std::vector<Point> playerLocations)
{
	std::vector<GopArray<int>> grids;
	for (Point loc : playerLocations)
		grids.push_back(getPars(altar, loc));

	int total = 0;
	for (int8_t y = -GRID_MAX; y <= GRID_MAX; y++)
	{
		for (int8_t x = -GRID_MAX; x <= GRID_MAX; x++)
		{
			Point p{ x,y };
			if (playerLocations.size() == 2)
				total += std::min({ grids[0][p], grids[1][p] });
			else if (playerLocations.size() == 3) {
				total += std::max({ grids[0][p], grids[1][p], grids[2][p] });
			}
			else if (playerLocations.size() == 4)
				total += std::min({ grids[0][p], grids[1][p], grids[2][p], grids[3][p] });
		}
	}
	return total;
}

int seedBadness(int altar, int seed, int numSpawns, GopArray<int> pars)
{
	//std::vector<Point> goodPracticeSpawns{ { -14, 12 },{ -14, 11 },{ -15, 11 },{ -14, 9 },{ -13, 8 },{ -15, 5 },{ -14, 7 },{ -12, 12 },{ -9, 9 },{ -10, 10 },{ -11, 11 },{ -10, 11 },{ -14, 10 },{ -15, 10 } };

	const auto& spawns = altarSpawns[altar];
	std::mt19937 eng;
	std::uniform_int_distribution<int> dist(0, (int)spawns.size() - 1);

	eng.seed(seed);
	int total = 0;
	for (int i = 0; i < numSpawns; ++i)
	{
		Point spawn = spawns[dist(eng)];
		total += pars[spawn];
		//if (std::find(std::begin(goodPracticeSpawns), std::end(goodPracticeSpawns), spawn) != goodPracticeSpawns.end())
		//	total += 10000;
	}
	return total;
}

void findGoodSpawns(int altar, int numSpawns, int maxSeed = 10000, Point startPosition1 = { 0, -2 },
	Point startPosition2 = Point::invalid)
{
	GopBoard::loadAltarFromFile(altarFiles[altar]);
	std::set<std::pair<int, int>, std::less<>> badness;

	GopArray<int> pars;
	if (startPosition2 != Point::invalid)
		pars = getGopMinGrid(altar, { startPosition1, startPosition2 });
	else
		pars = getPars(altar, startPosition1);
	auto startTime = currentTime();
	for (int i = 0; i <= maxSeed; ++i)
	{
		badness.emplace(seedBadness(altar, i, numSpawns, pars), i);
		if (badness.size() >= 100)
		{
			auto iter = badness.end();
			badness.erase(--iter);
		}

		if (i % 1000000 == 999999)
		{
			auto time = currentTime();
			auto diff = time - startTime;
			auto seedsPerSecond = (1000000000.0 * (i + 1)) / diff.count();
			std::cout << seedsPerSecond << " seeds per second; current min = "
				<< badness.begin()->first << ", seed " << badness.begin()->second << std::endl;
		}
	}
	for (auto& x : badness)
		std::cout << x.first << ", " << x.second << std::endl;
}

void doBestTrioPositions(int altar, int8_t limits = 8)
{
	std::vector<Point> points;
	std::set<std::tuple<int, Point, Point, Point>, std::less<>> values;

	GopBoard::loadAltarFromFile(altarFiles[altar]);
	for (int8_t x = -limits; x <= limits; x++)
		for (int8_t y = -limits; y <= limits; y++)
			if (GopBoard::isPassable({ x, y }, PathMode::Player))
				points.push_back({ x,y });

	for (Point p1 : points)
		for (Point p2 : points)
			for (Point p3 : points)
			{
				if (!(p1 < p2 && p2 < p3))
					continue;
				values.emplace(getGopMinGridSum(altar, { p1, p2, p3 }), p1, p2, p3);
			}

	int top = 100;
	for (auto entry : values)
	{
		if (--top <= 0)
			break;
		cout << std::get<0>(entry) << ", " << std::get<1>(entry).toString()
			<< ", " << std::get<2>(entry).toString()
			<< ", " << std::get<3>(entry).toString() << endl;
	}
}

void doBestDuoPositions(int altar, int8_t limits = 8)
{
	std::vector<Point> points;
	std::set<std::tuple<int, Point, Point>, std::less<>> values;

	GopBoard::loadAltarFromFile(altarFiles[altar]);
	for (int8_t x = -limits; x <= limits; x++)
	{
		for (int8_t y = -limits; y <= limits; y++)
		{
			if (GopBoard::isPassable({ x, y }, PathMode::Player))
			{
				points.push_back({ x,y });
			}
		}
	}

	for (Point p1 : points)
	{
		for (Point p2 : points)
		{
			if (!(p1 < p2))
				continue;
			values.emplace(getGopMinGridSum(altar, { p1, p2 }), p1, p2);
		}
	}

	int top = 100;
	for (auto entry : values)
	{
		if (--top <= 0)
			break;
		cout << std::get<0>(entry) << ", " << std::get<1>(entry).toString()
			<< ", " << std::get<2>(entry).toString() << endl;
	}
}

void doBestDuoPositionsGivenOne(int altar, Point location1, int8_t limits = 8)
{
	std::vector<Point> points;
	std::set<std::tuple<int, Point, Point>, std::less<>> values;

	GopBoard::loadAltarFromFile(altarFiles[altar]);
	for (int8_t x = -limits; x <= limits; x++)
		for (int8_t y = -limits; y <= limits; y++)
			if (GopBoard::isPassable({ x, y }, PathMode::Player))
				points.push_back({ x,y });

	for (Point p2 : points)
	{
		values.emplace(getGopMinGridSum(altar, { location1, p2 }), location1, p2);
	}

	int top = 100;
	for (auto entry : values)
	{
		if (--top <= 0)
			break;
		cout << std::get<0>(entry) << ", " << std::get<1>(entry).toString()
			<< ", " << std::get<2>(entry).toString() << endl;
	}
}

void doBestSoloPositions(int altar, int8_t limits = 8)
{
	std::vector<Point> points;
	std::set<std::pair<int, Point>, std::less<>> values;

	GopBoard::loadAltarFromFile(altarFiles[altar]);
	for (int8_t x = -limits; x <= limits; x++)
	{
		for (int8_t y = -limits; y <= limits; y++)
		{
			if (GopBoard::isPassable({ x, y }, PathMode::Player))
			{
				points.push_back({ x,y });
			}
		}
	}

	for (Point p1 : points)
	{
		values.emplace(sum(getPars(altar, { p1 })), p1);
	}

	cout << "Best solo positions for " << altarNames[altar] << endl;
	int top = 100;
	for (auto entry : values)
	{
		if (--top <= 0)
			break;
		cout << std::get<0>(entry) << ", " << std::get<1>(entry).toString() << endl;
	}
}

void doBestQuadPositions(int altar, int8_t limits = 3)
{
	std::vector<Point> points;
	std::set<std::tuple<int, Point, Point, Point, Point>, std::less<>> values;

	GopBoard::loadAltarFromFile(altarFiles[altar]);
	for (int8_t x = -limits; x <= limits; x++)
		for (int8_t y = -limits; y <= limits; y++)
			if (GopBoard::isPassable({ x, y }, PathMode::Player))
				points.push_back({ x,y });

	for (Point p1 : points)
		for (Point p2 : points)
			for (Point p3 : points)
				for (Point p4 : points)
				{
					if (!(p1 < p2 && p2 < p3 && p3 < p4))
						continue;
					values.emplace(getGopMinGridSum(altar, { p1, p2, p3, p4 }), p1, p2, p3, p4);
				}

	int top = 100;
	for (auto entry : values)
	{
		if (--top <= 0)
			break;
		cout << std::get<0>(entry) << ", " << std::get<1>(entry).toString()
			<< ", " << std::get<2>(entry).toString()
			<< ", " << std::get<3>(entry).toString()
			<< ", " << std::get<4>(entry).toString() << endl;
	}
}

void doBadnessBalance(int altar, std::vector<Point> locations)
{
	auto whichPlayer = getGopMinGridWhichPlayer(altar, locations);
	auto grid = getGopMinGrid(altar, locations);
	double sum1 = 0, sum2 = 0, sum3 = 0;
	for (int8_t y = -GRID_MAX; y <= GRID_MAX; y++)
	{
		for (int8_t x = -GRID_MAX; x <= GRID_MAX; x++)
		{
			Point p{ x,y };
			if (whichPlayer[p] == "1")
				sum1 += grid[p];
			else if (whichPlayer[p] == "2")
				sum2 += grid[p];
			else if (whichPlayer[p] == "3")
				sum3 += grid[p];
			else if (whichPlayer[p] == "12")
			{
				sum2 += grid[p];
			}
			else if (whichPlayer[p] == "13")
			{
				sum3 += grid[p];
			}
			else if (whichPlayer[p] == "23")
			{
				sum3 += grid[p];
			}
			else if (whichPlayer[p] == "123")
			{
				sum3 += grid[p];
			}
		}
	}
	cout << "Sum 1: " << sum1 << endl << "Sum 2: " << sum2 << endl
		<< "Sum 3: " << sum3 << endl;
}

std::vector<Point> bestTrioPositions[]
{
	{ Point{ -2,0 }, Point{ 1,-2 }, Point{ 1,2 } },
	{ Point{ -5,1 }, Point{ 2,-4 }, Point{ 2,1 } },
	{ Point{ -2,1 }, Point{ 1,-2 }, Point{ 4,3 } },
	{ Point{ -3,5 }, Point{ -5,-7 }, Point{ 6, -4 } },
	{ Point{ -2,0 }, Point{ 1,-2 }, Point{ 1,2 } },
	{ Point{ -2,0 }, Point{ 1,-2 }, Point{ 1,2 } },
};

std::vector<Point> bestDuoPositions[]
{
	{ Point{ 1,-2 }, Point{ 0,2 } },
	{ Point{ -5,1 }, Point{ 2,-4 } },
	{ Point{ 1,-2 }, Point{ 1,2 } },
	{ Point{ -5,1 }, Point{ 4,-2 } },
	{ Point{ 1,-2 }, Point{ 1,2 } },
	{ Point{ -2,0 }, Point{ 1, 2 } },
};

std::vector<Point> bestQuadPositions[]
{
	{ Point{ -1,-2 }, Point{1,-2}, Point{2,1}, Point{-1,2} },
	{ Point{ -5,1 }, Point{ 2,-4 }, Point{ 2,1 } },
	{ Point{ -2,1 }, Point{ 1,-2 }, Point{ 4,3 } },
	{ Point{ -3,5 }, Point{ -5,-7 }, Point{ 6, -4 } },
	{ Point{ -2,0 }, Point{ 1,-2 }, Point{ 1,2 } },
	{ Point{ -2,0 }, Point{ 1,-2 }, Point{ 1,2 } },
};

void doParsJSON()
{
	GopBoard::loadAltarFromFile(altarFiles[0]);
	std::ostringstream ostr;
	ostr << "[{";
	for (int8_t y = -5; y <= 5; y++)
		for (int8_t x = -5; x <= 5; x++)
		{
			Point p{ x, y };
			if (GopBoard::isPassable(p, PathMode::Player))
			{
				auto parStr = getPars(0, p).toJSON();
				ostr << "\"" << p.toString() << "\":";
				ostr << parStr << ",";
			}
		}
	ostr << "}]";

	std::ofstream fout("pars.json");
	fout << ostr.str() << endl;
}

enum Altar { Air, Mind, Water, Earth, Fire, Body };

int main()
{
	using namespace std;

	constexpr int Altar = Altar::Mind;
	constexpr int Seed = 1;
	constexpr int NumSpawns = 22;

	const auto spawnBadness = getGopMinGrid(Altar, bestDuoPositions[Altar]);
	const auto spawns = altarSpawns[Altar];
	std::mt19937 eng;
	std::uniform_int_distribution<int> dist(0, (int)spawns.size() - 1);

	eng.seed(Seed);
	int total = 0;
	for (int i = 0; i < NumSpawns; ++i)
	{
		Point spawn = spawns[dist(eng)];
		int badness = spawnBadness[spawn];
		cout << setw(3) << (i+1) << setw(10) << spawn.toString() << setw(5) << badness << endl;
		total += badness;
	}
	cout << "Average badness: " << (double)total / NumSpawns << endl;
}
