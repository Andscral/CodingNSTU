#include "ComplexNum.h"

ComplexNums::ComplexNums(double _a, double _b) : a(_a), b(_b) {}
ComplexNums::ComplexNums(double _a) : ComplexNums(_a, 0) {}
ComplexNums::ComplexNums() : ComplexNums(0, 0) {}
ComplexNums::~ComplexNums() = default;

ComplexNums::ComplexNums(const ComplexNums &obj) { this->a = obj.a; this->b = obj.b; }

double ComplexNums::getA() const { return a; }
double ComplexNums::getB() const { return b; }

void ComplexNums::Set(double r, double i) {
    a = r;
    b = i;
}

void ComplexNums::setA(double _a) { a = _a; }
void ComplexNums::setB(double _b) { b = _b; }



char* ComplexNums::to_string() {
    int n = snprintf(nullptr, 0, "%0.2f + %0.2fi", a, b);
    if (b < 0) {
        n = snprintf(nullptr, 0, "%0.2f - %0.2fi", a, -b);
    }
    n += 1;
    char* string = (char*)malloc(n * sizeof(char));
    if (!string) {
        throw bad_alloc();
    }
    if (b >= 0) {
        sprintf(string, "%0.2f + %0.2fi", a, b);
    } else {
        sprintf(string, "%0.2f - %0.2fi", a, -b);
    }
    return string;
}

void ComplexNums::Get() {
    if (b > 0) {
        cout << a << " + " << b << "i" << endl;
    } else {
        cout << a << endl;
    }
}

ostream& operator<<(ostream& os, const ComplexNums& num) {
    os << num.getA() << showpos << num.getB() << noshowpos << "i";
    return os;
}

istream& operator>>(istream& is, ComplexNums& num) {
    double real, imag;
    char sign;

    is >> real >> sign >> imag;
    num.setA(real);

    if (sign == '+') {
        num.setB(imag);
    } else if (sign == '-') {
        num.setB(-imag);
    }
    return is;
}

void ComplexNums::ShowExtra() { cout << "Base class" << endl; }