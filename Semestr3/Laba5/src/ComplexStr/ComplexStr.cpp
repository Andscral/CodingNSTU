#include "ComplexStr/ComplexStr.h"

ComplexStr::ComplexStr() : ComplexNums(0, 0) { string = new char[10]; }

void ComplexStr::from_string(const char* string) {
    int ind = 0;
    double r = 0;
    double i = 0;
    char sign = '+';
    while (string[ind] != ' ' && string[ind] != '+' && string[ind] != '-' && string[ind] != '\0') {
        r = r * 10 + (string[ind] - '0');
        ind++;
    }
    while (string[ind] == ' ') {
        ind++;
    }
    if (string[ind] == '+' || string[ind] == '-') {
        sign = string[ind];
        ind++;
    }
    while (string[ind] == ' ') {
        ind++;
    }
    while (string[ind] != 'i' && string[ind] != '\0') {
        i = i * 10 + (string[ind] - '0');
        ind++;
    }
    if (sign == '-') {
        i = -i;
    }

    this->Set(r, i);
};

void ComplexStr::ShowExtra() { cout << "String class" << endl; }