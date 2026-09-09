#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

class Patient {
private:
    string date;
    string fullName;
    string group;
    string reason;
    bool   helped;
    string note;

public:
    Patient();
    Patient(const string& date, const string& fullName,
        const string& group, const string& reason,
        bool helped, const string& note);
    Patient(const string& date, const string& fullName);
    Patient(const Patient& other);
    ~Patient();

    string getDate()     const;
    string getFullName() const;
    string getGroup()    const;
    string getReason()   const;
    bool   isHelped()    const;
    string getNote()     const;

    void setDate(const string& d);
    void setFullName(const string& f);
    void setGroup(const string& g);
    void setReason(const string& r);
    void setHelped(bool h);
    void setNote(const string& n);

    void print(ostream& os = cout) const;
    bool isRedirected() const;
    bool matchesDate(const string& d) const;
    string toString() const;

    friend ostream& operator<<(ostream& os, const Patient& p);
    friend istream& operator>>(istream& is, Patient& p);
};

void  addPatient(vector<Patient>& patients);
void  printAll(const vector<Patient>& patients);
void  printByDate(const vector<Patient>& patients, const string& date);
void  printRedirected(const vector<Patient>& patients);
int   inputInt(const string& prompt, int minV, int maxV);
string inputString(const string& prompt);
bool  isValidDate(const string& date);

#endif