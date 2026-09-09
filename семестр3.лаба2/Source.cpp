#include "Patient.h"

Patient::Patient()
    : date("01.01.2000"), fullName("Неизвестно"), group("Не указана"),
    reason("Не указана"), helped(true), note("") {
}

Patient::Patient(const string& date, const string& fullName,
    const string& group, const string& reason,
    bool helped, const string& note)
    : date(date), fullName(fullName), group(group),
    reason(reason), helped(helped), note(note) {
}

Patient::Patient(const Patient& other)
    : date(other.date), fullName(other.fullName), group(other.group),
    reason(other.reason), helped(other.helped), note(other.note) {
}

Patient::~Patient() {}

string Patient::getDate()     const { return date; }
string Patient::getFullName() const { return fullName; }
string Patient::getGroup()    const { return group; }
string Patient::getReason()   const { return reason; }
bool   Patient::isHelped()    const { return helped; }
string Patient::getNote()     const { return note; }

void Patient::setDate(const string& d) { date = d; }
void Patient::setFullName(const string& f) { fullName = f; }
void Patient::setGroup(const string& g) { group = g; }
void Patient::setReason(const string& r) { reason = r; }
void Patient::setHelped(bool h) { helped = h; }
void Patient::setNote(const string& n) { note = n; }

bool Patient::isRedirected() const {
    return !helped;
}

bool Patient::matchesDate(const string& d) const {
    return date == d;
}

string Patient::toString() const {
    return date + " | " + fullName + " | " + group + " | " + reason +
        " | " + (helped ? "Помощь оказана" : "Направлен") + " | " + note;
}

void Patient::print(ostream& os) const {
    os << left
        << setw(12) << date
        << setw(25) << fullName
        << setw(18) << group
        << setw(25) << reason
        << setw(20) << (helped ? "Помощь оказана" : "Направлен")
        << note << endl;
}

ostream& operator<<(ostream& os, const Patient& p) {
    p.print(os);
    return os;
}

istream& operator>>(istream& is, Patient& p) {
    cout << "Дата (дд.мм.гггг): ";  is >> p.date;
    cout << "Ф.И.О.: ";             is >> ws; getline(is, p.fullName);
    cout << "Группа: ";             getline(is, p.group);
    cout << "Причина: ";            getline(is, p.reason);
    cout << "Помощь оказана (1-да, 0-нет): ";
    is >> p.helped;
    cout << "Примечание: ";         is >> ws; getline(is, p.note);
    return is;
}

int inputInt(const string& prompt, int minV, int maxV) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < minV || value > maxV) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите число от " << minV << " до " << maxV << ".\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

string inputString(const string& prompt) {
    string s;
    while (true) {
        cout << prompt;
        getline(cin, s);
        if (!s.empty()) return s;
        cout << "Ошибка! Поле не может быть пустым.\n";
    }
}

bool isValidDate(const string& date) {
    if (date.size() != 10) return false;
    if (date[2] != '.' || date[5] != '.') return false;
    for (int i : {0, 1, 3, 4, 6, 7, 8, 9}) {
        if (!isdigit(date[i])) return false;
    }
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));
    return (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1900);
}

void addPatient(vector<Patient>& patients) {
    string date, fullName, group, reason, note;
    bool helped;

    while (true) {
        date = inputString("Введите дату (дд.мм.гггг): ");
        if (isValidDate(date)) break;
        cout << "Ошибка! Неверный формат даты.\n";
    }

    fullName = inputString("Введите Ф.И.О. пациента: ");
    group = inputString("Введите группу (кафедру/отдел): ");
    reason = inputString("Введите причину обращения: ");

    int h = inputInt("Помощь оказана? (1 - да, 0 - направлен): ", 0, 1);
    helped = (h == 1);

    note = inputString("Введите примечание: ");

    Patient p(date, fullName, group, reason, helped, note);
    patients.push_back(p);
    cout << "Запись успешно добавлена.\n";
}

void printAll(const vector<Patient>& patients) {
    if (patients.empty()) {
        cout << "Список пуст.\n";
        return;
    }
    cout << "\n" << string(120, '=') << endl;
    cout << left
        << setw(12) << "Дата"
        << setw(25) << "Ф.И.О."
        << setw(18) << "Группа"
        << setw(25) << "Причина"
        << setw(20) << "Статус"
        << "Примечание" << endl;
    cout << string(120, '-') << endl;
    for (const auto& p : patients) {
        p.print();
    }
    cout << string(120, '=') << endl;
}

void printByDate(const vector<Patient>& patients, const string& date) {
    bool found = false;
    cout << "\nПациенты, обратившиеся " << date << ":\n";
    cout << string(60, '-') << endl;
    for (const auto& p : patients) {
        if (p.matchesDate(date)) {
            cout << p.getFullName() << " | " << p.getGroup()
                << " | " << p.getReason() << endl;
            found = true;
        }
    }
    if (!found) cout << "  (нет таких пациентов)\n";
}

void printRedirected(const vector<Patient>& patients) {
    bool found = false;
    cout << "\nПациенты, направленные в другое лечебное учреждение:\n";
    cout << string(60, '-') << endl;
    for (const auto& p : patients) {
        if (p.isRedirected()) {
            cout << p.getDate() << " | " << p.getFullName()
                << " | " << p.getGroup() << " | " << p.getNote() << endl;
            found = true;
        }
    }
    if (!found) cout << "  (нет таких пациентов)\n";
}