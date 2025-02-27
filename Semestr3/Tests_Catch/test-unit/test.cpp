#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "ComplexNum/ComplexNum.h"

ComplexNums num1(5, 3);
ComplexNums num2(3, 1);

TEST_CASE("Sum test", "[Add]") {
    ComplexNums result = ComplexNums::Add(num1, num2);
    ComplexNums check(8, 4);
    REQUIRE(result == check);
}
TEST_CASE("Minus test", "[Subtract]") {
    ComplexNums result = ComplexNums::Subtract(num1, num2);
    ComplexNums check(2, 2);
    REQUIRE(result == check);
}
TEST_CASE("Multiplication test", "[Multiply]") {
    ComplexNums result = ComplexNums::Multiply(num1, num2);
    ComplexNums check(12, 14);
    REQUIRE(result == check);
}
TEST_CASE("Division test", "[Divide]") {
    ComplexNums result = ComplexNums::Divide(num1, num2);
    ComplexNums check(1.8, 0.4);
    REQUIRE(result == check);
}
TEST_CASE("Operator '=' test", "[operator=]") {
    ComplexNums c1(3, 4);
    ComplexNums c2;
    c2 = c1;
    REQUIRE(c2 == c1);
}
TEST_CASE("Operator '*' test", "[operator*]") {
    ComplexNums result = num1 * num2;
    ComplexNums check(12, 14);
    REQUIRE(result == check);
}
TEST_CASE("Operator '/' test", "[operator/]") {
    ComplexNums result = num1 / num2;
    ComplexNums check(1.8, 0.4);
    REQUIRE(result == check);
}
TEST_CASE("Operator '==/!=' test", "[operator==/operator!=]") {
    ComplexNums c1(3, 4);
    ComplexNums c2(3, 4);
    ComplexNums c3(5, 6);
    REQUIRE(c1 == c2);
    REQUIRE(c1 != c3);
}
TEST_CASE("Trigonometric form test", "[operator()()]") {
    ComplexNums num(5, 3);
    double r = sqrt(5 * 5 + 3 * 3);
    double ugol = atan2(3, 5);
    const char* trigForm = num();
    char buffer[100];
    sprintf(buffer, "Trig. form: %0.2f (cos(%0.2f) + i*sin(%0.2f))", r, ugol, ugol);
    REQUIRE(strcmp(trigForm, buffer) == 0);
}
TEST_CASE("Test >>/<< operators", "[ComplexNums]") {
    ComplexNums num1(3.0, 4.0);
    ComplexNums num2;

    //Оператор вывода
    ostringstream oss;
    oss << num1;
    REQUIRE(oss.str() == "3+4i"); // Проверяем формат вывода

    //Оператор ввода
    istringstream iss("5.0 + 6.0");
    iss >> num2;
    REQUIRE(num2.getA() == 5.0);
    REQUIRE(num2.getB() == 6.0);

    //Тестирование ввода с -мнимой частью
    istringstream issNegative("2.0 - 3.0");
    issNegative >> num2;
    REQUIRE(num2.getA() == 2.0);
    REQUIRE(num2.getB() == -3.0);
}

TEST_CASE("Test save&load binary file", "[ComplexNums]") {
    ComplexNums num1(7.0, -8.0);

    //Сохранение в бинарный файл
    {
        std::ofstream ofs("test.bin", ios::binary);
        num1.saveToBinaryFile(ofs);
        ofs.close();
    }

    ComplexNums num2;

    //Загрузка из бинарного файла
    {
        std::ifstream ifs("test.bin", ios::binary);
        num2.loadToBinaryFile(ifs);
        ifs.close();
    }

    //Проверка: загруженное значение соответствует исходному
    REQUIRE(num1.getA() == num2.getA());
    REQUIRE(num1.getB() == num2.getB());
}