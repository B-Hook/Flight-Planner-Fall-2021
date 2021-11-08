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
#include "DSStack.h"
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
    SECTION("Testing Insert"){
        test1.currToFront();
        int count = 0;
        while (count < 5){
            test1.currToNext();
            count ++;
        }
        test1.insert(20);
        test1.currToPrev();
        REQUIRE(test1.getCurrVal() == 20);
        test1.currToPrev();
        REQUIRE(test1.getCurrVal() == 4);
        test1.currToNext();
        test1.currToNext();
        REQUIRE(test1.getCurrVal() == 5);
        test2.currToFront();
        test2.insert(30);
        test2.currToFront();
        REQUIRE(test2.getCurrVal() == 30);
        test2.currToBack();
        test2.insert(50);
        test2.currToPrev();
        REQUIRE(test2.getCurrVal() == 50);
    }
    SECTION("Testing Remove"){
        test1.remove();
        REQUIRE(test1.getTailVal() == 8);
        LinkedList<int> test4;
        test4.append(4);
        test4.remove();
        REQUIRE(test4.checkEmpty() == true);
    }
    SECTION("Testing Clear"){
        test1.clear();
        REQUIRE(test1.checkEmpty() == true);
        test3.clear();
        REQUIRE(test3.checkEmpty() == true);
    }
    SECTION("Testing currToFront") {
        test1.currToFront();
        REQUIRE(test1.getCurrVal() == 0);
        test3.currToFront();
        REQUIRE(test3.isCurrNull() == true);
    }
    SECTION("Testing currToBack") {
        test1.currToBack();
        REQUIRE(test1.getCurrVal() == 9);
        test3.currToBack();
        REQUIRE(test3.isCurrNull() == true);
    }
    SECTION("Testing currToNext") {
        test1.currToFront();
        test1.currToNext();
        REQUIRE(test1.getCurrVal() == 1);
        test3.append(2);
        test3.currToFront();
        test3.currToNext();
        REQUIRE(test3.isCurrNull() == true);
    }
    SECTION("Testing currToPrev") {
        test1.currToBack();
        test1.currToPrev();
        REQUIRE(test1.getCurrVal() == 8);
        test3.append(2);
        test3.currToBack();
        test3.currToPrev();
        REQUIRE(test3.isCurrNull() == true);
    }
    SECTION("Testing getCurrVal"){
        test1.currToFront();
        test1.currToNext();
        REQUIRE(test1.getCurrVal() == 1);
    }
    SECTION("Testing getTailVal"){
        REQUIRE(test1.getTailVal() == 9);
        test3.append(1);
        REQUIRE(test3.getTailVal() == 1);
    }
    SECTION("Testing checkEmpty"){
        REQUIRE(test3.checkEmpty() == true);
        REQUIRE(test1.checkEmpty() == false);
    }
    SECTION("Testing isCurrNull"){
        REQUIRE(test1.isCurrNull() == true);
        test1.currToFront();
        REQUIRE(test1.isCurrNull() == false);
        test1.currToPrev();
        REQUIRE(test1.isCurrNull() == true);
    }
}
TEST_CASE("Testing DSStack"){

    DSStack<int> test1;
    DSStack<int> test2;

    for (int i = 0; i < 10; i++){
        test1.push(i);
    }

    SECTION("Testing push"){
        test1.push(15);
        REQUIRE(test1.peek() == 15);
        REQUIRE(test1.peek() != 10);
        test2.push(20);
        REQUIRE(test2.peek() == 20);
        REQUIRE(test2.peek() != 25);
    }
    SECTION("Testing pop"){
        test1.pop();
        REQUIRE(test1.peek() == 8);
        REQUIRE(test1.peek() != 9);
        test2.push(20);
        test2.pop();
        REQUIRE(test2.isEmpty() == true);
        REQUIRE(test2.isEmpty() != false);
    }
    SECTION("Testing peek"){
        REQUIRE(test1.peek() == 9);
    }
    SECTION("Testing isEmpty"){
        REQUIRE(test1.isEmpty() == false);
        REQUIRE(test1.isEmpty() != true);
        REQUIRE(test2.isEmpty() == true);
        REQUIRE(test2.isEmpty() != false);
    }
}