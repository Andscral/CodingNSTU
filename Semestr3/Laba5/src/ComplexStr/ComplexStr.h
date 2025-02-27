#pragma once
#ifndef TEST_CATCH_COMPLEXSTR_H
#define TEST_CATCH_COMPLEXSTR_H

#include "ComplexNum/ComplexNum.h"

class ComplexStr : public ComplexNums {
public:
    using ComplexNums::ComplexNums;
    ComplexStr();

    void from_string(const char* string);
    void ShowExtra();

private:
    char* string = ComplexNums::to_string();
};


#endif //TEST_CATCH_COMPLEXSTR_H
