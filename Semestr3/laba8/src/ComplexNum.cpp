#include "ComplexNum.h"

ComplexNum::ComplexNum(double Real, double Imag) : a(Real), b(Imag) {}

ComplexNum::ComplexNum(double Real) : ComplexNum(Real, 0) {}

ComplexNum::ComplexNum() : ComplexNum(0, 0) {}

ComplexNum::ComplexNum(const ComplexNum& other) : ComplexNum(other.a, other.b) {}


ComplexNum::~ComplexNum() {}

void ComplexNum::Get() {
    if (b > 0) {
        cout << a << " + " << b << "i" << endl;
    } else {
        cout << a << endl;
    }
}

double ComplexNum::getR() { return a; }
double ComplexNum::getI() { return b; }

void ComplexNum::Set(double R, double I) {
    a = R;
    b = I;
}

char* ComplexNum::to_string() {
    int n = floor(log10(abs(a))) + floor(log10(abs(b))) + 13;
    char* string = new char[n];
    if (b > 0) {
        sprintf_s(string, n, "%0.2f + %0.2fi", a, b);
    }
    else if (b == 0) {
        sprintf_s(string, n, "%0.2f", a);
    }
    else {
        sprintf_s(string, n, "%0.2f - %0.2fi", a, b);
    }
    return string;
}

ComplexNum ComplexNum::sum(ComplexNum A, ComplexNum B) {
    double new_real = A.a + B.a;
    double new_imaginary = A.b + B.b;
    ComplexNum C(new_real, new_imaginary);
    return C;
}
ComplexNum ComplexNum::substruct(ComplexNum A, ComplexNum B) {
    double new_real = A.a - B.a;
    double new_imaginary = A.b - B.b;
    ComplexNum C(new_real, new_imaginary);
    return C;
}
ComplexNum ComplexNum::multiplicate(ComplexNum A, ComplexNum B) {
    double new_real = A.a * B.a - A.b * B.b;
    double new_imaginary = A.b * B.a + A.a * B.b;
    ComplexNum C(new_real, new_imaginary);
    return C;
}
ComplexNum ComplexNum::divide(ComplexNum& A, ComplexNum B) {
    double divider = (B.a * B.a + B.b * B.b);
    if (divider) {
        double new_real = (A.a * B.a + A.b * B.b) / divider;
        double new_imaginary = (A.b * B.a - A.a * B.b) / divider;
        ComplexNum C(new_real, new_imaginary);
        return C;
    }
    else { throw runtime_error{"division by 0"}; }

}


ComplexNum ComplexNum::operator+(ComplexNum& A) {
    double real = this->a + A.a;
    double imag = this->b + A.b;
    return ComplexNum(real, imag);
}
ComplexNum ComplexNum::operator-(ComplexNum& A) {
    double real = this->a - A.a;
    double imag = this->b - A.b;
    return ComplexNum(real, imag);
}
ComplexNum ComplexNum::operator*(ComplexNum& A) {
     double real = this->a * A.a - this->b * A.b;
    double imag = this->b * A.a + this->a * A.b;
    return ComplexNum(real, imag);
}
ComplexNum ComplexNum::operator/(ComplexNum& A) {
    double divider = (A.a * A.a + A.b * A.b);
    if (divider) {
        double real = (this->a * A.a + this->b * A.b) / divider;
        double imag = (this->b * A.a - this->a * A.b) / divider;
        return ComplexNum(real, imag);
    }
    else { throw underflow_error{"division by 0"}; }
}
bool ComplexNum::operator<(const ComplexNum& A) const{
    double a1 = this->a, a2 = A.a;
    double b1 = this->b, b2 = A.b;
    double r1 = a1 * a1 + b1 * b1, r2 = a2 * a2 + b2 * b2;
    if (r1 < r2)
        return 1;
    else
        return 0;
}
bool ComplexNum::operator>(const ComplexNum& A) const{
    double a1 = this->a, a2 = A.a;
    double b1 = this->b, b2 = A.b;
    double r1 = a1 * a1 + b1 * b1, r2 = a2 * a2 + b2 * b2;
    if (r1 > r2)
        return 1;
    else
        return 0;
}
bool ComplexNum::operator==(const ComplexNum& A) const{
    double a1 = this->a, a2 = A.a;
    double b1 = this->b, b2 = A.b;
    if (a1 == a2 && b1 == b2)
        return 1;
    else
        return 0;
}

istream& operator>>(istream& is, ComplexNum& A) {
    is >> A.a >> A.b;
    return is;
}









