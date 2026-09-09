#include "Header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Поиск максимума методом деления пополам\n";
    cout << "Формула: max(max(a1,...,an), max(an/2,...,an))\n";

    int n = getN("Введите размер массива: ");

    vector<int> arr;
    generateArray(arr, n);

    cout << "\nМассив: ";
    printArray(arr);

    int maxVal = findMax(arr, 0, n - 1);

    int normalMax = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > normalMax) normalMax = arr[i];
    }

    cout << "\nРезультаты:\n";
    cout << "Максимум (метод деления): " << maxVal << endl;
    cout << "Максимум (обычный метод): " << normalMax << endl;

    cout << "\nПрограмма завершена.\n";
    return 0;
}