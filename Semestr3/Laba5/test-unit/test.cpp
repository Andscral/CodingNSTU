#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "List/List.h"
#include "ComplexStr/ComplexStr.h"

TEST_CASE("List operations", "[List]") {
    List list;

    ComplexNums* num1 = new ComplexNums(1, 2);
    ComplexNums* num2 = new ComplexNums(3, 4);
    ComplexNums* num3 = new ComplexNums(5, 6);

    SECTION("Adding") {
        list.adding(num1);
        list.adding(num2);
        list.adding(num3);

        REQUIRE(*list.get(0) == *num1);
        REQUIRE(*list.get(1) == *num2);
        REQUIRE(*list.get(2) == *num3);
    }

    SECTION("Remove") {
        list.adding(num1);
        list.adding(num2);
        list.adding(num3);

        list.remove(1); // Удаляем num2

        REQUIRE(*list.get(0) == *num1);
        REQUIRE(*list.get(1) == *num3);
        REQUIRE(list.get(2) == nullptr); // пустой
    }

    SECTION("Paste") {
        list.adding(num1);
        list.adding(num3);

        list.paste(1, num2);

        REQUIRE(*list.get(0) == *num1);
        REQUIRE(*list.get(1) == *num2);
        REQUIRE(*list.get(2) == *num3);
    }

    SECTION("Find") {
        list.adding(num1);
        list.adding(num2);
        list.adding(num3);

        REQUIRE(list.find(num1) == 0);
        REQUIRE(list.find(num2) == 1);
        REQUIRE(list.find(num3) == 2);
        ComplexNums temp(7, 8);
        REQUIRE(list.find(&temp) == -1); // Не найдено
    }

    delete num1;
    delete num2;
    delete num3;
}