#pragma once
#include "Imaginary.h"
class Imaginary_String :public Imaginary {
public:
    using Imaginary::Imaginary;
    Imaginary_String();

    void from_string(const char* string);

    void ShowExtra() ;

private:
    char* String = Imaginary::to_string();
};