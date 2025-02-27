#include "ComplexNum.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <sstream>

ComplexNums::ComplexNums(double _a, double _b) : a(_a), b(_b) {}
ComplexNums::ComplexNums(double _a) : ComplexNums(_a, 0) {}
ComplexNums::ComplexNums() : ComplexNums(0, 0) {}
ComplexNums::~ComplexNums() = default;

ComplexNums::ComplexNums(const ComplexNums &obj) { this->a = obj.a; this->b = obj.b; }

double ComplexNums::getA() const { return a; }
double ComplexNums::getB() const { return b; }

void ComplexNums::setA(double _a) { a = _a; }
void ComplexNums::setB(double _b) { b = _b; }

ComplexNums ComplexNums::Add(ComplexNums &num1, ComplexNums &num2) {
    double a1 = num1.getA(), a2 = num2.getA();
    double b1 = num1.getB(), b2 = num2.getB();

    double res_a = a1 + a2;
    double res_b = b1 + b2;

    return {res_a, res_b};

}
ComplexNums ComplexNums::Subtract(ComplexNums &num1, ComplexNums &num2) {
    double a1 = num1.getA(), a2 = num2.getA();
    double b1 = num1.getB(), b2 = num2.getB();

    double res_a = a1 - a2;
    double res_b = b1 - b2;

    return {res_a, res_b};
}
ComplexNums ComplexNums::Multiply(const ComplexNums &num1, const ComplexNums &num2) {
    double a1 = num1.getA(), a2 = num2.getA();
    double b1 = num1.getB(), b2 = num2.getB();

    double res_a = a1*a2 - b1*b2;
    double res_b = b1*a2 + a1*b2;

    return {res_a, res_b};
}
ComplexNums ComplexNums::Divide(const ComplexNums &num1, const ComplexNums &num2) {
    double a1 = num1.getA(), a2 = num2.getA();
    double b1 = num1.getB(), b2 = num2.getB();

    double res_a = (a1*a2 + b1*b2) / (a2*a2 + b2*b2);
    double res_b = (a2*b1 - a1*b2) / (a2*a2 + b2*b2);

    return {res_a, res_b};
}

//2 лаба
ComplexNums& ComplexNums::operator=(const ComplexNums& obj) {
    if (this != &obj) {
        a = obj.a;
        b = obj.b;
    }
    return *this;
}
//todo
ComplexNums operator*(const ComplexNums& num1, const ComplexNums& num2) {
    return { num1.getA() * num2.getA() - num1.getB() * num2.getB(),
             num1.getB() * num2.getA() + num1.getA() * num2.getB() };
}
ComplexNums ComplexNums::operator/(const ComplexNums& obj) const {
    return Divide(*this, obj);
}
bool ComplexNums::operator==(const ComplexNums& obj) const {
    return (a == obj.a) && (b == obj.b);
}
bool ComplexNums::operator!=(const ComplexNums& obj) const {
    return !(*this == obj);
}
const char* ComplexNums::operator()() const {
    double r = sqrt(a * a + b * b);
    double ugol = atan2(b, a);
    static char buffer[100];
    sprintf(buffer, "Trig. form: %0.2f (cos(%0.2f) + i*sin(%0.2f))", r, ugol, ugol);
    return buffer;
}

//3 лабораторная
//todo
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

//todo
void ComplexNums::saveToBinaryFile(ofstream& ofs) const {
    ofs.write((const char*)(this), sizeof(ComplexNums));
}
void ComplexNums::loadToBinaryFile(ifstream& ifs) {
    ifs.read((char*)(this), sizeof(ComplexNums));
}