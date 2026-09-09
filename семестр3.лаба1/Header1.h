#ifndef HEADER1_H
#define HEADER1_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cctype>
#include <limits>

using namespace std;

struct Employee {
    string fullName;
    int birthYear;
    string disease;
    int sicknessDuration;
};

bool check(const string& str);

bool checkS(const string& str);

int safeInputInt(const string& prompt, int minValue, int maxValue);

string safeInputString(const string& prompt, bool allowEmpty = false, bool checkLetters = false);

void inputEmployees(vector<Employee>& employees, int N);

void printEmployeesWithSameDisease(const vector<Employee>& employees);

void printAllEmployees(const vector<Employee>& employees);

void clearInputBuffer();

#endif