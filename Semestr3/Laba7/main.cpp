#include <iostream>
#include <stdexcept>
#include "List.h"
#include "ComplexNum.h"

using namespace std;

int main() {
    ComplexNums A(1, 5);
    ComplexNums B(3, 4);
    ComplexNums Result(0, 0);

    int a = 1;
    int b = 2;
    List<int> list_int;
    list_int.adding(a);
    list_int.adding(b);
    list_int.showAll(cout);

    double a1 = 1.1;
    double b1 = 2.1;
    List<double> list_double;
    list_double.adding(a1);
    list_double.adding(b1);
    list_double.showAll(cout);

    cout << "list: " << endl;
    List<ComplexNums> list_1;
    list_1.adding(A);
    list_1.adding(B);
    list_1.showAll(cout);

    try {
        cout << "division:" << endl;
        ComplexNums test_a(1, 1);
        ComplexNums test_b(0, 0);
        test_a / test_b;
    }
    catch (const underflow_error& error_type) {
        cerr << "error type: " << error_type.what() << endl;
    }

    try {
        cout << "overflow:" << endl;
        List<ComplexNums> list_2;
        list_2.adding(A);
        list_2.show(100);
    }
    catch (const overflow_error& error_type) {
        cerr << "error type: " << error_type.what() << endl;
    }
    cout << "end";

    return 0;
}