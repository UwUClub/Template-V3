//
// Created by beafowl on 27/06/23.
//

#include "factorial.hpp"

int factorial::factorial_function(int number) // NOLINT(misc-no-recursion)
{
    if (number < 0) {
        return -1;
    }
    if (number == 0) {
        return 1;
    }
    return number <= 1 ? number : factorial_function(number - 1) * number;
}
