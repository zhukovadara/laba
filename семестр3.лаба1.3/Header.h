#ifndef FUNCTIONS_H
#define HEADER_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

using namespace std;

void generateArr(vector<int>& arr, int size);

void printArr(const vector<int>& arr);

int findMax(const vector<int>& arr, int left, int right);

int getN(const string& prompt);

#endif