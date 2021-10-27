/**
 * Fall 2021 PA 04 - Flight Planner Template Repo.
 * Based on PA 02 Template repo
 */

#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "DSStack.h"

/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"

int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        std::cout << "Hello, 2341 students!" << std::endl;
        std::cout << "Attempting to open and write to " << argv[2] << std::endl;
        std::ofstream o(argv[3]);
        o << "Writing to output file." << std::endl;
        o.close();
    }

    LinkedList<int> test;
    LinkedList<int> test1;
    LinkedList<int> test2;
    DSStack<int> stack;

    for (int i = 0; i < 10; i++)
        test.append(i);

    for (int i = 0; i < 5; i++)
        test1.append(i);
    test.currToFront();
    for (int i = 0; i < test.getLength(); i++){
        stack.push(test.getCurrVal());
        test.currToNext();
        //stack.pop();
    }
    //test.clear();
    for (int i = 1; i < test.getLength(); i++){
        std::cout << stack.peek() << std::endl;
        stack.pop();
    }

    test = test1;
    test2 = test;


    return 0;
}