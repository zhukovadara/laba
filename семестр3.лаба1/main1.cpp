#include "Header1.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Учёт заболеваний сотрудников\n\n";

    int n = inputInt("Количество сотрудников (1-100): ", 1, 100);

    vector<Employee> employees;
    inputEmployees(employees, n);

    printEmployees(employees);
    printSameDisease(employees);

    return 0;
}