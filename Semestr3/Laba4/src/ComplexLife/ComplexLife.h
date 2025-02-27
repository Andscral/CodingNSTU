#ifndef TEST_CATCH_COMPLEXLIFE_H
#define TEST_CATCH_COMPLEXLIFE_H

#include "ComplexNum/ComplexNum.h"

class ComplexLife : public ComplexNums {

public:
    using ComplexNums::ComplexNums;
    ~ComplexLife() {cout << __FUNCTION__ << endl;
        delete[] time_str;
    }

    char* get_time();

    char* to_str();

private:
    time_t current_time = time(nullptr);
    char* time_str = ctime(&current_time);
};


#endif //TEST_CATCH_COMPLEXLIFE_H
