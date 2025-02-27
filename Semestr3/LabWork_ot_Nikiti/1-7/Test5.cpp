#define CATCH_CONFIG_MAIN
#include <catch2\catch.hpp>
#include "Imaginary.h"
#include "Imaginary_String.h"
#include "Imaginary_Time.h"
#include "list.h"

/*
TEST_CASE("Imaginary") {
    Imaginary a(3.0, 4.0);
    Imaginary b(1.0, -2.0);

    SECTION("Constructor") {
        REQUIRE(a.getR() == 3.0);
        REQUIRE(a.getI() == 4.0);
        REQUIRE(b.getR() == 1.0);
        REQUIRE(b.getI() == -2.0);
    }

    SECTION("Operations") {
        Imaginary sum = a + b;
        REQUIRE(sum.getR() == 4.0);
        REQUIRE(sum.getI() == 2.0);

        Imaginary diff = a - b;
        REQUIRE(diff.getR() == 2.0);
        REQUIRE(diff.getI() == 6.0);

        Imaginary prod = a * b;
        REQUIRE(prod.getR() == 11.0);
        REQUIRE(prod.getI() == -2.0);

        Imaginary div = a / b;
        REQUIRE(div.getR() == -1.0);
        REQUIRE(div.getI() == -2.0);
    }

    SECTION("Comparison") {
        REQUIRE(a > b);
        REQUIRE(b < a);
    }

    SECTION("String") {
        char* str = a.to_string();
        REQUIRE(string(str) == "3.00 + 4.00i");
    }
}
*/


TEST_CASE("Imaginary_String") {
    Imaginary_String strObj;
    strObj.from_string("5 + 6i");

    SECTION("String to Imaginary") {
        REQUIRE(strObj.getR() == 5.0);
        REQUIRE(strObj.getI() == 6.0);
    }
}

TEST_CASE("Imaginary_Time") {
    Imaginary_Time timeObj;

    SECTION("Time") {
        char* timeStr = timeObj.get_time();
        REQUIRE(timeStr != nullptr);
        REQUIRE(strlen(timeStr) > 0);
    }
}


TEST_CASE("List int") {
    int a = 1;
    int b = 2;
    int c = 3;

    list<int> myList;
    myList.push(a, 0);
    myList.push(b, 1);
    myList.push(c, 2);

    SECTION("Show all elements") {
        ostringstream oss;
        myList.showAll(oss);
        REQUIRE(oss.str() == "1  2  3\n");
    }
}

TEST_CASE("List pushEnd and show") {
    Imaginary A(1, 0);
    Imaginary B(2, 1);
    Imaginary C(3, 2);

    list<Imaginary> myList;
    myList.pushEnd(A);
    myList.pushEnd(B);
    myList.pushEnd(C);

    SECTION("Show all elements") {
        ostringstream oss;
        myList.showAll(oss);
        REQUIRE(oss.str() == "1  2 +1i  3 +2i\n");
    }
}