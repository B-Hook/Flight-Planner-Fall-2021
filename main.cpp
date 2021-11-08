/**
 * Fall 2021 PA 04 - Flight Planner Template Repo.
 * Based on PA 02 Template repo
 */
#include "Control.h"
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
        Control c (argv[1], argv[2], argv[3]); // Calling control to walk through the program
    }
    return 0;
}