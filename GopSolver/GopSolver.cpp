// GopSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma region Spawns

const Point airSpawns[] = { Point(-5, -9), Point(-4, -9), Point(-3, -9), Point(-2, -9), Point(-1, -9), Point(0, -9), Point(-6, -8), Point(-5, -8), Point(-4, -8), Point(-3, -8), Point(-2, -8), Point(-1, -8), Point(0, -8), Point(1, -8), Point(2, -8), Point(3, -8), Point(-6, -7), Point(-5, -7), Point(-4, -7), Point(-3, -7), Point(-2, -7), Point(-1, -7), Point(0, -7), Point(1, -7), Point(2, -7), Point(3, -7), Point(4, -7), Point(5, -7), Point(6, -7), Point(-6, -6), Point(-5, -6), Point(-4, -6), Point(-2, -6), Point(-1, -6), Point(0, -6), Point(1, -6), Point(2, -6), Point(3, -6), Point(4, -6), Point(5, -6), Point(6, -6), Point(7, -6), Point(-6, -5), Point(-5, -5), Point(-4, -5), Point(-3, -5), Point(-2, -5), Point(-1, -5), Point(0, -5), Point(1, -5), Point(2, -5), Point(3, -5), Point(4, -5), Point(5, -5), Point(6, -5), Point(7, -5), Point(-7, -4), Point(-6, -4), Point(-5, -4), Point(-4, -4), Point(-3, -4), Point(-2, -4), Point(2, -4), Point(3, -4), Point(4, -4), Point(5, -4), Point(6, -4), Point(7, -4), Point(-8, -3), Point(-7, -3), Point(-6, -3), Point(-5, -3), Point(-4, -3), Point(4, -3), Point(5, -3), Point(6, -3), Point(7, -3), Point(-8, -2), Point(-7, -2), Point(-6, -2), Point(-5, -2), Point(-4, -2), Point(4, -2), Point(5, -2), Point(6, -2), Point(7, -2), Point(-8, -1), Point(-7, -1), Point(-6, -1), Point(-5, -1), Point(5, -1), Point(6, -1), Point(7, -1), Point(-8, 0), Point(-7, 0), Point(-6, 0), Point(-5, 0), Point(5, 0), Point(6, 0), Point(7, 0), Point(-8, 1), Point(-7, 1), Point(-6, 1), Point(-5, 1), Point(5, 1), Point(6, 1), Point(7, 1), Point(-8, 2), Point(-7, 2), Point(-6, 2), Point(-5, 2), Point(-4, 2), Point(4, 2), Point(5, 2), Point(6, 2), Point(7, 2), Point(-8, 3), Point(-7, 3), Point(-6, 3), Point(-5, 3), Point(-4, 3), Point(4, 3), Point(5, 3), Point(6, 3), Point(7, 3), Point(-7, 4), Point(-6, 4), Point(-5, 4), Point(-4, 4), Point(-3, 4), Point(-2, 4), Point(2, 4), Point(3, 4), Point(4, 4), Point(5, 4), Point(6, 4), Point(7, 4), Point(-7, 5), Point(-6, 5), Point(-5, 5), Point(-4, 5), Point(-3, 5), Point(-2, 5), Point(-1, 5), Point(0, 5), Point(1, 5), Point(2, 5), Point(3, 5), Point(4, 5), Point(5, 5), Point(6, 5), Point(7, 5), Point(-6, 6), Point(-5, 6), Point(-4, 6), Point(-3, 6), Point(-2, 6), Point(-1, 6), Point(0, 6), Point(1, 6), Point(2, 6), Point(3, 6), Point(4, 6), Point(5, 6), Point(6, 6), Point(7, 6), Point(-6, 7), Point(-5, 7), Point(-4, 7), Point(-3, 7), Point(-2, 7), Point(-1, 7), Point(0, 7), Point(1, 7), Point(2, 7), Point(3, 7), Point(4, 7), Point(5, 7), Point(6, 7), Point(-5, 8), Point(-4, 8), Point(-3, 8), Point(-2, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(3, 8), Point(4, 8), Point(5, 8) };
const Point mindSpawns[] = { Point(-4, -16), Point(-3, -16), Point(-2, -16), Point(-1, -16), Point(0, -16), Point(1, -16), Point(2, -16), Point(3, -16), Point(4, -16), Point(5, -16), Point(6, -16), Point(7, -16), Point(8, -16), Point(9, -16), Point(10, -16), Point(11, -16), Point(13, -16), Point(-3, -15), Point(-2, -15), Point(-1, -15), Point(0, -15), Point(1, -15), Point(2, -15), Point(3, -15), Point(4, -15), Point(5, -15), Point(6, -15), Point(7, -15), Point(8, -15), Point(9, -15), Point(10, -15), Point(12, -15), Point(13, -15), Point(-4, -14), Point(-3, -14), Point(-2, -14), Point(-1, -14), Point(0, -14), Point(1, -14), Point(2, -14), Point(3, -14), Point(4, -14), Point(5, -14), Point(6, -14), Point(8, -14), Point(9, -14), Point(10, -14), Point(11, -14), Point(12, -14), Point(13, -14), Point(-4, -13), Point(-3, -13), Point(-2, -13), Point(-1, -13), Point(0, -13), Point(1, -13), Point(2, -13), Point(3, -13), Point(4, -13), Point(5, -13), Point(6, -13), Point(7, -13), Point(8, -13), Point(9, -13), Point(10, -13), Point(11, -13), Point(12, -13), Point(13, -13), Point(-6, -12), Point(-5, -12), Point(-4, -12), Point(-3, -12), Point(-2, -12), Point(-1, -12), Point(0, -12), Point(1, -12), Point(2, -12), Point(3, -12), Point(4, -12), Point(5, -12), Point(6, -12), Point(7, -12), Point(8, -12), Point(9, -12), Point(10, -12), Point(11, -12), Point(12, -12), Point(-6, -11), Point(-5, -11), Point(-4, -11), Point(-3, -11), Point(-2, -11), Point(-1, -11), Point(0, -11), Point(1, -11), Point(2, -11), Point(3, -11), Point(4, -11), Point(5, -11), Point(6, -11), Point(7, -11), Point(8, -11), Point(9, -11), Point(10, -11), Point(11, -11), Point(12, -11), Point(13, -11), Point(-13, -10), Point(-12, -10), Point(-10, -10), Point(-9, -10), Point(-7, -10), Point(-6, -10), Point(-5, -10), Point(-4, -10), Point(-3, -10), Point(-2, -10), Point(0, -10), Point(2, -10), Point(3, -10), Point(4, -10), Point(5, -10), Point(6, -10), Point(7, -10), Point(8, -10), Point(9, -10), Point(10, -10), Point(11, -10), Point(12, -10), Point(13, -10), Point(14, -10), Point(-14, -9), Point(-13, -9), Point(-12, -9), Point(-11, -9), Point(-10, -9), Point(-9, -9), Point(-8, -9), Point(-7, -9), Point(-6, -9), Point(-5, -9), Point(-4, -9), Point(-3, -9), Point(-2, -9), Point(-1, -9), Point(0, -9), Point(1, -9), Point(2, -9), Point(3, -9), Point(4, -9), Point(5, -9), Point(6, -9), Point(7, -9), Point(8, -9), Point(9, -9), Point(10, -9), Point(11, -9), Point(12, -9), Point(13, -9), Point(14, -9), Point(15, -9), Point(-15, -8), Point(-14, -8), Point(-13, -8), Point(-12, -8), Point(-11, -8), Point(-10, -8), Point(-9, -8), Point(-8, -8), Point(-7, -8), Point(-6, -8), Point(-5, -8), Point(-4, -8), Point(-3, -8), Point(-2, -8), Point(-1, -8), Point(0, -8), Point(1, -8), Point(2, -8), Point(3, -8), Point(4, -8), Point(5, -8), Point(6, -8), Point(7, -8), Point(8, -8), Point(9, -8), Point(10, -8), Point(11, -8), Point(12, -8), Point(13, -8), Point(14, -8), Point(15, -8), Point(-16, -7), Point(-15, -7), Point(-14, -7), Point(-13, -7), Point(-12, -7), Point(-11, -7), Point(-10, -7), Point(-9, -7), Point(-8, -7), Point(-7, -7), Point(6, -7), Point(7, -7), Point(8, -7), Point(9, -7), Point(10, -7), Point(11, -7), Point(12, -7), Point(13, -7), Point(14, -7), Point(15, -7), Point(-16, -6), Point(-15, -6), Point(-14, -6), Point(-13, -6), Point(-12, -6), Point(-11, -6), Point(-10, -6), Point(-9, -6), Point(-8, -6), Point(7, -6), Point(8, -6), Point(9, -6), Point(10, -6), Point(11, -6), Point(12, -6), Point(13, -6), Point(14, -6), Point(15, -6), Point(-16, -5), Point(-15, -5), Point(-14, -5), Point(-13, -5), Point(-12, -5), Point(-11, -5), Point(-10, -5), Point(-9, -5), Point(8, -5), Point(9, -5), Point(10, -5), Point(11, -5), Point(12, -5), Point(13, -5), Point(14, -5), Point(15, -5), Point(-16, -4), Point(-15, -4), Point(-14, -4), Point(-13, -4), Point(-12, -4), Point(-11, -4), Point(-10, -4), Point(8, -4), Point(9, -4), Point(10, -4), Point(11, -4), Point(13, -4), Point(14, -4), Point(-16, -3), Point(-15, -3), Point(-14, -3), Point(-13, -3), Point(-12, -3), Point(-11, -3), Point(-10, -3), Point(8, -3), Point(9, -3), Point(10, -3), Point(11, -3), Point(12, -3), Point(13, -3), Point(14, -3), Point(15, -3), Point(-16, -2), Point(-15, -2), Point(-14, -2), Point(-13, -2), Point(-12, -2), Point(-11, -2), Point(-10, -2), Point(8, -2), Point(9, -2), Point(10, -2), Point(11, -2), Point(12, -2), Point(13, -2), Point(14, -2), Point(15, -2), Point(-16, -1), Point(-15, -1), Point(-14, -1), Point(-13, -1), Point(-12, -1), Point(-11, -1), Point(8, -1), Point(9, -1), Point(11, -1), Point(12, -1), Point(13, -1), Point(14, -1), Point(15, -1), Point(-16, 0), Point(-15, 0), Point(-14, 0), Point(-13, 0), Point(-12, 0), Point(-11, 0), Point(-10, 0), Point(8, 0), Point(9, 0), Point(10, 0), Point(11, 0), Point(12, 0), Point(13, 0), Point(14, 0), Point(15, 0), Point(-16, 1), Point(-15, 1), Point(-14, 1), Point(-13, 1), Point(-12, 1), Point(-11, 1), Point(8, 1), Point(9, 1), Point(11, 1), Point(12, 1), Point(13, 1), Point(14, 1), Point(15, 1), Point(-16, 2), Point(-15, 2), Point(-14, 2), Point(-13, 2), Point(-12, 2), Point(-11, 2), Point(-10, 2), Point(8, 2), Point(9, 2), Point(10, 2), Point(11, 2), Point(12, 2), Point(13, 2), Point(14, 2), Point(-16, 3), Point(-15, 3), Point(-14, 3), Point(-13, 3), Point(-12, 3), Point(-11, 3), Point(-10, 3), Point(8, 3), Point(9, 3), Point(10, 3), Point(11, 3), Point(12, 3), Point(13, 3), Point(-16, 4), Point(-15, 4), Point(-14, 4), Point(-13, 4), Point(-12, 4), Point(-11, 4), Point(-10, 4), Point(8, 4), Point(9, 4), Point(10, 4), Point(11, 4), Point(12, 4), Point(13, 4), Point(14, 4), Point(-16, 5), Point(-15, 5), Point(-14, 5), Point(-13, 5), Point(-12, 5), Point(-11, 5), Point(-10, 5), Point(-9, 5), Point(8, 5), Point(9, 5), Point(10, 5), Point(11, 5), Point(12, 5), Point(13, 5), Point(14, 5), Point(-16, 6), Point(-15, 6), Point(-14, 6), Point(-13, 6), Point(-12, 6), Point(-11, 6), Point(-10, 6), Point(-9, 6), Point(-8, 6), Point(7, 6), Point(8, 6), Point(9, 6), Point(10, 6), Point(11, 6), Point(-16, 7), Point(-15, 7), Point(-14, 7), Point(-13, 7), Point(-12, 7), Point(-11, 7), Point(-10, 7), Point(-9, 7), Point(-8, 7), Point(-7, 7), Point(6, 7), Point(7, 7), Point(8, 7), Point(9, 7), Point(10, 7), Point(-16, 8), Point(-15, 8), Point(-14, 8), Point(-13, 8), Point(-12, 8), Point(-11, 8), Point(-10, 8), Point(-9, 8), Point(-8, 8), Point(-7, 8), Point(-6, 8), Point(-5, 8), Point(-4, 8), Point(-3, 8), Point(-2, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(3, 8), Point(4, 8), Point(5, 8), Point(6, 8), Point(7, 8), Point(8, 8), Point(9, 8), Point(-16, 9), Point(-15, 9), Point(-14, 9), Point(-13, 9), Point(-11, 9), Point(-10, 9), Point(-9, 9), Point(-8, 9), Point(-7, 9), Point(-6, 9), Point(-5, 9), Point(-4, 9), Point(-3, 9), Point(-2, 9), Point(-1, 9), Point(0, 9), Point(1, 9), Point(2, 9), Point(3, 9), Point(4, 9), Point(5, 9), Point(6, 9), Point(-16, 10), Point(-15, 10), Point(-14, 10), Point(-13, 10), Point(-12, 10), Point(-11, 10), Point(-10, 10), Point(-9, 10), Point(-8, 10), Point(-7, 10), Point(-6, 10), Point(-5, 10), Point(-4, 10), Point(-3, 10), Point(-2, 10), Point(0, 10), Point(2, 10), Point(3, 10), Point(4, 10), Point(5, 10), Point(-15, 11), Point(-14, 11), Point(-13, 11), Point(-12, 11), Point(-11, 11), Point(-10, 11), Point(-9, 11), Point(-8, 11), Point(-7, 11), Point(-6, 11), Point(-5, 11), Point(-4, 11), Point(-3, 11), Point(-2, 11), Point(-1, 11), Point(0, 11), Point(1, 11), Point(2, 11), Point(3, 11), Point(4, 11), Point(-15, 12), Point(-14, 12), Point(-12, 12), Point(-10, 12), Point(-8, 12), Point(-7, 12), Point(-6, 12), Point(-5, 12), Point(-4, 12), Point(-3, 12), Point(-2, 12), Point(-1, 12), Point(1, 12), Point(2, 12), Point(3, 12), Point(-7, 13), Point(-3, 13) };
const Point waterSpawns[] = { Point(1, -15), Point(2, -15), Point(3, -15), Point(4, -15), Point(1, -14), Point(2, -14), Point(3, -14), Point(4, -14), Point(2, -13), Point(3, -13), Point(4, -13), Point(5, -13), Point(3, -12), Point(4, -12), Point(5, -12), Point(6, -12), Point(3, -11), Point(4, -11), Point(5, -11), Point(6, -11), Point(7, -11), Point(8, -11), Point(9, -11), Point(4, -10), Point(5, -10), Point(6, -10), Point(7, -10), Point(8, -10), Point(9, -10), Point(10, -10), Point(-1, -9), Point(0, -9), Point(4, -9), Point(5, -9), Point(6, -9), Point(7, -9), Point(8, -9), Point(9, -9), Point(10, -9), Point(-6, -8), Point(-5, -8), Point(-2, -8), Point(-1, -8), Point(0, -8), Point(1, -8), Point(2, -8), Point(3, -8), Point(4, -8), Point(5, -8), Point(6, -8), Point(7, -8), Point(8, -8), Point(9, -8), Point(10, -8), Point(11, -8), Point(-6, -7), Point(-5, -7), Point(-4, -7), Point(-2, -7), Point(-1, -7), Point(0, -7), Point(1, -7), Point(2, -7), Point(3, -7), Point(4, -7), Point(5, -7), Point(6, -7), Point(7, -7), Point(8, -7), Point(9, -7), Point(10, -7), Point(11, -7), Point(12, -7), Point(-7, -6), Point(-6, -6), Point(-5, -6), Point(-4, -6), Point(-3, -6), Point(-2, -6), Point(-1, -6), Point(0, -6), Point(1, -6), Point(2, -6), Point(3, -6), Point(4, -6), Point(5, -6), Point(6, -6), Point(7, -6), Point(8, -6), Point(9, -6), Point(10, -6), Point(11, -6), Point(12, -6), Point(13, -6), Point(-7, -5), Point(-6, -5), Point(-5, -5), Point(-4, -5), Point(-3, -5), Point(-2, -5), Point(-1, -5), Point(0, -5), Point(1, -5), Point(2, -5), Point(3, -5), Point(4, -5), Point(5, -5), Point(6, -5), Point(7, -5), Point(8, -5), Point(9, -5), Point(10, -5), Point(11, -5), Point(12, -5), Point(13, -5), Point(14, -5), Point(-7, -4), Point(-6, -4), Point(-5, -4), Point(-4, -4), Point(-3, -4), Point(-2, -4), Point(0, -4), Point(2, -4), Point(3, -4), Point(4, -4), Point(5, -4), Point(6, -4), Point(7, -4), Point(8, -4), Point(9, -4), Point(10, -4), Point(12, -4), Point(13, -4), Point(14, -4), Point(-7, -3), Point(-6, -3), Point(-5, -3), Point(-4, -3), Point(4, -3), Point(5, -3), Point(6, -3), Point(7, -3), Point(8, -3), Point(9, -3), Point(10, -3), Point(11, -3), Point(12, -3), Point(13, -3), Point(14, -3), Point(15, -3), Point(-8, -2), Point(-7, -2), Point(-6, -2), Point(-5, -2), Point(-4, -2), Point(4, -2), Point(5, -2), Point(6, -2), Point(7, -2), Point(8, -2), Point(9, -2), Point(10, -2), Point(11, -2), Point(12, -2), Point(13, -2), Point(14, -2), Point(15, -2), Point(-9, -1), Point(-8, -1), Point(-7, -1), Point(-6, -1), Point(-5, -1), Point(5, -1), Point(6, -1), Point(7, -1), Point(8, -1), Point(9, -1), Point(11, -1), Point(12, -1), Point(13, -1), Point(14, -1), Point(15, -1), Point(16, -1), Point(-9, 0), Point(-8, 0), Point(-7, 0), Point(-6, 0), Point(-5, 0), Point(-4, 0), Point(4, 0), Point(5, 0), Point(6, 0), Point(7, 0), Point(8, 0), Point(9, 0), Point(13, 0), Point(14, 0), Point(15, 0), Point(-9, 1), Point(-8, 1), Point(-7, 1), Point(-6, 1), Point(-5, 1), Point(5, 1), Point(6, 1), Point(7, 1), Point(8, 1), Point(9, 1), Point(13, 1), Point(14, 1), Point(-9, 2), Point(-8, 2), Point(-7, 2), Point(-6, 2), Point(-5, 2), Point(-4, 2), Point(4, 2), Point(5, 2), Point(6, 2), Point(7, 2), Point(8, 2), Point(9, 2), Point(13, 2), Point(14, 2), Point(-9, 3), Point(-8, 3), Point(-7, 3), Point(-6, 3), Point(-5, 3), Point(-4, 3), Point(4, 3), Point(5, 3), Point(6, 3), Point(7, 3), Point(8, 3), Point(9, 3), Point(10, 3), Point(11, 3), Point(12, 3), Point(13, 3), Point(-9, 4), Point(-8, 4), Point(-7, 4), Point(-6, 4), Point(-5, 4), Point(-4, 4), Point(-3, 4), Point(-2, 4), Point(0, 4), Point(2, 4), Point(3, 4), Point(4, 4), Point(5, 4), Point(6, 4), Point(7, 4), Point(8, 4), Point(9, 4), Point(10, 4), Point(11, 4), Point(12, 4), Point(-11, 5), Point(-10, 5), Point(-9, 5), Point(-8, 5), Point(-7, 5), Point(-6, 5), Point(-5, 5), Point(-4, 5), Point(-3, 5), Point(-2, 5), Point(-1, 5), Point(0, 5), Point(1, 5), Point(2, 5), Point(3, 5), Point(4, 5), Point(5, 5), Point(6, 5), Point(7, 5), Point(8, 5), Point(9, 5), Point(10, 5), Point(11, 5), Point(12, 5), Point(-11, 6), Point(-10, 6), Point(-9, 6), Point(-8, 6), Point(-7, 6), Point(-6, 6), Point(-5, 6), Point(-4, 6), Point(-3, 6), Point(-2, 6), Point(-1, 6), Point(0, 6), Point(1, 6), Point(2, 6), Point(3, 6), Point(4, 6), Point(5, 6), Point(6, 6), Point(7, 6), Point(8, 6), Point(9, 6), Point(10, 6), Point(-10, 7), Point(-9, 7), Point(-8, 7), Point(-7, 7), Point(-2, 7), Point(-1, 7), Point(0, 7), Point(1, 7), Point(2, 7), Point(3, 7), Point(4, 7), Point(5, 7), Point(6, 7), Point(8, 7), Point(9, 7), Point(-9, 8), Point(-8, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(3, 8), Point(4, 8), Point(0, 9), Point(1, 9), Point(2, 9), Point(3, 9) };
const Point earthSpawns[] = { Point(-16, -16), Point(-15, -16), Point(-8, -16), Point(-7, -16), Point(2, -16), Point(3, -16), Point(4, -16), Point(5, -16), Point(6, -16), Point(7, -16), Point(8, -16), Point(10, -16), Point(11, -16), Point(12, -16), Point(13, -16), Point(14, -16), Point(-16, -15), Point(-15, -15), Point(-9, -15), Point(-8, -15), Point(-7, -15), Point(4, -15), Point(5, -15), Point(11, -15), Point(12, -15), Point(13, -15), Point(14, -15), Point(-16, -14), Point(-15, -14), Point(-8, -14), Point(-7, -14), Point(-3, -14), Point(4, -14), Point(5, -14), Point(12, -14), Point(13, -14), Point(14, -14), Point(15, -14), Point(-16, -13), Point(-15, -13), Point(-8, -13), Point(-7, -13), Point(-4, -13), Point(-3, -13), Point(-2, -13), Point(-1, -13), Point(4, -13), Point(5, -13), Point(10, -13), Point(11, -13), Point(12, -13), Point(14, -13), Point(15, -13), Point(-16, -12), Point(-15, -12), Point(-14, -12), Point(-13, -12), Point(-12, -12), Point(-9, -12), Point(-8, -12), Point(-7, -12), Point(-4, -12), Point(-2, -12), Point(-1, -12), Point(4, -12), Point(5, -12), Point(11, -12), Point(12, -12), Point(-16, -11), Point(-15, -11), Point(-14, -11), Point(-13, -11), Point(-12, -11), Point(-11, -11), Point(-10, -11), Point(-9, -11), Point(-8, -11), Point(-7, -11), Point(-6, -11), Point(-4, -11), Point(-3, -11), Point(-2, -11), Point(-1, -11), Point(0, -11), Point(1, -11), Point(2, -11), Point(3, -11), Point(4, -11), Point(5, -11), Point(8, -11), Point(11, -11), Point(12, -11), Point(-16, -10), Point(-15, -10), Point(-12, -10), Point(-11, -10), Point(-10, -10), Point(-9, -10), Point(-8, -10), Point(-7, -10), Point(-6, -10), Point(-5, -10), Point(-4, -10), Point(-3, -10), Point(-2, -10), Point(-1, -10), Point(0, -10), Point(1, -10), Point(2, -10), Point(3, -10), Point(4, -10), Point(5, -10), Point(6, -10), Point(7, -10), Point(8, -10), Point(11, -10), Point(12, -10), Point(-16, -9), Point(-15, -9), Point(-14, -9), Point(10, -9), Point(11, -9), Point(12, -9), Point(-15, -8), Point(-14, -8), Point(10, -8), Point(11, -8), Point(12, -8), Point(13, -8), Point(-14, -7), Point(10, -7), Point(-14, -6), Point(15, -6), Point(-14, -5), Point(-13, -5), Point(15, -5), Point(-14, -4), Point(-13, -4), Point(-12, -4), Point(-11, -4), Point(-10, -4), Point(-9, -4), Point(15, -4), Point(-14, -3), Point(-13, -3), Point(-12, -3), Point(-11, -3), Point(-10, -3), Point(-9, -3), Point(15, -3), Point(-14, -2), Point(-13, -2), Point(-12, -2), Point(-11, -2), Point(-10, -2), Point(-9, -2), Point(10, -2), Point(11, -2), Point(12, -2), Point(13, -2), Point(15, -2), Point(-16, -1), Point(-15, -1), Point(-14, -1), Point(-13, -1), Point(-12, -1), Point(10, -1), Point(11, -1), Point(12, -1), Point(-16, 0), Point(-15, 0), Point(-14, 0), Point(10, 0), Point(-16, 1), Point(10, 1), Point(-16, 2), Point(10, 2), Point(11, 2), Point(12, 2), Point(-16, 3), Point(-15, 3), Point(-12, 3), Point(-11, 3), Point(-10, 3), Point(-9, 3), Point(10, 3), Point(11, 3), Point(12, 3), Point(13, 3), Point(-16, 4), Point(-15, 4), Point(-12, 4), Point(-11, 4), Point(-10, 4), Point(-9, 4), Point(10, 4), Point(11, 4), Point(12, 4), Point(13, 4), Point(14, 4), Point(15, 4), Point(-16, 5), Point(-15, 5), Point(-14, 5), Point(-13, 5), Point(-12, 5), Point(10, 5), Point(11, 5), Point(12, 5), Point(15, 5), Point(-16, 6), Point(-15, 6), Point(-14, 6), Point(-13, 6), Point(-12, 6), Point(10, 6), Point(12, 6), Point(15, 6), Point(-14, 7), Point(-13, 7), Point(-12, 7), Point(-11, 7), Point(10, 7), Point(11, 7), Point(12, 7), Point(13, 7), Point(14, 7), Point(15, 7), Point(-14, 8), Point(-13, 8), Point(-12, 8), Point(-7, 8), Point(-6, 8), Point(-5, 8), Point(-4, 8), Point(-3, 8), Point(-2, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(11, 8), Point(12, 8), Point(13, 8), Point(14, 8), Point(15, 8), Point(-14, 9), Point(-13, 9), Point(-12, 9), Point(-7, 9), Point(-6, 9), Point(-5, 9), Point(-4, 9), Point(-3, 9), Point(-2, 9), Point(-1, 9), Point(0, 9), Point(1, 9), Point(2, 9), Point(3, 9), Point(5, 9), Point(6, 9), Point(7, 9), Point(8, 9), Point(-14, 10), Point(-13, 10), Point(-12, 10), Point(-11, 10), Point(-10, 10), Point(-9, 10), Point(-8, 10), Point(-7, 10), Point(-6, 10), Point(-5, 10), Point(-4, 10), Point(-3, 10), Point(-2, 10), Point(-1, 10), Point(1, 10), Point(2, 10), Point(3, 10), Point(4, 10), Point(5, 10), Point(6, 10), Point(7, 10), Point(-13, 11), Point(-12, 11), Point(-11, 11), Point(-10, 11), Point(-9, 11), Point(-8, 11), Point(-7, 11), Point(-4, 11), Point(-3, 11), Point(-2, 11), Point(2, 11), Point(3, 11), Point(4, 11), Point(5, 11), Point(6, 11), Point(7, 11), Point(-12, 12), Point(-11, 12), Point(-10, 12), Point(-9, 12), Point(-7, 12), Point(-4, 12), Point(-3, 12), Point(2, 12), Point(5, 12), Point(-11, 13), Point(-10, 13), Point(-3, 13), Point(-11, 14), Point(-10, 14), Point(-9, 14) };
const Point fireSpawns[] = { Point(-8, -6), Point(-7, -6), Point(-6, -6), Point(-5, -6), Point(-4, -6), Point(-1, -6), Point(2, -6), Point(3, -6), Point(4, -6), Point(-8, -5), Point(-7, -5), Point(-6, -5), Point(-4, -5), Point(-3, -5), Point(-2, -5), Point(-1, -5), Point(0, -5), Point(1, -5), Point(2, -5), Point(3, -5), Point(4, -5), Point(-8, -4), Point(-7, -4), Point(-6, -4), Point(-5, -4), Point(-4, -4), Point(-3, -4), Point(-2, -4), Point(0, -4), Point(2, -4), Point(3, -4), Point(4, -4), Point(5, -4), Point(-9, -3), Point(-8, -3), Point(-7, -3), Point(-6, -3), Point(-5, -3), Point(-4, -3), Point(4, -3), Point(5, -3), Point(6, -3), Point(7, -3), Point(-8, -2), Point(-7, -2), Point(-6, -2), Point(-5, -2), Point(-4, -2), Point(4, -2), Point(5, -2), Point(6, -2), Point(7, -2), Point(-8, -1), Point(-7, -1), Point(-6, -1), Point(-5, -1), Point(5, -1), Point(6, -1), Point(-8, 0), Point(-7, 0), Point(-6, 0), Point(-5, 0), Point(-4, 0), Point(4, 0), Point(5, 0), Point(6, 0), Point(-8, 1), Point(-7, 1), Point(-6, 1), Point(-5, 1), Point(5, 1), Point(6, 1), Point(7, 1), Point(-7, 2), Point(-6, 2), Point(-5, 2), Point(-4, 2), Point(4, 2), Point(5, 2), Point(7, 2), Point(-6, 3), Point(-5, 3), Point(-4, 3), Point(4, 3), Point(5, 3), Point(6, 3), Point(-6, 4), Point(-5, 4), Point(-4, 4), Point(-3, 4), Point(-2, 4), Point(0, 4), Point(2, 4), Point(3, 4), Point(4, 4), Point(5, 4), Point(6, 4), Point(7, 4), Point(-8, 5), Point(-7, 5), Point(-6, 5), Point(-4, 5), Point(-3, 5), Point(-2, 5), Point(-1, 5), Point(0, 5), Point(1, 5), Point(2, 5), Point(3, 5), Point(4, 5), Point(6, 5), Point(7, 5), Point(-8, 6), Point(-7, 6), Point(-6, 6), Point(-5, 6), Point(-4, 6), Point(-3, 6), Point(-2, 6), Point(-1, 6), Point(0, 6), Point(1, 6), Point(2, 6), Point(3, 6), Point(4, 6), Point(5, 6), Point(6, 6), Point(7, 6), Point(-8, 7), Point(-7, 7), Point(-6, 7), Point(-5, 7), Point(-4, 7), Point(-3, 7), Point(-2, 7), Point(-1, 7), Point(0, 7), Point(1, 7), Point(2, 7), Point(3, 7), Point(4, 7), Point(5, 7), Point(-8, 8), Point(-7, 8), Point(-6, 8), Point(-5, 8), Point(-4, 8), Point(-3, 8), Point(-2, 8), Point(-1, 8), Point(0, 8), Point(1, 8), Point(2, 8), Point(4, 8), Point(5, 8), Point(-8, 9), Point(-6, 9), Point(-5, 9), Point(-2, 9), Point(-1, 9), Point(0, 9), Point(1, 9), Point(4, 9), Point(5, 9), Point(6, 9), Point(-8, 10), Point(-7, 10), Point(-6, 10), Point(-5, 10), Point(0, 10), Point(2, 10), Point(3, 10), Point(5, 10), Point(-7, 11), Point(-6, 11), Point(-5, 11), Point(-4, 11), Point(-3, 11), Point(3, 11) };
const Point bodySpawns[] = { Point(3, -10), Point(-2, -9), Point(-1, -9), Point(2, -9), Point(3, -9), Point(-5, -8), Point(-4, -8), Point(-3, -8), Point(-2, -8), Point(-1, -8), Point(0, -8), Point(1, -8), Point(2, -8), Point(-4, -7), Point(-3, -7), Point(-1, -7), Point(0, -7), Point(1, -7), Point(2, -7), Point(3, -7), Point(5, -7), Point(-6, -6), Point(-5, -6), Point(-4, -6), Point(-3, -6), Point(-2, -6), Point(-1, -6), Point(0, -6), Point(1, -6), Point(2, -6), Point(3, -6), Point(4, -6), Point(5, -6), Point(6, -6), Point(-9, -5), Point(-8, -5), Point(-7, -5), Point(-6, -5), Point(-5, -5), Point(-4, -5), Point(-3, -5), Point(-2, -5), Point(-1, -5), Point(0, -5), Point(1, -5), Point(2, -5), Point(3, -5), Point(4, -5), Point(7, -5), Point(-8, -4), Point(-7, -4), Point(-6, -4), Point(-5, -4), Point(-4, -4), Point(-3, -4), Point(-2, -4), Point(0, -4), Point(2, -4), Point(3, -4), Point(4, -4), Point(5, -4), Point(6, -4), Point(7, -4), Point(-11, -3), Point(-10, -3), Point(-8, -3), Point(-7, -3), Point(-6, -3), Point(-5, -3), Point(-4, -3), Point(4, -3), Point(5, -3), Point(6, -3), Point(7, -3), Point(-10, -2), Point(-9, -2), Point(-8, -2), Point(-7, -2), Point(-6, -2), Point(-5, -2), Point(-4, -2), Point(4, -2), Point(5, -2), Point(6, -2), Point(7, -2), Point(-11, -1), Point(-10, -1), Point(-9, -1), Point(-8, -1), Point(-7, -1), Point(-6, -1), Point(-5, -1), Point(5, -1), Point(6, -1), Point(7, -1), Point(8, -1), Point(-10, 0), Point(-9, 0), Point(-8, 0), Point(-7, 0), Point(-6, 0), Point(-5, 0), Point(-4, 0), Point(4, 0), Point(5, 0), Point(6, 0), Point(7, 0), Point(8, 0), Point(9, 0), Point(-11, 1), Point(-10, 1), Point(-9, 1), Point(-8, 1), Point(-7, 1), Point(-6, 1), Point(-5, 1), Point(5, 1), Point(6, 1), Point(7, 1), Point(8, 1), Point(9, 1), Point(-12, 2), Point(-11, 2), Point(-10, 2), Point(-9, 2), Point(-8, 2), Point(-7, 2), Point(-6, 2), Point(-5, 2), Point(-4, 2), Point(4, 2), Point(5, 2), Point(6, 2), Point(7, 2), Point(8, 2), Point(9, 2), Point(-12, 3), Point(-11, 3), Point(-10, 3), Point(-9, 3), Point(-8, 3), Point(-7, 3), Point(-6, 3), Point(-5, 3), Point(-4, 3), Point(4, 3), Point(5, 3), Point(6, 3), Point(7, 3), Point(8, 3), Point(9, 3), Point(10, 3), Point(-14, 4), Point(-13, 4), Point(-12, 4), Point(-11, 4), Point(-9, 4), Point(-8, 4), Point(-7, 4), Point(-6, 4), Point(-5, 4), Point(-4, 4), Point(-3, 4), Point(-2, 4), Point(0, 4), Point(2, 4), Point(3, 4), Point(4, 4), Point(5, 4), Point(6, 4), Point(7, 4), Point(8, 4), Point(9, 4), Point(10, 4), Point(-16, 5), Point(-15, 5), Point(-14, 5), Point(-13, 5), Point(-11, 5), Point(-10, 5), Point(-9, 5), Point(-8, 5), Point(-7, 5), Point(-6, 5), Point(-5, 5), Point(-4, 5), Point(-3, 5), Point(-2, 5), Point(-1, 5), Point(0, 5), Point(1, 5), Point(2, 5), Point(3, 5), Point(4, 5), Point(5, 5), Point(6, 5), Point(7, 5), Point(8, 5), Point(9, 5), Point(-12, 6), Point(-11, 6), Point(-10, 6), Point(-9, 6), Point(-7, 6), Point(-6, 6), Point(-5, 6), Point(-4, 6), Point(-3, 6), Point(-2, 6), Point(0, 6), Point(1, 6), Point(2, 6), Point(3, 6), Point(4, 6), Point(5, 6), Point(6, 6), Point(7, 6), Point(8, 6), Point(-13, 7), Point(-12, 7), Point(-10, 7), Point(-9, 7), Point(-8, 7), Point(-6, 7), Point(-5, 7), Point(-4, 7), Point(-3, 7), Point(-2, 7), Point(-1, 7), Point(0, 7), Point(1, 7), Point(2, 7), Point(3, 7), Point(4, 7), Point(5, 7), Point(6, 7), Point(7, 7), Point(-5, 8), Point(-3, 8), Point(2, 8), Point(4, 8), Point(5, 8), Point(6, 8), Point(7, 8), Point(7, 9), Point(8, 9) };

#pragma endregion

template<class F0>
double timeFunc(F0 f, int repetitions = 1)
{
	auto t = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < repetitions; ++i)
		f();
	auto x = std::chrono::high_resolution_clock::now() - t;
	return (double)std::chrono::duration_cast<std::chrono::nanoseconds>(x).count() / repetitions / 1000000000;
}

std::chrono::time_point<std::chrono::high_resolution_clock> currentTime()
{
	return std::chrono::high_resolution_clock::now();
}

#define SPAWNS airSpawns

std::mt19937 eng;
std::uniform_int_distribution<int> dist(0, _countof(SPAWNS) - 1);

int spawnBadness(int seed, int numSpawns = 50)
{
	eng.seed(seed);
	int total = 0;
	for (int i = 0; i < numSpawns; ++i)
	{
		Point spawn = SPAWNS[dist(eng)];
		int distance = GopBoard::distanceToAltar(spawn);
		if (spawn == Point(-3, -7))
			total += 3;
		else if (spawn == Point(-3, -8))
			total += 3;
		else if (spawn == Point(-3, -9))
			total += 3;
		else if (spawn == Point(-4, -8))
			total += 3;
		else if (spawn == Point(-4, -9))
			total += 3;
		else if ((abs(spawn.x) == 1 && abs(spawn.y) == 5) || (abs(spawn.x) == 5 && abs(spawn.y) == 1))
			total += 2;
		else if (distance >= 5)
			total += 1;
	}
	return total;
}

void findGoodSpawns()
{
	GopBoard::loadAltarFromFile("..\\GopSolverLib\\air.txt");
	std::set<std::pair<int, int>, std::less<>> badness;
	for (int i = 0; i < 100; ++i)
	{
		badness.emplace(spawnBadness(i, 55), i);
		if (badness.size() >= 100)
		{
			auto iter = badness.end();
			badness.erase(--iter);
		}
	}
	for (auto& x : badness)
		std::cout << x.first << ", " << x.second << std::endl;
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

int _tmain()
{
	findGoodSpawns();
	
	return 0;
	benchmarkSolver("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { 4,9 } } } });
	benchmarkSolver("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { -13,0 } } } });
	benchmarkSolver("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { 7,-16 } } } });
	benchmarkSolver("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { -16,0 } } } });
	benchmarkSolver("..\\GopSolverLib\\air.txt", { { { 0,-2 } },{ { { -7,5 } },{ { 7,5 } } } });
	benchmarkSolver("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { -11,0 } },{ { 11,0 } } } });

	testHeuristic("..\\GopSolverLib\\mind.txt", { { { 0,-2 } },{ { { -13,0 } } } }, "(-3,-8)[3]*AA(-1,-5)[2]*AA[4](0,-4)*AAAA--");
	testHeuristic("..\\GopSolverLib\\earth.txt", { { { -3,-1 } },{ { { -13,5 } } } }, "*A(-4,-1)-*A-*A-*AA*A{q}A--");
	testHeuristic("..\\GopSolverLib\\mind.txt", { { { 0, -2 } },{ { { 8, -16 } } } }, "(0,-8)[3]*AAA--*AA(0,-10){r}*A{r}{q}AA[6]--");
	testHeuristic("..\\GopSolverLib\\mind.txt", { { { 0, -2 } },{ { { -1,-13 } },{ { -1,11 } } } }, "(-6,-3)[3]*AA(-6,-2)*BBB(-2,1)[2]*AAA*BB*AA*BB*AA*B-");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { -4, 2 } },{ { 4, 2 } } } },                                                                                                       "*A-*B--");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { -5, 3 } },{ { 4, 2 } } } }, "*AA*B--");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { -5, 3 } },{ { 5, 3 } } } }, "*AA*BB--");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { -7, 5 } },{ { 7, 5 } } } }, "*AA*BB*A-*B--");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 0, -2 } },{ { { -7, 5 } },{ { 4, 2 } } } }, "*AA*BB*A--");
	testHeuristic("..\\GopSolverLib\\water.txt", { { { 1, -2 } },{ { { 11, -2 } },{ { 11, -2 } } } }, "*AA*BB*AA*BB*AA*BB--");
	testHeuristic("..\\GopSolverLib\\water.txt", { { { 1, -2 } },{ { { 11, -2 } },{ { 10, -2 } } } }, "*AA*BB*AA*BB*AA*B--");
	testHeuristic("..\\GopSolverLib\\water.txt", { { { 1, -2 } },{ { { 11, -2 } },{ { 9, -2 } } } }, "*AA*BB*AA*BB*AA*B-");
	testHeuristic("..\\GopSolverLib\\earth.txt", { { { 2, -2 } },{ { { -3, -13 } },{ { -2, -12 } } } }, "(2,-3)*AA(0,-5)*BB(1,-5)[2]*AA*BBBB*A(0,-7){q}(0,-7)*AA*BBB*A-");
	testHeuristic("..\\GopSolverLib\\air.txt", { { { 2, 0 } },{ { { -4, 4 } }, {{-3, -5}} } }, "*A-*BB*A-");

	t1.join();

	//set<pair<int, int>, less<>> badness;
	//for (int i = 0; i < 41; ++i)
	//{
	//	badness.emplace(spawnBadness(i, 50), i);
	//	if (badness.size() >= 100)
	//	{
	//		auto iter = badness.end();
	//		badness.erase(--iter);
	//	}
	//}
	//for (auto& x : badness)
	//	cout << x.first << ", " << x.second << endl;
}
