#include <iostream>
#include <fstream>
#include "Imaginary.h"
#include "Imaginary_String.h"
#include "Imaginary_Time.h"
#include "list.h"

int main() {
    Imaginary A(1.2, 5);
    Imaginary B(3, 4);
    Imaginary Result(0, 0);

    // обычные операции

    /*
    Result = Result.sum(A, B);
    Result.Get();
    cout << Result.to_string() << endl;

    Result = Result.substruct(A, B);
    Result.Get();

    Result = Result.multiplicate(A, B);
    Result.Get();

    Result = Result.divide(A, B);
    Result.Get();
    cout << "\n" << endl;
    */

    // перегруженные
    //Result = A + B;
    //Result.Get();

    //Result = A - B;
    //Result.Get();

    //Result = A * B;
    //Result.Get();

    //Result = A / B;
    //Result.Get();

   // cout << ">   " << char(int(A > B) + 48) << endl;
    //cout << "<   " << char(int(A < B) + 48) << endl;

    //cout << Result.to_tstr() << endl;
    /*
    Imaginary  C;
    cin >> C;
    cout << C << endl;
    */
    /* Запись в файл
    ofstream outFile("1.txt");
    if (outFile) {
        outFile << A << endl;
        outFile.close();
    }
    else {
        cout << "Error" << endl;
    }
    // Чтение из файла
    ifstream inFile("1.txt");
    if (inFile) {
        inFile >> C;
        inFile.close();
        cout << C << endl;
    }
    else {
        cout << "Error" << endl;
    }
    cout << " " << endl;
    // Запись в двоичный файл
    cout << "filework" << endl;
    ofstream outFileDat("2.dat", ios::binary);
    if (outFileDat) {
        A.ToDataFile(outFile);
        outFileDat.close();
    }
    else {
        cout << "Error" << endl;
    }
    // Чтение двоичного файла
    ifstream inFileDat("2.dat", ios::binary);
    if (inFileDat) {
        C.FromDataFile(inFile);
        inFileDat.close();
        cout << C << std::endl;
    }
    else {
        cout << "Error" << endl;
    }
    */
    cout << "from string:" << endl;
    char number[] = "1 + 1i";
    Imaginary_String IS(1, 1);
    IS.from_string(number);
    IS.Get();

    cout << "time:" << endl;

    Imaginary_Time IT(1, 3);
    cout << IT.get_time() << endl;

    list<Imaginary_String> List3;
    cout << "str list" << endl;
    List3.pushEnd(IS);
    List3.show(0);
    cout << "time list" << endl;
    list<Imaginary_Time> List4;
    List4.pushEnd(IT);
    List4.show(0);


    cout << endl;
    cout << "list: " << endl;
    list<Imaginary> list_1;
    list_1.pushEnd(A);
    list_1.pushEnd(B);
    list_1.pushEnd(IT);
    list_1.pushEnd(IS);
    list_1.showAll(cout);

    cout << endl;
    int a = 1;
    int b = 2;
    list<int> list_int;
    list_int.pushEnd(a);
    list_int.pushEnd(b);
    list_int.showAll(cout);

    cout << endl;
    double a1 = 1.0;
    double b1 = 2.0;
    list<double> list_double;
    list_double.pushEnd(a1);
    list_double.pushEnd(b1);
    list_double.showAll(cout);

    // ошибки
    try {
        cout << "division:" << endl;
        Imaginary test_a(1, 1);
        Imaginary test_b(0, 0);
        test_a / test_b;
    }
    catch (string error_type) { cerr << "error type: " << error_type << endl; }

    try {
        cout << "overflow:" << endl;
        list<Imaginary> list_2;
        list_2.pushEnd(A);
        list_2.show(100);
    }
    catch (string error_type) { cerr << "error type: " << error_type << endl; }
    cout << "end";
}