#ifndef LABA5_LIST_H
#define LABA5_LIST_H
#include "ComplexNum.h"
#include <iostream>

template<class T>
class Node {
public:
    Node* next;
    T& obj;
    Node(T& A) : obj(A), next(nullptr) {}
};

template<class T>
class List {
public:
    List() : start(nullptr) {}
    void paste(T& A, int num); //вставка по номеру
    void adding(T& A); // вставка в конец
    void remove(int num); // удаление по номеру
    void removeEnd(T& A);// удаление последнего
    void showAll(ostream& os); // вывод всего списка
    void show(int num);
private:
    Node<T>* start;
};

template<class T>
void List<T>::show(int num) {
    if (start == nullptr) {}
    else {
        Node<T>* current = start;
        int count = 0;
        while (current->next != nullptr and num > count++) {
            current = current->next;
        }
        if (current->next == nullptr && num != count) {
            throw overflow_error{ "no node with such number"};
        }
        else {
            cout << current->obj << endl;
        }
    }
}

template<>
void List<ComplexNums>::showAll(ostream& os) {
    if (start == nullptr) { }
    else {
        Node<ComplexNums> *current = start;
        while (current->next != nullptr) {
            os << current->obj << "  ";
            current = current->next;
        }
        os << current->obj << endl;
    }
}

template<class T>
void List<T>::paste(T& A, int num) {
    Node<T>* newNode = new Node<T>(A);
    if (start == nullptr) {
        start = newNode;
    }
    else {
        Node<T>* current = start;
        int count = 0;
        while (current->next != nullptr && num > ++count) {
            current = current->next;
        }
        if (current->next == nullptr) {
            current->next = newNode;
        }
        else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

template<class T>
void List<T>::adding(T& A) {
    Node<T>* newNode = new Node<T>(A);
    if (start == nullptr) {
        start = newNode;
    }
    else {
        Node<T>* current = start;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template<class T>
void List<T>::remove(int num) {
    if (start == nullptr) {}
    else {
        Node<T>* current = start;
        int count = 0;
        while (current->next != nullptr and num > ++count) {
            current = current->next;
        }
        if (current->next == nullptr) {}
        else {
            Node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
}

template<class T>
void List<T>::removeEnd(T& A) {
    if (start == nullptr) {}
    else {
        Node<T>* current = start;
        int count = 0;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next->next;
        current->next = nullptr;
    }
}

template<class T>
void List<T>::showAll(ostream& os) {
    if (start == nullptr) { cout << "list is empty" << endl; }
    else {
        Node<T> *current = start;
        while (current->next != nullptr) {
            os << current->obj << "  ";
            current = current->next;
        }
        os << current->obj << endl;
    }
}
#endif //LABA5_LIST_H
