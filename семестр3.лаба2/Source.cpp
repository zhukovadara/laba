#include "Patient.h"

using namespace std;

Patient::Patient() {
    date = "";
    fio = "";
    group = "";
    reason = "";
    wasSentToHospital = false;
    note = "";
}

Patient::Patient(const string& date, const string& fio, const string& group,
    const string& reason, bool wasSentToHospital, const string& note) {
    this->date = date;
    this->fio = fio;
    this->group = group;
    this->reason = reason;
    this->wasSentToHospital = wasSentToHospital;
    this->note = note;
}

string Patient::getDate() const { return date; }
string Patient::getFullName() const { return fio; }
string Patient::getGroup() const { return group; }
string Patient::getReason() const { return reason; }
bool Patient::wasSent() const { return wasSentToHospital; }
string Patient::getNote() const { return note; }

void Patient::setDate(const string& date) { this->date = date; }
void Patient::setFullName(const string& fullName) { this->fio = fio; }
void Patient::setGroup(const string& group) { this->group = group; }
void Patient::setReason(const string& reason) { this->reason = reason; }
void Patient::setWasSentToHospital(bool value) { wasSentToHospital = value; }
void Patient::setNote(const string& note) { this->note = note; }

void Patient::print() const {
    cout << "Дата:           " << date << "\n";
    cout << "ФИО:            " << fio << "\n";
    cout << "Группа:         " << group << "\n";
    cout << "Причина:        " << reason << "\n";
    cout << "Результат:      "
        << (wasSentToHospital ? "Направлен в другое учреждение"
            : "Оказана помощь на месте") << "\n";
    cout << "Примечание:     " << (note.empty() ? "-" : note) << "\n";
}

string getString(const string& prompt) {
    string value;
    bool valid;

    do {
        cout << prompt;
        getline(cin, value);

        if (value.empty()) {
            cout << "Ошибка: Поле не может быть пустым. Попробуйте снова.\n";
            valid = false;
            continue;
        }

        bool onlySpaces = true;
        for (char c : value) {
            if (c != ' ') {
                onlySpaces = false;
                break;
            }
        }

        if (onlySpaces) {
            cout << "Ошибка: Поле не может состоять только из пробелов. Попробуйте снова.\n";
            valid = false;
        }
        else {
            valid = true;
        }
    } while (!valid);

    return value;
}

int getNumber(const string& prompt, int minVal, int maxVal) {
    int num;
    bool ok;

    do {
        cout << prompt;
        cin >> num;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка! Введите целое число.\n";
            ok = false;
        }
        else if (num < minVal || num > maxVal) {
            cout << "Ошибка! Значение должно быть от " << minVal
                << " до " << maxVal << ".\n";
            ok = false;
        }
        else {
            ok = true;
        }
    } while (!ok);

    cin.ignore(10000, '\n');
    return num;
}

Patient inputPatient() {
    Patient p;

    cout << "\nВведите дату обращения (например 12.05.2024): ";
    p.setDate(getString(""));

    cout << "Введите ФИО пациента: ";
    p.setFullName(getString(""));

    cout << "Введите группу (кафедра, отдел): ";
    p.setGroup(getString(""));

    cout << "Введите причину обращения: ";
    p.setReason(getString(""));

    cout << "Пациент направлен в другое лечебное учреждение?\n";
    cout << "1 - Да, 0 - Нет (оказана помощь на месте): ";
    int choice = getNumber("", 0, 1);
    p.setWasSentToHospital(choice == 1);

    cout << "Введите примечание (можно пустое): ";
    string note;
    getline(cin, note);
    p.setNote(note);

    return p;
}

void printPatientsByDate(const vector<Patient>& patients, const string& date) {
    cout << "Пациенты, обратившиеся " << date << ":\n";

    bool found = false;
    for (const Patient& p : patients) {
        if (p.getDate() == date) {
            p.print();
            found = true;
        }
    }

    if (!found) {
        cout << "Пациентов с такой датой обращения не найдено.\n";
    }
}

void printSentPatients(const vector<Patient>& patients) {
    cout << "Пациенты, направленные в другое учреждение:\n";

    bool found = false;
    for (const Patient& p : patients) {
        if (p.wasSent()) {
            p.print();
            found = true;
        }
    }

    if (!found) {
        cout << "Нет пациентов, направленных в другое учреждение.\n";
    }
}