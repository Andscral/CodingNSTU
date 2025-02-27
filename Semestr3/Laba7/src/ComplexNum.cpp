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
ComplexNums ComplexNums::Divide(ComplexNums& A, ComplexNums B) {
    double divider = (B.a * B.a + B.b * B.b);
    if (divider) {
        double new_real = (A.a * B.a + A.b * B.b) / divider;
        double new_imaginary = (A.b * B.a - A.a * B.b) / divider;
        ComplexNums C(new_real, new_imaginary);
        return C;
    }
    else {
        throw runtime_error{"division by 0"};
    }
}

ComplexNums ComplexNums::operator/(const ComplexNums& num) {
    double divider = (num.a * num.a + num.b * num.b);
    if (divider) {
        double real = (this->a * num.a + this->b * num.b) / divider;
        double imag = (this->b * num.a - this->a * num.b) / divider;
        return ComplexNums(real, imag);
    } else {
        throw underflow_error{"division by 0"};
    }
}

ComplexNums& ComplexNums::operator=(const ComplexNums& obj) {
    if (this != &obj) {
        a = obj.a;
        b = obj.b;
    }
    return *this;
}

ComplexNums operator*(const ComplexNums& num1, const ComplexNums& num2) {
    return { num1.getA() * num2.getA() - num1.getB() * num2.getB(),
             num1.getB() * num2.getA() + num1.getA() * num2.getB() };
}

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

void ComplexNums::Get() {
    if (b > 0) {
        cout << a << " + " << b << "i" << endl;
    } else {
        cout << a << endl;
    }
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

ostream& operator<<(ostream& os, const ComplexNums& num) {
    os << num.getA() << showpos << num.getB() << noshowpos << "i";
    return os;
}

istream& operator>>(istream& is, ComplexNums& A) {
    is >> A.a >> A.b;
    return is;
}

