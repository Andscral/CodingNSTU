#include "ComplexNum/ComplexNum.h"
#include "ComplexStr/ComplexStr.h"
#include "ComplexLife/ComplexLife.h"

using namespace std;

int main() {
    ComplexNums complex1(5, 3);
    //ComplexNums compex2(3, 1);
    ComplexLife num1(5, 3);
    ComplexStr num3("2 + 3i");
    ComplexStr num4(" ");

    //вывод из числа в строку
    cout << "convert comp->str: ";
    cout << num4.complexToStr(complex1) << endl;

    //дата создания
    cout << "Printing ComplexWithDate: ";
    num1.getDate();
    cout << endl;

    //вывод строки
    num3.getStr();
    cout << endl;

    //из строки в число
    cout << "convert str->comp: ";
    num3.strToComplex();
    cout << endl;

    //cout << "Number one: " << compex1 << endl;
    //cout << "Number two: " << compex2 << endl;

    //лаба 1
    /*ComplexNums sum = ComplexNums::Add(compex1, compex2);
    ComplexNums minus = ComplexNums::Subtract(compex1, compex2);
    ComplexNums mult = ComplexNums::Multiply(compex1, compex2);
    ComplexNums div = ComplexNums::Divide(compex1, compex2);

    cout << "Result <+>: " << sum.c_str() << endl;
    cout << "Result <->: " << minus.c_str() << endl;
    cout << "Result <*>: " << mult.c_str() << endl;
    cout << "Result </>: " << div.c_str() << endl;*/

    //лаба 2
    /*ComplexNums mult = compex1 * compex2;
    ComplexNums div = compex1 / compex2;
    bool number = (compex1 == compex2);

    cout << "Multiplier: " << mult << endl;
    cout << "Division: " << div << endl;
    cout << "Ravnie?: " << (number ? "yes" : "no") << endl;

    cout << compex1() << endl;*/

    //лаба 3
    /*cout << "\n3 lab" << endl;
    ofstream outFile("ComplexUsual.txt");   //в файл
    if (outFile) {
        outFile << compex1 << endl;
        outFile.close();
    }
    else {
        cout << "Error save" << endl;
    }

    ifstream inFile("ComplexUsual.txt");    //из файла
    if (inFile) {
        inFile >> compex1;
        inFile.close();
        cout << "Load usual: " << compex1 << endl;
    }
    else {
        cout << "Error load" << endl;
    }

    //в двоичный save
    ofstream outFileBin("ComplexBin.bin", ios::binary);
    if (outFileBin) {
        compex1.saveToBinaryFile(outFileBin);
        outFileBin.close();
    }
    else {
        cout << "Error save bin" << endl;
    }
    // двоичного load
    ifstream inFileBin("ComplexBin.bin", ios::binary);
    if (inFileBin) {
        compex1.loadToBinaryFile(inFileBin);
        inFileBin.close();
        cout << "Load Bin: " << compex1 << endl;
    }
    else {
        cout << "Error load bin" << endl;
    }*/

    return 0;
}
