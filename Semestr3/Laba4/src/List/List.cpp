#include "List.h"
#include <iostream>

using namespace std;

List::List() : head(nullptr) {}

List::~List() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void List::adding(ComplexNums& data) {
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

void List::remove(int index) {
    if (head == nullptr) return;

    Node *current = head;
    if (index == 0) {
        head = current->next;
        delete current;
        return;
    }

    for (int i = 0; i < index - 1 && current != nullptr; ++i) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) return;

    Node *toDelete = current->next;
    current->next = toDelete->next;

    delete toDelete;
}

void List::paste(ComplexNums& data, int index) {
    Node *new_node = new Node(data);
    if (head == nullptr) {
        head = new_node;
    }
    if (index == 0) {
        new_node->next = head;
        head = new_node;
        return;
    }
    Node *current = head;
    int count = 0;
    while (current != nullptr && count < index - 1) {
        current = current->next;
        count++;
    }
    if (current != nullptr) {
        new_node->next = current->next;
        current->next = new_node;
    } else {
        delete new_node;;
    }
}

int List::find(ComplexNums& data) {
    Node* current = head;
    int index = 0;

    while (current) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        ++index;
    }

    return -1; // Не найдено
}

void List::showAll(ostream& os) {
    if (head == nullptr) { os << "list is empty" << endl;
        return; }
    Node* current = head;
    while (current != nullptr) {
        char* data_str = current->data.to_str();
        os << data_str << "  ";
        delete[] data_str;
        current = current->next;
    }
    os << endl;
}

void List::show(int index) {
    if (head == nullptr) { return; }
    Node* current = head;
    int count = 0;
    while (current != nullptr && index > count) {
        current = current->next;
        count++;
    }
    if (current == nullptr) { throw string{ "no node with such number" }; }
    else {
        char* data_str = current->data.to_str();
        cout << data_str << endl;
        delete[] data_str;
    }
}