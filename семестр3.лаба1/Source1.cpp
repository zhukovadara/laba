#include "Header1.h"

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool check(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool checkS(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isalpha(c) && c != ' ' && c != '-' && c != '.') {
            return false;
        }
    }
    return true;
}

int safeInputInt(const string& prompt, int minValue, int maxValue) {
    string input;
    int value;
    bool valid = false;

    while (!valid) {
        cout << prompt;
        getline(cin, input);

        if (input.empty()) {
            cout << "Ошибка: Ввод не может быть пустым.\n";
            continue;
        }

        bool onlySpaces = true;
        for (char c : input) {
            if (c != ' ') {
                onlySpaces = false;
                break;
            }
        }
        if (onlySpaces) {
            cout << "Ошибка: Ввод не может состоять только из пробелов.\n";
            continue;
        }

        if (!check(input)) {
            cout << "Ошибка: Введите целое число.\n";
            continue;
        }

        value = stoi(input);

        if (value < minValue || value > maxValue) {
            cout << "Ошибка: Значение должно быть в диапазоне от " << minValue << " до " << maxValue << ".\n";
            continue;
        }

        valid = true;
    }

    return value;
}

string safeInputString(const string& prompt, bool allowEmpty, bool checkLetters) {
    string input;
    bool valid = false;

    while (!valid) {
        cout << prompt;
        getline(cin, input);

        if (!allowEmpty && input.empty()) {
            cout << "Ошибка: Поле не может быть пустым.\n";
            continue;
        }

        if (!allowEmpty) {
            bool onlySpaces = true;
            for (char c : input) {
                if (c != ' ') {
                    onlySpaces = false;
                    break;
                }
            }
            if (onlySpaces) {
                cout << "Ошибка: Поле не может состоять только из пробелов.\n";
                continue;
            }
        }

        if (checkLetters && !checkS(input)) {
            cout << "Ошибка: Поле должно содержать только буквы, пробелы, дефисы и точки.\n";
            continue;
        }

        valid = true;
    }

    return input;
}

void inputEmployees(vector<Employee>& employees, int N) {
    for (int i = 0; i < N; i++) {
        Employee emp;
        cout << "\nСотрудник " << i + 1 << "\n";

        emp.fullName = safeInputString("Введите ФИО: ", false, true);

        emp.birthYear = safeInputInt("Введите год рождения (1900-2026): ", 1900, 2026);

        emp.disease = safeInputString("Введите заболевание: ", false, true);

        emp.sicknessDuration = safeInputInt("Введите продолжительность болезни (в днях, 1-365): ", 1, 365);

        employees.push_back(emp);
    }
}

void printEmployeesWithSameDisease(const vector<Employee>& employees) {
    map<string, vector<Employee>> diseaseGroups;

    for (const auto& emp : employees) {
        diseaseGroups[emp.disease].push_back(emp);
    }

    cout << "\nСписок сотрудников с одинаковыми заболеваниями:\n";

    bool found = false;
    for (const auto& group : diseaseGroups) {
        if (group.second.size() > 1) {
            found = true;
            cout << "\nЗаболевание: " << group.first << "\n";
            for (const auto& emp : group.second) {
                cout << "ФИО: " << emp.fullName << "\n";
                cout << "Год рождения: " << emp.birthYear << "\n";
                cout << "Продолжительность: " << emp.sicknessDuration << " дней\n";
                cout << "\n";
            }
        }
    }

    if (!found) {
        cout << "\nНет сотрудников с одинаковыми заболеваниями.\n";
    }
}

void printAllEmployees(const vector<Employee>& employees) {
    cout << "\nСписок всех сотрудников:\n";
    for (size_t i = 0; i < employees.size(); i++) {
        cout << "\nСотрудник " << i + 1 << ":\n";
        cout << "ФИО: " << employees[i].fullName << "\n";
        cout << "Год рождения: " << employees[i].birthYear << "\n";
        cout << "Заболевание: " << employees[i].disease << "\n";
        cout << "Продолжительность: " << employees[i].sicknessDuration << " дней\n";
    }
}