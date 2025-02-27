#pragma once

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;
class ComplexNums {
public:
    ComplexNums(double _a, double _b);
    ComplexNums(double _a);
    ComplexNums();
    virtual ~ComplexNums() {cout << __FUNCTION__ << endl; };

    ComplexNums(const ComplexNums &obj);

    double getA() const;
    double getB() const;
    void setA(double _a);
    void setB(double _b);

    void Set(double r, double i);
    void Get();

    bool operator<(ComplexNums& A);
    bool operator>(ComplexNums& A);
    bool operator==( ComplexNums& A) ;

    char* to_string();

    virtual char* to_str();

    friend ostream& operator<< (ostream& os, ComplexNums& num);
    friend istream& operator>> (istream& is, ComplexNums& num);

protected:
    double a, b;
};

