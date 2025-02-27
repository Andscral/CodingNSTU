#pragma once
#include "Imaginary_String.h"

Imaginary_String::Imaginary_String() : Imaginary(0, 0) { String = new char[10]; }

void Imaginary_String::from_string(const char* string) {
    int a = 0;
    double r = 0;
    double i = 0;
    char sign = ' ';
    while (string[a] != ' ' && string[a] != '+' && string[a] != '-' && string[a] != '\0') {
        r = r * 10 + (string[a] - '0');
        a++;
    }
    while (string[a] == ' ') {
        a++;
    }
    if (string[a] == '+' || string[a] == '-') {
        sign = string[a];
        a++;
    }
    while (string[a] == ' ') {
        a++;
    }
    while (string[a] != 'i' && string[a] != '\0') {
        i = i * 10 + (string[a] - '0');
        a++;
    }

    if (sign == '-') {
        i = -i;
    }
    this->Set(r, i);
};

void Imaginary_String::ShowExtra() { cout << "String class" << endl; }