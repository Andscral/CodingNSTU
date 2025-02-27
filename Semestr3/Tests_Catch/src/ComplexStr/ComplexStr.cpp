#include "ComplexStr/ComplexStr.h"
#include <cstring>
#include <cstdio>

ComplexStr::ComplexStr(const char* input) {
    strcpy(str, input);
    strToComplex();
}

void ComplexStr::strToComplex() {
    double real, imag;
    char sign;
    sscanf(str, "%lf %c %lfi", &real, &sign, &imag);
    setA(real);
    setB(sign == '-' ? -imag : imag);
}

const char* ComplexStr::complexToStr(const ComplexNums &num1) {
    double a = num1.getA();
    double b = num1.getB();
    sprintf(str, "%lf %s %lfi", a, (b >= 0 ? "+" : ""), fabs(b));
    return str;
}

void ComplexStr::getStr() const {
    cout << "Complex String: " << str << endl;
}