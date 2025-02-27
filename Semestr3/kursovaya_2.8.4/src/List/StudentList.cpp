#include "../List/StudentList.h"

StudentsList::StudentsList(const string& filename) : filename(filename), head(nullptr), tail(nullptr) {}

StudentsList::~StudentsList() {
    Student* current = head;
    while (current) {
        Student* next = current->next;
        delete current;
        current = next;
    }
}

void StudentsList::saveToFile() {
    ofstream file(filename, ios::binary);

    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Student* current = head;

    while (current != nullptr) {
        // Сохраняем только студентов, которые не помечены как удаленные
        size_t lastNameSize = current->lastName.size();
        file.write(reinterpret_cast<const char*>(&lastNameSize), sizeof(size_t));
        file.write(current->lastName.c_str(), lastNameSize);

        size_t birthDateSize = current->birthDate.size();
        file.write(reinterpret_cast<const char*>(&birthDateSize), sizeof(size_t));
        file.write(current->birthDate.c_str(), birthDateSize);

        size_t admissionDateSize = current->admissionDate.size();
        file.write(reinterpret_cast<const char*>(&admissionDateSize), sizeof(size_t));
        file.write(current->admissionDate.c_str(), admissionDateSize);

        size_t expulsionDateSize = current->expulsionDate.size();
        file.write(reinterpret_cast<const char*>(&expulsionDateSize), sizeof(size_t));
        file.write(current->expulsionDate.c_str(), expulsionDateSize);

        size_t addressSize = current->address.size();
        file.write(reinterpret_cast<const char*>(&addressSize), sizeof(size_t));
        file.write(current->address.c_str(), addressSize);

        size_t groupSize = current->group.size();
        file.write(reinterpret_cast<const char*>(&groupSize), sizeof(size_t));
        file.write(current->group.c_str(), groupSize);

        current = current->next;
    }

    file.close();
}

void StudentsList::loadFromFile() {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error reading!" << endl;
        return;
    }

    while (file.peek() != EOF) {
        size_t lastNameSize;
        file.read(reinterpret_cast<char*>(&lastNameSize), sizeof(size_t));
        char* lastName = new char[lastNameSize + 1];
        file.read(lastName, lastNameSize);
        lastName[lastNameSize] = '\0';

        size_t birthDateSize;
        file.read(reinterpret_cast<char*>(&birthDateSize), sizeof(size_t));
        char* birthDate = new char[birthDateSize + 1];
        file.read(birthDate, birthDateSize);
        birthDate[birthDateSize] = '\0';

        size_t admissionDateSize;
        file.read(reinterpret_cast<char*>(&admissionDateSize), sizeof(size_t));
        char* admissionDate = new char[admissionDateSize + 1];
        file.read(admissionDate, admissionDateSize);
        admissionDate[admissionDateSize] = '\0';

        size_t expulsionDateSize;
        file.read(reinterpret_cast<char*>(&expulsionDateSize), sizeof(size_t));
        char* expulsionDate = new char[expulsionDateSize + 1];
        file.read(expulsionDate, expulsionDateSize);
        expulsionDate[expulsionDateSize] = '\0';

        size_t addressSize;
        file.read(reinterpret_cast<char*>(&addressSize), sizeof(size_t));
        char* address = new char[addressSize + 1];
        file.read(address, addressSize);
        address[addressSize] = '\0';

        size_t groupSize;
        file.read(reinterpret_cast<char*>(&groupSize), sizeof(size_t));
        char* group = new char[groupSize + 1];
        file.read(group, groupSize);
        group[groupSize] = '\0';

        // Создание нового студента
        Student newStudent(lastName, birthDate, admissionDate, expulsionDate, address, group);
        addStudent(newStudent);

        delete[] lastName;
        delete[] birthDate;
        delete[] admissionDate;
        delete[] expulsionDate;
        delete[] address;
        delete[] group;
    }
    file.close();
}

void StudentsList::addStudent(const Student& student) {
    Student* newStudent = new Student(student);

    if (tail) {
        tail->next = newStudent;
        newStudent->prev = tail;
        tail = newStudent;
    } else {
        head = tail = newStudent; // список был пуст
    }
    saveToFile();
}

void StudentsList::removeStudent(int index) {
    if (index < 0) {
        cerr << "Index invalid." << endl;
        return;
    }

    // Если список пуст, ничего не делаем
    if (!head) {
        cerr << "Student list is empty." << endl;
        return;
    }

    // Если удаляется первый элемент
    if (index == 0) {
        Student* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        cout << "Student with index (0) deleted." << endl;
        saveToFile();
        return;
    }

    // Поиск элемента для удаления
    Student* current = head;
    int count = 0;
    while (current && count < index - 1) {
        current = current->next;
        count++;
    }

    // Если элемент не найден
    if (!current || !current->next) {
        cerr << "Student with index (" << index << ") not found." << endl;
        return;
    }

    // Удаление элемента
    Student* toDelete = current->next;
    current->next = toDelete->next;
    if (toDelete->next) {
        toDelete->next->prev = current;
    } else {
        tail = current;
    }
    delete toDelete;

    cout << "Student with index (" << index << ") deleted." << endl;
    saveToFile();
}

void StudentsList::editStudent(const string& surname, const string& group, Student& newData) {
    Student* current = head;

    // Проверяем, что список не пуст
    if (current == nullptr) {
        cerr << "List student empty!" << endl;
        return;
    }
    bool found = false;

    do {
        // Сравниваем фамилию и группу текущего студента с искомой
        if (current->group == group && current->lastName == surname) {
            found = true;
            // Выводим текущие данные студента
            cout << "Edit data student: " << current->lastName << endl;

            // Обновляем данные студента
            cout << "new lastname (current: " << current->lastName << "): ";
            cin >> newData.lastName;

            cout << "new birth data (current: " << current->birthDate << "): ";
            cin >> newData.birthDate;

            cout << "new admission date (current: " << current->admissionDate << "): ";
            cin >> newData.admissionDate;

            cout << "new expulsion date (current: " << current->expulsionDate << "): ";
            cin >> newData.expulsionDate;

            cout << "new address (current: " << current->address << "): ";
            cin.ignore(); // Игнорируем остаток строки после предыдущего ввода
            getline(cin, newData.address); // Используем getline для ввода адреса

            cout << "new group (current: " << current->group << "): ";
            cin >> newData.group;

            // Обновляем данные студента
            current->lastName = newData.lastName;
            current->group = newData.group;
            current->birthDate = newData.birthDate;
            current->admissionDate = newData.admissionDate;
            current->expulsionDate = newData.expulsionDate;
            current->address = newData.address;

            cout << "The data has been updated successfully!" << endl;
            saveToFile();
            return;
        }
        current = current->next; // Переходим к следующему студенту
    } while (current != head); // Цикл продолжается, пока не вернемся к началу

    cerr << "Student lastname '" << surname << "' not found!" << endl;
}

void StudentsList::insertStudent(int index, const Student& student) {
    Student* newStudent = new Student(student);

    if (index == 0) {
        newStudent->next = head;
        if (head) {
            head->prev = newStudent;
        }
        head = newStudent;
        if (!tail) {
            tail = newStudent;
        }
    } else {
        Student* current = head;
        int count = 0;

        while (current != nullptr && count < index - 1) {
            current = current->next;
            count++;
        }

        if (current) {
            newStudent->next = current->next;
            newStudent->prev = current;

            if (current->next) {
                current->next->prev = newStudent;
            } else {
                tail = newStudent;
            }
            current->next = newStudent;
        } else {
            if (tail) {
                tail->next = newStudent;
                newStudent->prev = tail;
                tail = newStudent;
            } else {
                // Если список пуст
                head = newStudent;
                tail = newStudent;
            }
        }
    }
    // Обновление файла после вставки студента
    saveToFile();
}

void StudentsList::displayStudents(int pageSize, int page) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "error open file." << endl;
        return;
    }

    size_t position = 0;
    int count = 0;

    // Пропускаем до нужной страницы
    while (count < (page - 1) * pageSize && file.peek() != EOF) {
        size_t lastNameSize;
        file.seekg(position);
        file.read(reinterpret_cast<char*>(&lastNameSize), sizeof(size_t));
        position += sizeof(size_t) + lastNameSize; // Пропустить фамилию

        // Пропускаем остальные данные
        size_t birthDateSize;
        file.seekg(position);
        file.read(reinterpret_cast<char*>(&birthDateSize), sizeof(size_t));
        position += sizeof(size_t) + birthDateSize;

        size_t admissionDateSize;
        file.seekg(position);
        file.read(reinterpret_cast<char*>(&admissionDateSize), sizeof(size_t));
        position += sizeof(size_t) + admissionDateSize;

        size_t expulsionDateSize;
        file.seekg(position);
        file.read(reinterpret_cast<char*>(&expulsionDateSize), sizeof(size_t));
        position += sizeof(size_t) + expulsionDateSize;

        size_t addressSize;
        file.seekg(position);
        file.read(reinterpret_cast<char*>(&addressSize), sizeof(size_t));
        position += sizeof(size_t) + addressSize;

        size_t groupSize;
        file.seekg(position);
        file.read(reinterpret_cast<char*>(&groupSize), sizeof(size_t));
        position += sizeof(size_t) + groupSize;

        count++;
    }

    count = 0;

    // Чтение и вывод студентов на экран
    while (count < pageSize && file.peek() != EOF) {
        size_t lastNameSize;
        file.seekg(position);
        file.read(reinterpret_cast<char*>(&lastNameSize), sizeof(size_t));
        char* lastName = new char[lastNameSize + 1];
        file.read(lastName, lastNameSize);
        lastName[lastNameSize] = '\0';

        size_t birthDateSize;
        file.read(reinterpret_cast<char*>(&birthDateSize), sizeof(size_t));
        char* birthDate = new char[birthDateSize + 1];
        file.read(birthDate, birthDateSize);
        birthDate[birthDateSize] = '\0';

        size_t admissionDateSize;
        file.read(reinterpret_cast<char*>(&admissionDateSize), sizeof(size_t));
        char* admissionDate = new char[admissionDateSize + 1];
        file.read(admissionDate, admissionDateSize);
        admissionDate[admissionDateSize] = '\0';

        size_t expulsionDateSize;
        file.read(reinterpret_cast<char*>(&expulsionDateSize), sizeof(size_t));
        char* expulsionDate = new char[expulsionDateSize + 1];
        file.read(expulsionDate, expulsionDateSize);
        expulsionDate[expulsionDateSize] = '\0';

        size_t addressSize;
        file.read(reinterpret_cast<char*>(&addressSize), sizeof(size_t));
        char* address = new char[addressSize + 1];
        file.read(address, addressSize);
        address[addressSize] = '\0';

        size_t groupSize;
        file.read(reinterpret_cast<char*>(&groupSize), sizeof(size_t));
        char* groupName = new char[groupSize + 1];
        file.read(groupName, groupSize);
        groupName[groupSize] = '\0';

        // Вывод информации о студенте
        cout << count << ". " << lastName
                  << ", " << birthDate
                  << ", " << admissionDate
                  << ", " << expulsionDate
                  << ", " << address
                  << ", " << groupName << endl;

        delete[] lastName;
        delete[] birthDate;
        delete[] admissionDate;
        delete[] expulsionDate;
        delete[] address;
        delete[] groupName;

        // Обновление позиции для следующего студента
        position += sizeof(size_t) + lastNameSize + sizeof(size_t) + birthDateSize +
                    sizeof(size_t) + admissionDateSize + sizeof(size_t) + expulsionDateSize +
                    sizeof(size_t) + addressSize + sizeof(size_t) + groupSize;

        count++;
    }
    file.close();
}

void StudentsList::compressFile() {
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Error open!" << endl;
        return;
    }

    // Создаём временный файл для хранения сжатых данных
    string tempFilename = "temp_" + filename;
    ofstream outputFile(tempFilename, ios::binary);
    if (!outputFile) {
        cerr << "Error open temp file!" << endl;
        inputFile.close();
        return;
    }

    // Чтение данных из исходного файла и запись в новый файл
    while (inputFile.peek() != EOF) {
        size_t lastNameSize;
        inputFile.read(reinterpret_cast<char*>(&lastNameSize), sizeof(size_t));
        char* lastName = new char[lastNameSize + 1];
        inputFile.read(lastName, lastNameSize);
        lastName[lastNameSize] = '\0';

        // Записываем данные о студенте в новый файл
        outputFile.write(reinterpret_cast<const char*>(&lastNameSize), sizeof(size_t));
        outputFile.write(lastName, lastNameSize);

        size_t birthDateSize;
        inputFile.read(reinterpret_cast<char*>(&birthDateSize), sizeof(size_t));
        char* birthDate = new char[birthDateSize + 1];
        inputFile.read(birthDate, birthDateSize);
        birthDate[birthDateSize] = '\0';
        outputFile.write(reinterpret_cast<const char*>(&birthDateSize), sizeof(size_t));
        outputFile.write(birthDate, birthDateSize);

        size_t admissionDateSize;
        inputFile.read(reinterpret_cast<char*>(&admissionDateSize), sizeof(size_t));
        char* admissionDate = new char[admissionDateSize + 1];
        inputFile.read(admissionDate, admissionDateSize);
        admissionDate[admissionDateSize] = '\0';
        outputFile.write(reinterpret_cast<const char*>(&admissionDateSize), sizeof(size_t));
        outputFile.write(admissionDate, admissionDateSize);

        size_t expulsionDateSize;
        inputFile.read(reinterpret_cast<char*>(&expulsionDateSize), sizeof(size_t));
        char* expulsionDate = new char[expulsionDateSize + 1];
        inputFile.read(expulsionDate, expulsionDateSize);
        expulsionDate[expulsionDateSize] = '\0';
        outputFile.write(reinterpret_cast<const char*>(&expulsionDateSize), sizeof(size_t));
        outputFile.write(expulsionDate, expulsionDateSize);

        size_t addressSize;
        inputFile.read(reinterpret_cast<char*>(&addressSize), sizeof(size_t));
        char* address = new char[addressSize + 1];
        inputFile.read(address, addressSize);
        address[addressSize] = '\0';
        outputFile.write(reinterpret_cast<const char*>(&addressSize), sizeof(size_t));
        outputFile.write(address, addressSize);

        size_t groupSize;
        inputFile.read(reinterpret_cast<char*>(&groupSize), sizeof(size_t));
        char* group = new char[groupSize + 1];
        inputFile.read(group, groupSize);
        group[groupSize] = '\0';
        outputFile.write(reinterpret_cast<const char*>(&groupSize), sizeof(size_t));
        outputFile.write(group, groupSize);

        // Освобождение памяти
        delete[] lastName;
        delete[] birthDate;
        delete[] admissionDate;
        delete[] expulsionDate;
        delete[] address;
        delete[] group;
    }

    inputFile.close();
    outputFile.close();

    // Заменяем старый файл новым сжатым файлом
    remove(filename.c_str());
    rename(tempFilename.c_str(), filename.c_str());
    cout << "File compressed." << endl;
}

void StudentsList::searchStudentByIndex(int index) {
    ifstream file(filename, ios::binary);
    if (file) {
        size_t position = 0;
        for (int i = 0; i < index; ++i) {
            size_t lastNameSize;
            file.seekg(position);
            file.read(reinterpret_cast<char*>(&lastNameSize), sizeof(size_t));
            position += sizeof(size_t) + lastNameSize;

            size_t birthDateSize;
            file.seekg(position);
            file.read(reinterpret_cast<char*>(&birthDateSize), sizeof(size_t));
            position += sizeof(size_t) + birthDateSize;

            size_t admissionDateSize;
            file.seekg(position);
            file.read(reinterpret_cast<char*>(&admissionDateSize), sizeof(size_t));
            position += sizeof(size_t) + admissionDateSize;

            size_t expulsionDateSize;
            file.seekg(position);
            file.read(reinterpret_cast<char*>(&expulsionDateSize), sizeof(size_t));
            position += sizeof(size_t) + expulsionDateSize;

            size_t addressSize;
            file.seekg(position);
            file.read(reinterpret_cast<char*>(&addressSize), sizeof(size_t));
            position += sizeof(size_t) + addressSize;

            size_t groupSize;
            file.seekg(position);
            file.read(reinterpret_cast<char*>(&groupSize), sizeof(size_t));
            position += sizeof(size_t) + groupSize;
        }

        size_t lastNameSize;
        file.seekg(position);
        file.read(reinterpret_cast<char*>(&lastNameSize), sizeof(size_t));
        char* lastName = new char[lastNameSize + 1];
        file.read(lastName, lastNameSize);
        lastName[lastNameSize] = '\0';

        size_t birthDateSize;
        file.read(reinterpret_cast<char*>(&birthDateSize), sizeof(size_t));
        char* birthDate = new char[birthDateSize + 1];
        file.read(birthDate, birthDateSize);
        birthDate[birthDateSize] = '\0';

        size_t admissionDateSize;
        file.read(reinterpret_cast<char*>(&admissionDateSize), sizeof(size_t));
        char* admissionDate = new char[admissionDateSize + 1];
        file.read(admissionDate, admissionDateSize);
        admissionDate[admissionDateSize] = '\0';

        size_t expulsionDateSize;
        file.read(reinterpret_cast<char*>(&expulsionDateSize), sizeof(size_t));
        char* expulsionDate = new char[expulsionDateSize + 1];
        file.read(expulsionDate, expulsionDateSize);
        expulsionDate[expulsionDateSize] = '\0';

        size_t addressSize;
        file.read(reinterpret_cast<char*>(&addressSize), sizeof(size_t));
        char* address = new char[addressSize + 1];
        file.read(address, addressSize);
        address[addressSize] = '\0';

        size_t groupSize;
        file.read(reinterpret_cast<char*>(&groupSize), sizeof(size_t));
        char* groupName = new char[groupSize + 1];
        file.read(groupName, groupSize);
        groupName[groupSize] = '\0';

        // Вывод информации о студенте
        cout << "lastName: " << lastName << "\nbirthDate: " << birthDate
             << "\nadmissionDate: " << admissionDate << "\n"
             << "expulsionDate: " << expulsionDate << "\naddress: " << address
             << "\ngroup: " << groupName << endl;

        delete[] lastName;
        delete[] birthDate;
        delete[] admissionDate;
        delete[] expulsionDate;
        delete[] address;
        delete[] groupName;

        file.close();
    }
}

void StudentsList::sortStudents() {
    // Если список пуст или состоит из одного элемента, ничего не делаем
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Student* current = head;
        Student* prev = nullptr;

        while (current->next) {
            if (string(current->lastName) > string(current->next->lastName)) {
                Student* nextStudent = current->next;

                // Обновляем связи
                if (prev) {
                    prev->next = nextStudent;
                } else {
                    head = nextStudent;
                }
                current->next = nextStudent->next;
                nextStudent->next = current;

                // Обновляем prev указатели
                nextStudent->prev = prev;
                current->prev = nextStudent;
                if (current->next) {
                    current->next->prev = current;
                } else {
                    tail = current;
                }

                prev = nextStudent;
                swapped = true;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);

    // Обновляем tail указатель
    tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    saveToFile();
}


