#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;

class ComplexNum {
public:
    ComplexNum(double Real, double Imag);
    ComplexNum(double Real);
    ComplexNum();
    ComplexNum(const ComplexNum& other);
    ~ComplexNum();

    void Get();
    double getR();
    double getI();
    void Set(double R, double I);

    //������ � ������
    char* to_string();

    //������� ���������
    ComplexNum static sum(ComplexNum A, ComplexNum B);
    ComplexNum static substruct(ComplexNum A, ComplexNum B);
    ComplexNum static multiplicate(ComplexNum A, ComplexNum B);
    ComplexNum static divide(ComplexNum& A, ComplexNum B);

    //������������� ���������
    ComplexNum operator+(ComplexNum& A);
    ComplexNum operator-(ComplexNum& A);
    ComplexNum operator*(ComplexNum& A);
    ComplexNum operator/(ComplexNum& A);

    //���������
    bool operator<(const ComplexNum& A) const;
    bool operator>(const ComplexNum& A) const;
    bool operator==(const ComplexNum& A) const;

    //���� � �����
    friend ostream& operator<<(ostream& os, const ComplexNum& A);
    friend istream& operator>>(istream& is, ComplexNum& A);

protected:
    double a, b;
};


