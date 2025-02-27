#pragma once
#include <stdio.h>
#include "Imaginary.h"

template<class T>
class node {
public:
    node* next;
    T& obj;
    node(T& A) : obj(A), next(nullptr) {}
};

template<class T>
class list {
public:
    list() : start(nullptr) {}
    void push(T& A, int num); //вставка по номеру
    void pushEnd(T& A); // вставка в конец
    void pop(int num); // удаление по номеру
    void popEnd(T& A);// удаление последнего
    void show(int num); // вывод ячейки по номеру
    void showAll(ostream& os); // вывод всего списка
private:
    node<T>* start;
};

template<class T>
void list<T>::push(T& A, int num) {
    node<T>* newNode = new node<T>(A);
        if (start == nullptr) {
            start = newNode;
        }
        else {
            node<T>* current = start;
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
    void list<T>::pushEnd(T& A) {
        node<T>* newNode = new node<T>(A);
        if (start == nullptr) {
            start = newNode;
        }
        else {
            node<T>* current = start;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    template<class T>
    void list<T>::pop(int num) {
        if (start == nullptr) {}
        else {
            node<T>* current = start;
            int count = 0;
            while (current->next != nullptr and num > ++count) {
                current = current->next;
            }
            if (current->next == nullptr) {}
            else {
                node<T>* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
        }
    }
    template<class T>
    void list<T>::popEnd(T& A) {
        if (start == nullptr) {}
        else {
            node<T>* current = start;
            int count = 0;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next->next;
            current->next = nullptr;
        }
    }
    template<class T>
    void list<T>::show(int num) {
        if (start == nullptr) {}
        else {
            node<T>* current = start;
            int count = 0;
            while (current->next != nullptr and num > count++) {
                current = current->next;
            }
            if (current->next == nullptr && num != count) { throw string{ "no node with such number" }; }
            else {
                cout << current->obj << endl;
            }
        }
    }
    template<>
    void list<Imaginary>::show(int num) {
        if (start == nullptr) {}
        else {
            node<Imaginary>* current = start;
            int count = 0;
            while (current->next != nullptr and num > count++) {
                current = current->next;
            }
            if (current->next == nullptr && num!= count) { throw string{ "no node with such number" }; }
            else {
                cout << current->obj << endl;
                current->obj.ShowExtra();
            }
        }
    }

    template<class T> 
    void list<T>::showAll(ostream& os) {
        if (start == nullptr) { cout << "list is empty" << endl; }
        else {
            node<T>* current = start;
            while (current->next != nullptr) {
                os << current->obj << "  ";
                current = current->next;
            }
            os << current->obj << endl;
        }
    }

