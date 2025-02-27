#ifndef KURSOVAYA_2_8_4_STUDENT_H
#define KURSOVAYA_2_8_4_STUDENT_H

using namespace std;

#include <string>

struct Student {
    string lastName;
    string birthDate;
    string admissionDate;
    string expulsionDate;
    string address;
    string group;
    Student* next;
    Student* prev;

    Student() : lastName(""), birthDate(""), admissionDate(""),
    expulsionDate(""), address(""), group("") {}

    Student(const string& lastName, const string& birthDate,
            const string& admissionDate, const string& expulsionDate,
            const string& address, const string& group)
            : lastName(lastName), birthDate(birthDate), admissionDate(admissionDate),
            expulsionDate(expulsionDate), address(address), group(group),
            next(nullptr), prev(nullptr) {}
};

#endif
