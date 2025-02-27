#include <iostream>
#include "src/List/StudentList.h"

using namespace std;

void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Add a student\n";
    cout << "2. Delete a student\n";
    cout << "3. Edit\n";
    cout << "4. Insert student by index\n";
    cout << "5. Display list\n";
    cout << "6. Compress the file\n";
    cout << "7. Remove student by index\n";
    cout << "8. Sort list\n";
    cout << "0. Exit\n";
}

int main() {
    StudentsList studentsList("students.dat");
    studentsList.loadFromFile();
    int choice;

    do {
        displayMenu();
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {//add
                cout << "\n|Add student|" << endl;

                string lastName, birthDate, admissionDate, expulsionDate, address, group;
                cout << "LastName: ";
                cin >> lastName;
                cout << "Birth date: ";
                cin >> birthDate;
                cout << "Admission date: ";
                cin >> admissionDate;
                cout << "Expulsion date: ";
                cin >> expulsionDate;
                cout << "Address: ";
                cin >> address;
                cout << "Group: ";
                cin >> group;

                studentsList.addStudent(Student(lastName, birthDate, admissionDate, expulsionDate, address, group));
                break;
            }
            case 2: {//remove
                cout << "\n|Remove student|" << endl;
                int index;
                cout << "Student's index: ";
                cin >> index;
                studentsList.removeStudent(index);
                break;
            }
            case 3: {//edit
                cout << "\n|Edit student|" << endl;
                Student newData;
                string surname_edit, group_edit;
                cout << "Group student: ";
                cin >> group_edit;
                cout << "Lastname student: ";
                cin >> surname_edit;

                studentsList.editStudent(surname_edit, group_edit, newData);
                break;
            }
            case 4: {//insert
                cout << "\n|Insert student|" << endl;
                int index;
                cout << "Index insert: ";
                cin >> index;
                string lastName, birthDate, admissionDate, expulsionDate, address, group;
                cout << "LastName: ";
                cin >> lastName;
                cout << "Birth date: ";
                cin >> birthDate;
                cout << "Admission date: ";
                cin >> admissionDate;
                cout << "Expulsion date: ";
                cin >> expulsionDate;
                cout << "Address: ";
                cin >> address;
                cout << "Group: ";
                cin >> group;

                studentsList.insertStudent(index, Student(lastName, birthDate, admissionDate, expulsionDate, address, group));
                break;
            }
            case 5: {//display
                int pageSize, page;
                cout << "page size: ";
                cin >> pageSize;
                cout << "page number: ";
                cin >> page;
                cout << "\nStudent List, page(" << page << ")" << endl;
                studentsList.displayStudents(pageSize, page);
                break;
            }
            case 6: {//compress
                studentsList.compressFile();
                break;
            }
            case 7: {//search
                cout << "\n|Search student|" << endl;
                int index;
                cout << "Index student: ";
                cin >> index;
                cout << "\n|Student information|" << endl;
                studentsList.searchStudentByIndex(index);
                break;
            }
            case 8: {
                studentsList.sortStudents();
                break;
            }
            case 0:
                cout << "Exit." << endl;
                break;
            default:
                cout << "Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
           