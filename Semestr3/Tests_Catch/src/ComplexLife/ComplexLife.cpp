#include "ComplexLife.h"
#include <iostream>
#include <ctime>

ComplexLife::ComplexLife(double _a, double _b) : ComplexNums(_a, _b) {
    Date = time(nullptr);
}
void ComplexLife::getDate() const {
    cout << "Created on: " << ctime(&Date);
}