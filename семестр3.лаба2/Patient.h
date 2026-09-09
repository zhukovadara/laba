#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Patient {
private:
    string date;
    string fio;
    string group;
    string reason;
    bool wasSentToHospital;
    string note;

public:
    Patient();

    Patient(const string& date, const string& fullName, const string& group,
        const string& reason, bool wasSentToHospital, const string& note);

    string getDate() const;
    string getFullName() const;
    string getGroup() const;
    string getReason() const;
    bool wasSent() const;
    string getNote() const;

    void setDate(const string& date);
    void setFullName(const string& fullName);
    void setGroup(const string& group);
    void setReason(const string& reason);
    void setWasSentToHospital(bool value);
    void setNote(const string& note);

    void print() const;
};

string getString(const string& prompt);

int getNumber(const string& prompt, int minVal, int maxVal);

Patient inputPatient();

void printPatientsByDate(const vector<Patient>& patients, const string& date);

void printSentPatients(const vector<Patient>& patients);

#endif