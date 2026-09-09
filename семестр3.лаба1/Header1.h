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
    string fio;
    int year;
    string disease;
    int days;
};

bool check(const string& str);

bool checkS(const string& str);

int checkInt(const string& prompt, int minValue, int maxValue);

string checkString(const string& prompt, bool allowEmpty = false, bool checkLetters = false);

void inputEmployees(vector<Employee>& employees, int N);

void printEmployeesDisease(const vector<Employee>& employees);

void printEmployees(const vector<Employee>& employees);

void clear();

#endif