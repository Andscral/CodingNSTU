#ifndef LABA5_LIST_H
#define LABA5_LIST_H
#include "ComplexNum/ComplexNum.h"
#include <iostream>
#include <ctime>

class Node {
public:
    ComplexNums& data;
    Node* next;

    Node(ComplexNums& data) : data(data), next(nullptr) {}
};

class List {
public:
     List();
    ~List();

    char* to_str();

    void adding(ComplexNums& data); //добавление
    void remove(int index); // удаление по номеру
    void paste(ComplexNums& data, int index); //вставка по номеру
    int find(ComplexNums& data);    //поиск
    void showAll(ostream& os);  //просмотр
    void show(int index); //просмотр по индексу

private:
    Node* head;
};

#endif //LABA5_LIST_H
