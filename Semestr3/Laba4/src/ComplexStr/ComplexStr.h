#pragma once
#ifndef TEST_CATCH_COMPLEXSTR_H
#define TEST_CATCH_COMPLEXSTR_H

#include "ComplexNum/ComplexNum.h"
#include <iostream>

class ComplexStr : public ComplexNums {
public:
    using ComplexNums::ComplexNums;
    ComplexStr();
    ~ComplexStr() {cout << __FUNCTION__ << endl;
        delete[] string;
    }

    void from_string(const char* string);

    char* to_str();

private:
    char* string = ComplexNums::to_string();
};


#endif //TEST_CATCH_COMPLEXSTR_H
