//
// Created by MARK FONTENOT on 9/14/21.
//

/**
 * This file contains some simple tests.
 *
 * DO NOT add the #define CATCH_CONFIG_RUNNER to this file.
 * It is already in catch_setup.cpp
 *
 * Note that you can have more than one cpp file with tests in them.
 * For example, you could have a test file for your DSString and a
 * separate one for your DSVector.
 */

#include "catch.hpp"
#include "LinkedList.h"

TEST_CASE("Testing Tests", "[multiplication]") {
    REQUIRE((2 * 2) == 4);
    REQUIRE((1 * 5) == 5);
}
TEST_CASE("Testing LinkedList"){
    LinkedList<int> test1;
    LinkedList<int> test2;
    LinkedList<int> test3;
    for (int i = 0; i < 10; i++)
        test1.append(i);

    for (int i = 0; i < 5; i++)
        test2.append(i);

    SECTION("Testing copy constructor"){
        test3 = test1;
        test1.currToFront();
        test3.currToFront();
        int i = 0;
        while (i < 10){
            REQUIRE(test3.getCurrVal() == test1.getCurrVal());
            test1.currToNext();
            test3.currToNext();
            i++;
        }
    }
    SECTION("Testing copy assignment operator"){
        test1 = test2;
        test1.currToFront();
        test2.currToFront();
        int i = 0;
        while (i < 5){
            REQUIRE(test2.getCurrVal() == test1.getCurrVal());
            test1.currToNext();
            test2.currToNext();
            i++;
        }
    }
    SECTION("Testing Append"){
        test1.append(20);
        test3.append(5);
        REQUIRE(test1.getTailVal() == 20);
        REQUIRE(test3.getTailVal() == 5);
    }
    SECTION("Testing Remove"){
        test1.remove();
        REQUIRE(test1.getTailVal() == 8);
    }
    //SECTION("Testing Clear"){
        //test1.clear();
        //REQUIRE(test1.getTailVal() == NULL);
    //}
    SECTION("Check Next"){
        test1.currToFront();
        REQUIRE(test1.checkNext() == true);
        int i = 0;
        while(i < 9) {
            test1.currToNext();
            i++;
        }
        REQUIRE(test1.checkNext() == false);

    }
}