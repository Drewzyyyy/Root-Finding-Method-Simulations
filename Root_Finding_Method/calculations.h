#pragma once
#include <iostream>

double f(double x);
double* doBisection(int iterations, double leftEndPt, double rightEndPt);
double* doSecant(int iterations, double leftEndPt, double rightEndPt);
double* doFalsePos(int iterations, double leftEndPt, double rightEndPt);
void doRootFinding(double* (*method)(int iterations, double leftEndPt, double rightEndPt));