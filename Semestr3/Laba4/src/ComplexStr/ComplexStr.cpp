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

char* ComplexStr::to_str() {
    char* result = new char[50];
    if (b > 0) {
        sprintf(result, "%0.2f + %0.2fi", a, b);
    }
    else if (b == 0) {
        sprintf(result, "%0.2f", a);
    }
    else {
        sprintf(result, "%0.2f - %0.2fi", a, b);
    }
    return result;
}