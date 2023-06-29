//
// Created by beafowl on 27/06/23.
//

#include "factorial.hpp"
#include <iostream>
#include <span>

int main(int argc, char** argv) {
    (void)argc;
    factorial facto;
    auto args = std::span(argv, size_t(argc));
    const int ret = facto.factorial_function(std::stoi(args[1]));
    std::cout << ret << std::endl;
}
