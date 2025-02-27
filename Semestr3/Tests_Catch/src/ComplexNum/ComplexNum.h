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
    ~ComplexNums();

    ComplexNums(const ComplexNums &obj);

    double getA() const;
    double getB() const;
    void setA(double _a);
    void setB(double _b);

    char* c_str() {
        int size = floor(log10(abs(a))) + floor(log10(abs(b)))+13;
        char* s = new char[size+1];
        if (b >= 0) { sprintf(s, "%0.2f + %0.2fi", a, b); }
        else { sprintf(s, "%0.2f - %0.2fi", a, -b); }
        return s;
    }

    static ComplexNums Add(ComplexNums &num1, ComplexNums &num2);
    static ComplexNums Subtract(ComplexNums &num1, ComplexNums &num2);
    static ComplexNums Multiply(const ComplexNums &num1,const ComplexNums &num2);
    static ComplexNums Divide(const ComplexNums &num1, const ComplexNums &num2);

    //2 лаба
    ComplexNums& operator=(const ComplexNums& obj);
    friend ComplexNums operator*(const ComplexNums& num1, const ComplexNums& num2);
    ComplexNums operator/(const ComplexNums& obj) const;
    bool operator==(const ComplexNums& obj) const;
    bool operator!=(const ComplexNums& obj) const;
    const char * operator()() const;

    //3 лаба
    friend ostream& operator<< (ostream& os, const ComplexNums& num);
    friend istream& operator>> (istream& is, ComplexNums& num);

    void saveToBinaryFile(ofstream& ofs) const;
    void loadToBinaryFile(ifstream& ifs);

//поменять стиль. Методы - глаголы.
private:
    double a, b;
};

