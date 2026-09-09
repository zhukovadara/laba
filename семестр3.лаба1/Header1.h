#ifndef HEADER1_H
#define HEADER1_H

#include <string>
#include <vector>

using namespace std;

struct Employee {
    string fio;
    int year;
    string disease;
    int days;
};

int inputInt(const string& prompt, int minVal, int maxVal);
string inputString(const string& prompt);
void inputEmployees(vector<Employee>& employees, int n);
void printEmployees(const vector<Employee>& employees);
void printSameDisease(const vector<Employee>& employees);

#endif