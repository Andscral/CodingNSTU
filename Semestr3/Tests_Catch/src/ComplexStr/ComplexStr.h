#ifndef TEST_CATCH_COMPLEXSTR_H
#define TEST_CATCH_COMPLEXSTR_H

#include "ComplexNum/ComplexNum.h"

class ComplexStr : public ComplexNums {
public:
    ComplexStr(const char* str);
    void strToComplex();
    const char* complexToStr(const ComplexNums &num1);
    void getStr() const;
private:
    char str[100];
};


#endif //TEST_CATCH_COMPLEXSTR_H
