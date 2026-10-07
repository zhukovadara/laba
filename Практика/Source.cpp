#include "AdamsMethod.h"

AdamsSolver::AdamsSolver(function<double(double, double)> func,
    double x0, double y0, double h, double xEnd)
    : x0(x0), y0(y0), h(h), xEnd(xEnd), f(func) {
    xValues.clear();
    yValues.clear();
    fValues.clear();
}

void AdamsSolver::initializeFirstPoints() {
    int numStartPoints = 4;

    xValues.clear();
    yValues.clear();
    fValues.clear();

    xValues.push_back(x0);
    yValues.push_back(y0);
    fValues.push_back(f(x0, y0));

    double x = x0;
    double y = y0;

    for (int i = 1; i < numStartPoints; ++i) {
        double k1 = f(x, y);
        double k2 = f(x + h / 2, y + h * k1 / 2);
        double k3 = f(x + h / 2, y + h * k2 / 2);
        double k4 = f(x + h, y + h * k3);

        y = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
        x = x + h;

        xValues.push_back(x);
        yValues.push_back(y);
        fValues.push_back(f(x, y));
    }
}

double AdamsSolver::predictor(int i) {
    return yValues[i] + (h / 24.0) * (55.0 * fValues[i] -
        59.0 * fValues[i - 1] +
        37.0 * fValues[i - 2] -
        9.0 * fValues[i - 3]);
}

double AdamsSolver::corrector(int i) {
    return yValues[i] + (h / 24.0) * (9.0 * f(xValues[i] + h, predictor(i)) +
        19.0 * fValues[i] -
        5.0 * fValues[i - 1] +
        fValues[i - 2]);
}

double AdamsSolver::adamsBashforth2(int i) {
    return yValues[i] + (h / 2.0) * (3.0 * fValues[i] - fValues[i - 1]);
}

double AdamsSolver::adamsBashforth3(int i) {
    return yValues[i] + (h / 12.0) * (23.0 * fValues[i] -
        16.0 * fValues[i - 1] +
        5.0 * fValues[i - 2]);
}

double AdamsSolver::adamsBashforth4(int i) {
    return yValues[i] + (h / 24.0) * (55.0 * fValues[i] -
        59.0 * fValues[i - 1] +
        37.0 * fValues[i - 2] -
        9.0 * fValues[i - 3]);
}

double AdamsSolver::adamsMoulton2(int i) {
    double yn1_pred = yValues[i] + h * fValues[i];
    return yValues[i] + (h / 2.0) * (f(xValues[i] + h, yn1_pred) + fValues[i]);
}

double AdamsSolver::adamsMoulton3(int i) {
    double yn1_pred = adamsBashforth2(i);
    return yValues[i] + (h / 12.0) * (5.0 * f(xValues[i] + h, yn1_pred) +
        8.0 * fValues[i] -
        fValues[i - 1]);
}

double AdamsSolver::adamsMoulton4(int i) {
    double yn1_pred = adamsBashforth3(i);
    return yValues[i] + (h / 24.0) * (9.0 * f(xValues[i] + h, yn1_pred) +
        19.0 * fValues[i] -
        5.0 * fValues[i - 1] +
        fValues[i - 2]);
}

void AdamsSolver::solve(int order) {
    initializeFirstPoints();

    if (xValues.back() >= xEnd) {
        return;
    }

    double x = xValues.back();
    double y = yValues.back();

    while (x < xEnd) {
        int i = xValues.size() - 1;
        double xn1, yn1;

        switch (order) {
        case 2:
            if (i >= 1) {
                yn1 = adamsBashforth2(i);
            }
            else {
                double k1 = f(x, y);
                double k2 = f(x + h / 2, y + h * k1 / 2);
                double k3 = f(x + h / 2, y + h * k2 / 2);
                double k4 = f(x + h, y + h * k3);
                yn1 = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
            }
            break;

        case 3:
            if (i >= 2) {
                yn1 = adamsMoulton3(i);
            }
            else {
                double k1 = f(x, y);
                double k2 = f(x + h / 2, y + h * k1 / 2);
                double k3 = f(x + h / 2, y + h * k2 / 2);
                double k4 = f(x + h, y + h * k3);
                yn1 = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
            }
            break;

        case 4:
        default:
            if (i >= 3) {
                double y_pred = predictor(i);
                double f_pred = f(x + h, y_pred);

                for (int iter = 0; iter < 3; ++iter) {
                    y_pred = yValues[i] + (h / 24.0) * (9.0 * f_pred +
                        19.0 * fValues[i] -
                        5.0 * fValues[i - 1] +
                        fValues[i - 2]);
                    f_pred = f(x + h, y_pred);
                }
                yn1 = y_pred;
            }
            else {
                double k1 = f(x, y);
                double k2 = f(x + h / 2, y + h * k1 / 2);
                double k3 = f(x + h / 2, y + h * k2 / 2);
                double k4 = f(x + h, y + h * k3);
                yn1 = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
            }
            break;
        }

        xn1 = x + h;

        xValues.push_back(xn1);
        yValues.push_back(yn1);
        fValues.push_back(f(xn1, yn1));

        x = xn1;
        y = yn1;
    }
}

void AdamsSolver::printResults() const {
    cout << fixed << setprecision(8);
    cout << "Результаты решения методом Адамса:\n";
    cout << "====================================\n";
    cout << "   x        |     y        \n";
    cout << "------------------------------------\n";

    for (size_t i = 0; i < xValues.size(); ++i) {
        cout << setw(10) << xValues[i] << " | "
            << setw(12) << yValues[i] << "\n";
    }
    cout << "====================================\n";
}

void AdamsSolver::printResultsToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << filename << "\n";
        return;
    }

    file << fixed << setprecision(10);
    file << "x,y\n";
    for (size_t i = 0; i < xValues.size(); ++i) {
        file << xValues[i] << "," << yValues[i] << "\n";
    }

    file.close();
    cout << "Результаты сохранены в файл " << filename << "\n";
}

double AdamsSolver::calculateError(const vector<double>& exact,
    const vector<double>& computed) {
    if (exact.size() != computed.size()) {
        cerr << "Ошибка: векторы имеют разный размер\n";
        return -1.0;
    }

    double maxError = 0.0;
    for (size_t i = 0; i < exact.size(); ++i) {
        double error = abs(exact[i] - computed[i]);
        if (error > maxError) {
            maxError = error;
        }
    }
    return maxError;
}