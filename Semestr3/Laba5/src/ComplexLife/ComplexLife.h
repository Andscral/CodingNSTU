#ifndef TEST_CATCH_COMPLEXLIFE_H
#define TEST_CATCH_COMPLEXLIFE_H

#include "ComplexNum/ComplexNum.h"

class ComplexLife : public ComplexNums {

public:
    using ComplexNums::ComplexNums;

    char* get_time();

    void ShowExtra();

private:
    time_t current_time = time(nullptr);
    char* time_str = ctime(&current_time);
};


#endif //TEST_CATCH_COMPLEXLIFE_H
