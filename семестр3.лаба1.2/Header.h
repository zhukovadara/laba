#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

void TriangleP(double a, double& P, double& S);

double getDouble(const string& prompt, double minVal, double maxVal);

void printResult(int number, double a, double P, double S);

#endif