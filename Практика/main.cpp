#include "AdamsMethod.h"

double f(double x, double y) {
    return x + y;
}

double exactSolution(double x) {
    return 2.0 * exp(x) - x - 1.0;
}

double f2(double x, double y) {
    return y * y + 1.0;
}

double exactSolution2(double x) {
    return tan(x);
}

double f3(double x, double y) {
    return -2.0 * x * y;
}

double exactSolution3(double x) {
    return exp(-x * x);
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "========================================\n";
    cout << "   РЕШЕНИЕ ДУ МЕТОДОМ АДАМСА\n";
    cout << "========================================\n\n";

    cout << "Пример 1: dy/dx = x + y, y(0) = 1\n";
    cout << "Точное решение: y = 2*e^x - x - 1\n";
    cout << "----------------------------------------\n";

    AdamsSolver solver1(f, 0.0, 1.0, 0.01, 2.0);
    solver1.solve(4);

    auto xVals1 = solver1.getXValues();
    auto yVals1 = solver1.getYValues();

    vector<double> exact1;
    for (double x : xVals1) {
        exact1.push_back(exactSolution(x));
    }

    solver1.printResults();

    double error1 = AdamsSolver::calculateError(exact1, yVals1);
    cout << "Максимальная ошибка: " << scientific << error1 << "\n\n";

    solver1.printResultsToFile("results_example1.csv");

    cout << "\nПример 2: dy/dx = y^2 + 1, y(0) = 0\n";
    cout << "Точное решение: y = tan(x)\n";
    cout << "----------------------------------------\n";

    AdamsSolver solver2(f2, 0.0, 0.0, 0.01, 1.0);
    solver2.solve(4);

    auto xVals2 = solver2.getXValues();
    auto yVals2 = solver2.getYValues();

    vector<double> exact2;
    for (double x : xVals2) {
        exact2.push_back(exactSolution2(x));
    }

    solver2.printResults();

    double error2 = AdamsSolver::calculateError(exact2, yVals2);
    cout << "Максимальная ошибка: " << scientific << error2 << "\n\n";

    solver2.printResultsToFile("results_example2.csv");

    cout << "\nПример 3: dy/dx = -2xy, y(0) = 1\n";
    cout << "Точное решение: y = e^(-x^2)\n";
    cout << "----------------------------------------\n";

    AdamsSolver solver3(f3, 0.0, 1.0, 0.01, 2.0);
    solver3.solve(4);

    auto xVals3 = solver3.getXValues();
    auto yVals3 = solver3.getYValues();

    vector<double> exact3;
    for (double x : xVals3) {
        exact3.push_back(exactSolution3(x));
    }

    solver3.printResults();

    double error3 = AdamsSolver::calculateError(exact3, yVals3);
    cout << "Максимальная ошибка: " << scientific << error3 << "\n\n";

    solver3.printResultsToFile("results_example3.csv");

    cout << "\n========================================\n";
    cout << "   СРАВНЕНИЕ МЕТОДОВ РАЗНЫХ ПОРЯДКОВ\n";
    cout << "========================================\n";
    cout << "Уравнение: dy/dx = x + y, y(0) = 1\n";
    cout << "Точное решение в x = 1: " << exactSolution(1.0) << "\n\n";

    vector<int> orders = { 2, 3, 4 };
    for (int order : orders) {
        AdamsSolver solver(f, 0.0, 1.0, 0.1, 1.0);
        solver.solve(order);
        auto yVals = solver.getYValues();
        double yAt1 = yVals.back();
        double error = abs(yAt1 - exactSolution(1.0));
        cout << "Метод " << order << "-го порядка: y(1) = "
            << fixed << setprecision(8) << yAt1
            << ", ошибка = " << scientific << error << "\n";
    }

    cout << "\n========================================\n";
    cout << "   АНАЛИЗ СХОДИМОСТИ МЕТОДА\n";
    cout << "========================================\n";
    cout << "Уравнение: dy/dx = x + y, y(0) = 1\n";
    cout << "Точное решение в x = 1: " << exactSolution(1.0) << "\n";
    cout << "Шаг    |  y(1)     |  Ошибка\n";
    cout << "----------------------------------------\n";

    vector<double> steps = { 0.1, 0.05, 0.025, 0.0125 };
    for (double step : steps) {
        AdamsSolver solver(f, 0.0, 1.0, step, 1.0);
        solver.solve(4);
        auto yVals = solver.getYValues();
        double yAt1 = yVals.back();
        double error = abs(yAt1 - exactSolution(1.0));
        cout << fixed << setprecision(4) << step << "  | "
            << setprecision(8) << yAt1 << " | "
            << scientific << error << "\n";
    }

    cout << "\nПрограмма завершена.\n";
    return 0;
}