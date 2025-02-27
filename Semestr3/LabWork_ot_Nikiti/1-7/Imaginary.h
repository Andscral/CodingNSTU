#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;

class Imaginary {
public:
    Imaginary(double Real, double Imag);
    Imaginary(double Real);
    Imaginary();
    Imaginary(const Imaginary& other);
    ~Imaginary();

    void Get();
    double getR();
    double getI();
    double getA();
    double getr();
    void Set(double R, double I);
    void setAlpha(double alpha);
    void setR(double r);

    //Запись в строку
    char* to_string();
    char* to_tstr();

    //Обычные операторы
    Imaginary static sum(Imaginary A, Imaginary B);
    Imaginary static substruct(Imaginary A, Imaginary B);
    Imaginary static multiplicate(Imaginary A, Imaginary B);
    Imaginary static divide(Imaginary& A, Imaginary B);

    //Перегруженные операторы
    Imaginary operator+(Imaginary& A);
    Imaginary operator-(Imaginary& A);
    Imaginary operator*(Imaginary& A);
    Imaginary operator/(Imaginary& A);

    //Сравнение
    bool operator<(Imaginary& A);
    bool operator>(Imaginary& A);
    bool operator==(Imaginary& A);

    void operator()(void);

    //Работа с двоичным файлом
    void ToDataFile(ofstream& ofs) const;
    void FromDataFile(ifstream& ifs);

    virtual void ShowExtra();

    //Ввод и вывод
    friend ostream& operator<<(ostream& os, const Imaginary& A);
    friend istream& operator>>(istream& is, Imaginary& A);

protected:
    double Real, Imag;
    double Alpha, R;
};


