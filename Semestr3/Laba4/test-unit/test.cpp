#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "ComplexNum/ComplexNum.h"
#include "List/List.h"

TEST_CASE("List operations", "[List]") {

    ComplexNums n1(1, 2);
    ComplexNums n2(3, 4);
    ComplexNums n3(5, 6);

    SECTION("Show all") {
        List list;
        list.adding(n1);
        list.adding(n2);
        list.adding(n3);

        ostringstream oss;
        list.showAll(oss);
        REQUIRE(oss.str() == "5.00 + 6.00i  3.00 + 4.00i  1.00 + 2.00i  \n");
    }
    SECTION("Search") {
        List list;
        list.adding(n1);
        list.adding(n2);
        list.adding(n3);

        REQUIRE(list.find(n1) == 2);
        REQUIRE(list.find(n2) == 1);
        REQUIRE(list.find(n3) == 0);
    }
    SECTION("Remove") {
        List list;
        list.adding(n1);
        list.adding(n2);
        list.adding(n3);

        ostringstream oss;
        list.remove(1); // del cn2
        list.showAll(oss);
        REQUIRE(oss.str() == "5.00 + 6.00i  1.00 + 2.00i  \n");
    }
    SECTION("Paste") {
        List list;
        list.adding(n1);
        list.adding(n3);

        ostringstream oss;
        ComplexNums paste_num(2, 7);
        list.paste(paste_num, 1);
        list.showAll(oss);
        REQUIRE(oss.str() == "5.00 + 6.00i  2.00 + 7.00i  1.00 + 2.00i  \n");
    }
}

