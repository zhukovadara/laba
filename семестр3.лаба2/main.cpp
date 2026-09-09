#include "Patient.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Программа учёта пациентов медпункта\n";

    int n = getNumber("\nВведите количество записей: ", 1, 100);

    vector<Patient> patients;

    for (int i = 0; i < n; i++) {
        cout << "\n Пациент " << i + 1 << "\n";
        patients.push_back(inputPatient());
    }

    int choice;
    do {
        cout << "\n МЕНЮ \n";
        cout << "1. Показать всех пациентов\n";
        cout << "2. Найти пациентов по дате обращения\n";
        cout << "3. Показать пациентов, направленных в другое учреждение\n";
        cout << "0. Выход\n";

        choice = getNumber("Ваш выбор: ", 0, 3);

        switch (choice) {
        case 1: {
            cout << "\n Все пациенты \n";
            for (const Patient& p : patients) {
                p.print();
            }
            break;
        }

        case 2: {
            cout << "Введите дату для поиска (например 12.05.2024): ";
            string date;
            getline(cin, date);
            printPatientsByDate(patients, date);
            break;
        }

        case 3: {
            printSentPatients(patients);
            break;
        }

        case 0: {
            cout << "\nВыход из программы.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}