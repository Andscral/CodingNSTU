#include <iostream>
#include "ComplexNum/ComplexNum.h"
#include "ComplexLife/ComplexLife.h"
#include "ComplexStr/ComplexStr.h"
#include "List/List.h"

using namespace std;

int main() {
    //cout << "from string: ";
    /*char number[] = "1 + 1i";
    ComplexStr string_num(1, 1);
    string_num.from_string(number);
    //string_num.Get();

    //cout << "time: ";
    ComplexLife time_born(1, 3);*/
    //cout << time_born.to_str() << endl;

    //5
    /*ComplexNums num1(1, 2);
    ComplexNums num2(3, 4);

    List list3;
    cout << "str list" << endl;
    list3.adding(string_num);
    list3.showAll(cout);

    cout << "\ntime list" << endl;
    List list4;
    list4.adding(time_born);
    list4.showAll(cout);

    List list1;
    list1.adding(num1);
    list1.adding(num2);
    cout << "list:" << endl;
    list1.showAll(cout);*/

    ComplexNums* obj1 = new ComplexStr();
    ComplexNums* obj2 = new ComplexLife();

    delete obj1;
    delete obj2;

    /*List list;

    ComplexNums n1(1, 2);
    ComplexNums n2(3, 4);
    ComplexNums n3(5, 6);

    list.adding(n1);
    list.adding(n2);
    list.adding(n3);

    list.showAll(cout);
    cout << "1/ 5.00 + 6.00i  3.00 + 4.00i  1.00 + 2.00i  \n\n";

    list.remove(1); // del cn2
    list.showAll(cout);
    cout << "2/ 5.00 + 6.00i  1.00 + 2.00i  \n\n";

    ComplexNums paste_num(2, 7);
    list.paste(paste_num, 1);
    list.showAll(cout);
    cout << "3/ 5.00 + 6.00i  2.00 + 7.00i  1.00 + 2.00i  \n";*/

    return 0;
}
