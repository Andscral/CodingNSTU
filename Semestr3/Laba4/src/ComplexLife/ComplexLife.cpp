#include "ComplexLife.h"
#include "ComplexNum/ComplexNum.h"
#include <cstring>

char* ComplexLife::get_time() { return time_str; }

char* ComplexLife::to_str() {
    char* base_str = ComplexNums::to_str();
    char* result = new char[strlen(base_str) + strlen(time_str) + 10];
    sprintf(result, "%s at %s", base_str, time_str);
    delete[] base_str;

    return result;
}