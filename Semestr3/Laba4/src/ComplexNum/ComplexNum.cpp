#include "ComplexNum.h"

ComplexNums::ComplexNums(double _a, double _b) : a(_a), b(_b) {}
ComplexNums::ComplexNums(double _a) : ComplexNums(_a, 0) {}
ComplexNums::ComplexNums() : ComplexNums(0, 0) {}

ComplexNums::ComplexNums(const ComplexNums &obj) { this->a = obj.a; this->b = obj.b; }

double ComplexNums::getA() const { return a; }
double ComplexNums::getB() const { return b; }

void ComplexNums::Set(double r, double i) {
    a = r;
    b = i;
}

void ComplexNums::setA(double _a) { a = _a; }
void ComplexNums::setB(double _b) { b = _b; }

bool ComplexNums::operator<(ComplexNums& A) {
    double a1 = this->a, a2 = A.a;
    double b1 = this->b, b2 = A.b;
    double r1 = a1 * a1 + b1 * b1, r2 = a2 * a2 + b2 * b2;
    if (r1 < r2)
        return 1;
    else
        return 0;
}
bool ComplexNums::operator>(ComplexNums& A) {
    double a1 = this->a, a2 = A.a;
    double b1 = this->b, b2 = A.b;
    double r1 = a1 * a1 + b1 * b1, r2 = a2 * a2 + b2 * b2;
    if (r1 > r2)
        return 1;
    else
        return 0;
}
bool ComplexNums::operator==(ComplexNums& A) {
    double a1 = this->a, a2 = A.a;
    double b1 = this->b, b2 = A.b;
    if (a1 == a2 && b1 == b2)
        return 1;
    else
        return 0;
}

char* ComplexNums::to_string() {
    int n = 50;
    char* string = new char[n];
    if (b > 0) {
        sprintf(string, "%0.2f + %0.2fi", a, b);
    }
    else if (b == 0) {
        sprintf(string, "%0.2f", a);
    }
    else {
        sprintf(string, "%0.2f - %0.2fi", a, b);
    }
    return string;
}

char* ComplexNums::to_str() {
    int n = floor(log10(abs(a))) + floor(log10(abs(b))) + 15;
    char* string = new char[n+1];
    if (b > 0) {
        sprintf(string, "%0.2f + %0.2fi", a, b);
    }
    else if (b == 0) {
        sprintf(string, "%0.2f", a);
    }
    else {
        sprintf(string, "%0.2f - %0.2fi", a, b);
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

ostream& operator<<(ostream& os, ComplexNums& num) {
    os << num.getA() << showpos << num.getB() << noshowpos << "i";
    return os;
}

istream& operator>>(istream& is, ComplexNums& A) {
    is >> A.a >> A.b;
    return is;
}