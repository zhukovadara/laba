#include "Header.h"

using namespace std;

void TriangleP(double a, double& P, double& S) {
    P = 3 * a;
    S = (a * a * sqrt(3)) / 4;
}

double getDouble(const string& prompt, double minVal, double maxVal) {
    double value;
    bool valid;

    do {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка! Введите число.\n";
            valid = false;
        }
        else if (value < minVal) {
            cout << "Ошибка! Сторона должна быть больше " << minVal;
            cout << ".\n";
            valid = false;
        }
        else {
            valid = true;
        }
    } while (!valid);

    cin.ignore(10000, '\n');
    return value;
}

void printResult(int number, double a, double P, double S) {
    cout << "\nТреугольник " << number << ":\n";
    cout << "  Сторона: " << a << endl;
    cout << "  Периметр: " << P << endl;
    cout << "  Площадь: " << S << endl;
}