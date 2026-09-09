#include "Patient.h"

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Patient> patients;
    int choice;

    cout << "   База пациентов медпункта\n";

    do {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1. Добавить пациента\n";
        cout << "2. Показать всех пациентов\n";
        cout << "3. Показать пациентов по дате\n";
        cout << "4. Показать направленных в др. учреждение\n";
        cout << "5. Показать количество записей\n";
        cout << "0. Выход\n";

        choice = inputInt("Ваш выбор: ", 0, 5);

        switch (choice) {
        case 1:
            addPatient(patients);
            break;

        case 2:
            printAll(patients);
            break;

        case 3: {
            if (patients.empty()) { cout << "Список пуст.\n"; break; }
            string date;
            while (true) {
                date = inputString("Введите дату (дд.мм.гггг): ");
                if (isValidDate(date)) break;
                cout << "Ошибка! Неверный формат даты.\n";
            }
            printByDate(patients, date);
            break;
        }

        case 4:
            printRedirected(patients);
            break;

        case 5:
            cout << "Всего записей в базе: " << patients.size() << endl;
            break;

        case 0:
            cout << "Программа завершена.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}