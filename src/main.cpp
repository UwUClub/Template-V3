//
// Created by beafowl on 27/06/23.
//

#include <iostream>
#include <string.h>
#include "sparse_array.hpp"
#include "entity.hpp"

struct Position {
    int x;
    int y;
};

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    entity ett(42);

    Position pos = { 42, 67 };
    sparse_array<Position> spa = sparse_array<Position>();
    std::cout << spa.size() << std::endl;
    spa.insert_at(ett, pos);
    std::cout << spa.size() << std::endl;
    return 0;
}
