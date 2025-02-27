#ifndef TEST_CATCH_COMPLEXLIFE_H
#define TEST_CATCH_COMPLEXLIFE_H

#include "ComplexNum/ComplexNum.h"
#include <ctime>

class ComplexLife : public ComplexNums {

public:
    ComplexLife(double _a, double _b);
    void getDate() const;
private:
    time_t Date;
};


#endif //TEST_CATCH_COMPLEXLIFE_H
