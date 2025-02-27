#pragma once

#include <cmath>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;
class ComplexNums {
public:
    ComplexNums(double _a, double _b);
    ComplexNums(double _a);
    ComplexNums();
    ~ComplexNums();

    ComplexNums(const ComplexNums &obj);

    double getA() const;
    double getB() const;
    void setA(double _a);
    void setB(double _b);

    void Set(double r, double i);
    void Get();

    static ComplexNums Add(ComplexNums &num1, ComplexNums &num2);
    static ComplexNums Subtract(ComplexNums &num1, ComplexNums &num2);
    static ComplexNums Multiply(const ComplexNums &num1,const ComplexNums &num2);
    static ComplexNums Divide(ComplexNums& A, ComplexNums B);

    ComplexNums& operator=(const ComplexNums& obj);
    friend ComplexNums operator*(const ComplexNums& num1, const ComplexNums& num2);
    ComplexNums operator/(const ComplexNums& A);

    bool operator<(ComplexNums& A);
    bool operator>(ComplexNums& A);
    bool operator==( ComplexNums& A) ;

    char* to_string();

    friend ostream& operator<< (ostream& os, const ComplexNums& num);
    friend istream& operator>> (istream& is, ComplexNums& num);

protected:
    double a, b;
};

