#pragma once
#include "Imaginary.h"

Imaginary::Imaginary(double Real, double Imag) : Real(Real), Imag(Imag) {
    Alpha = 0;
    R = sqrt(Real * Real + Imag * Imag);
}

Imaginary::Imaginary(double Real) : Imaginary(Real, 0) {}

Imaginary::Imaginary() : Imaginary(0, 0) {}

Imaginary::Imaginary(const Imaginary& other) : Imaginary(other.Real, other.Imag) {}


Imaginary::~Imaginary() {}

void Imaginary::Get() {
    if (Imag > 0) {
        cout << Real << " + " << Imag << "i" << endl;
    } else {
        cout << Real << endl;
    }
}

double Imaginary::getR() { return Real; }
double Imaginary::getI() { return Imag; }
double Imaginary::getA() { return Alpha; }
double Imaginary::getr() { return R; }

void Imaginary::Set(double R, double I) {
    Real = R;
    Imag = I;
}

void Imaginary::setAlpha(double alpha) { Alpha = alpha; }
void Imaginary::setR(double r) { R = r; }

char* Imaginary::to_string() {
    int n = floor(log10(abs(Real))) + floor(log10(abs(Imag))) + 13;
    char* string = new char[n];
    if (Imag > 0) {
        sprintf_s(string, n, "%0.2f + %0.2fi", Real, Imag);
    }
    else if (Imag == 0) {
        sprintf_s(string, n, "%0.2f", Real);
    }
    else {
        sprintf_s(string, n, "%0.2f - %0.2fi", Real, Imag);
    }
    return string;
}

char* Imaginary::to_tstr() {

    double r = this->getR();
    double alpha = this->getA();
    int n = floor(log10(abs(r))) + 40;
    char* s = new char[n];
    sprintf_s(s, n, "%0.2f(cos%0.2f + isin%0.2f)", r, alpha, alpha);
    return s;
}
Imaginary Imaginary::sum(Imaginary A, Imaginary B) {
    double new_real = A.Real + B.Real;
    double new_imaginary = A.Imag + B.Imag;
    Imaginary C(new_real, new_imaginary);
    return C;
}
Imaginary Imaginary::substruct(Imaginary A, Imaginary B) {
    double new_real = A.Real - B.Real;
    double new_imaginary = A.Imag - B.Imag;
    Imaginary C(new_real, new_imaginary);
    return C;
}
Imaginary Imaginary::multiplicate(Imaginary A, Imaginary B) {
    double new_real = A.Real * B.Real - A.Imag * B.Imag;
    double new_imaginary = A.Imag * B.Real + A.Real * B.Imag;
    Imaginary C(new_real, new_imaginary);
    return C;
}
Imaginary Imaginary::divide(Imaginary& A, Imaginary B) {
    double divider = (B.Real * B.Real + B.Imag * B.Imag);
    if (divider) {
        double new_real = (A.Real * B.Real + A.Imag * B.Imag) / divider;
        double new_imaginary = (A.Imag * B.Real - A.Real * B.Imag) / divider;
        Imaginary C(new_real, new_imaginary);
        return C;
    }
    else { throw string{ "division by 0" }; }
    
}


Imaginary Imaginary::operator+(Imaginary& A) {
    double real = this->Real + A.Real;
    double imag = this->Imag + A.Imag;
    return Imaginary(real, imag);
}
Imaginary Imaginary::operator-(Imaginary& A) {
    double real = this->Real - A.Real;
    double imag = this->Imag - A.Imag;
    return Imaginary(real, imag);
}
Imaginary Imaginary::operator*(Imaginary& A) {
     double real = this->Real * A.Real - this->Imag * A.Imag;
    double imag = this->Imag * A.Real + this->Real * A.Imag;
    return Imaginary(real, imag);
}
Imaginary Imaginary::operator/(Imaginary& A) {
    double divider = (A.Real * A.Real + A.Imag * A.Imag);
    if (divider) {
        double real = (this->Real * A.Real + this->Imag * A.Imag) / divider;
        double imag = (this->Imag * A.Real - this->Real * A.Imag) / divider;
        return Imaginary(real, imag);
    }
    else { throw string{ "division by 0" }; }
}
bool Imaginary::operator<(Imaginary& A) {
    double a1 = this->Real, a2 = A.Real;
    double b1 = this->Imag, b2 = A.Imag;
    double r1 = a1 * a1 + b1 * b1, r2 = a2 * a2 + b2 * b2;
    if (r1 < r2)
        return 1;
    else
        return 0;
}
bool Imaginary::operator>(Imaginary& A) {
    double a1 = this->Real, a2 = A.Real;
    double b1 = this->Imag, b2 = A.Imag;
    double r1 = a1 * a1 + b1 * b1, r2 = a2 * a2 + b2 * b2;
    if (r1 > r2)
        return 1;
    else
        return 0;
}
bool Imaginary::operator==(Imaginary& A) {
    double a1 = this->Real, a2 = A.Real;
    double b1 = this->Imag, b2 = A.Imag;
    if (a1 == a2 && b1 == b2)
        return 1;
    else
        return 0;
}

void Imaginary::operator()(void) {

    double Real = this->getR();
    double Imag = this->getI();
    double R = sqrt(Real * Real + Imag * Imag);

    setR(R);

    if (Imag >= 0) {
        setAlpha(acos(Real / R));
    }
    else {
        setAlpha(acos(-Real / R) + 3.14);
    }
}

void Imaginary::ToDataFile(std::ofstream& ofs) const {
    ofs.write((const char*)(this), sizeof(Imaginary));
}
void Imaginary::FromDataFile(std::ifstream& ifs) {
    ifs.read((char*)(this), sizeof(Imaginary));
}

void Imaginary::ShowExtra() { cout << "Base class" << endl; }

ostream& operator<<(ostream& os, const Imaginary& A) {
    if (A.Imag != 0) {
        os  << A.Real << " " << showpos << A.Imag << 'i' << noshowpos;
    } else {
        os << A.Real;
    }
    return os;
}


istream& operator>>(istream& is, Imaginary& A) {
    is >> A.Real >> A.Imag;
    return is;
}









