#include "Header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Вычисление периметра и площади равностороннего треугольника\n";

    cout << "Формулы:\n";
    cout << "  P = 3 * a\n";
    cout << "  S = a^2 * sqrt(3) / 4\n";

    double sides[3];

    for (int i = 0; i < 3; i++) {
        cout << "Треугольник " << i + 1 << endl;
        sides[i] = getDouble("  Введите сторону a: ", 0.001, 1e9);
        cout << endl;
    }

    cout << "Результаты вычислений:\n";

    for (int i = 0; i < 3; i++) {
        double P, S;

        TriangleP(sides[i], P, S);

        cout << fixed << setprecision(2);
        printResult(i + 1, sides[i], P, S);
    }

    cout << "Программа завершена.\n";

    return 0;
}