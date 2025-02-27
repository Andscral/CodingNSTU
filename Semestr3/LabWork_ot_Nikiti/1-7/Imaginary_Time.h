#include "Imaginary.h"
class Imaginary_Time :public Imaginary {
public:
    using Imaginary::Imaginary;

    char* get_time();

    void ShowExtra();

private:
    time_t current_time = time(nullptr);
    char* time_str = ctime(&current_time);
};