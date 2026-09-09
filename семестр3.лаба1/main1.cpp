#include "Header1.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Программа учета заболеваний сотрудников\n";

    int N = safeInputInt("Введите количество сотрудников (1-100): ", 1, 100);

    vector<Employee> employees;
    
    inputEmployees(employees, N);

    printAllEmployees(employees);

    printEmployeesWithSameDisease(employees);

    cout << "\nПрограмма завершена.\n";

    return 0;
}