#include "Header1.h"
#include <iostream>
#include <map>
#include <cctype>

using namespace std;

int inputInt(const string& prompt, int minVal, int maxVal) {
    string s;
    int value;

    while (true) {
        cout << prompt;
        getline(cin, s);

        if (s.empty()) {
            cout << "Ошибка: пустой ввод.\n";
            continue;
        }

        bool ok = true;
        for (char c : s) {
            if (!isdigit((unsigned char)c)) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "Ошибка: введите число.\n";
            continue;
        }

        value = stoi(s);

        if (value < minVal || value > maxVal) {
            cout << "Ошибка: значение от " << minVal << " до " << maxVal << ".\n";
            continue;
        }

        return value;
    }
}

string inputString(const string& prompt) {
    string s;

    while (true) {
        cout << prompt;
        getline(cin, s);

        if (s.empty()) {
            cout << "Ошибка: пустой ввод.\n";
            continue;
        }

        bool onlySpaces = true;
        for (char c : s) {
            if (c != ' ') {
                onlySpaces = false;
                break;
            }
        }
        if (onlySpaces) {
            cout << "Ошибка: строка из пробелов.\n";
            continue;
        }

        return s;
    }
}

void inputEmployees(vector<Employee>& employees, int n) {
    for (int i = 0; i < n; i++) {
        Employee emp;
        cout << "\nСотрудник " << i + 1 << "\n";

        emp.fio = inputString("ФИО: ");
        emp.year = inputInt("Год рождения (1900-2026): ", 1900, 2026);
        emp.disease = inputString("Заболевание: ");
        emp.days = inputInt("Дней болезни (1-365): ", 1, 365);

        employees.push_back(emp);
    }
}

void printEmployees(const vector<Employee>& employees) {
    cout << "\n Все сотрудники \n";
    for (size_t i = 0; i < employees.size(); i++) {
        cout << "\nСотрудник " << i + 1 << "\n";
        cout << "  ФИО: " << employees[i].fio << "\n";
        cout << "  Год: " << employees[i].year << "\n";
        cout << "  Заболевание: " << employees[i].disease << "\n";
        cout << "  Дней: " << employees[i].days << "\n";
    }
}

void printSameDisease(const vector<Employee>& employees) {
    map<string, vector<int>> groups;
    for (int i = 0; i < (int)employees.size(); i++) {
        groups[employees[i].disease].push_back(i);
    }

    cout << "\n Одинаковые заболевания \n";

    bool found = false;
    for (auto& g : groups) {
        if (g.second.size() > 1) {
            found = true;
            cout << "\nЗаболевание: " << g.first << "\n";
            for (int idx : g.second) {
                cout << "  " << employees[idx].fio
                    << ", " << employees[idx].year
                    << ", " << employees[idx].days << " дней\n";
            }
        }
    }

    if (!found) {
        cout << "Нет совпадений.\n";
    }
}