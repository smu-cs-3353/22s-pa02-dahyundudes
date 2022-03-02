//
// Created by Zachary on 01/23/2022
//

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "catch_setup.h"

int runCatchTests();

int main() {
    return runCatchTests();
}

int runCatchTests()
{
    //This line of code causes the Catch library to
    //run the tests in the project.
    return Catch::Session().run();
}