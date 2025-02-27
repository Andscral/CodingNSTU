#include <iostream>
#include "Imaginary.h"

int main() {
    Imaginary A;
    Imaginary B;
    A.Set(1.2,5);
    B.Set(3,4);
    Imaginary Result;
    Result = Result.sum(A, B);
    Result.Get();
    cout << Result.to_string() << endl;

    Result = Result.substruct(A, B);
    Result.Get();

    Result = Result.multiplicate(A, B);
    Result.Get();

    Result = Result.divide(A, B);
    Result.Get();
}
