#ifndef KURSOVAYA_2_8_4_STUDENTLIST_H
#define KURSOVAYA_2_8_4_STUDENTLIST_H

#include "../Student/Student.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstring>

class StudentsList {
public:
    StudentsList(const string& filename);
    ~StudentsList();

    void saveToFile();
    void loadFromFile();

    void addStudent(const Student& student);
    void removeStudent(int index);
    void editStudent(const string& surname, const string& group, Student& newData);
    void insertStudent(int index, const Student& student);
    void displayStudents(int pageSize, int page);
    void compressFile();
    void searchStudentByIndex(int index);
    void sortStudents();

private:
    string filename;
    Student* head;
    Student* tail;
};

#endif
