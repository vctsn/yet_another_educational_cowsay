#include "Cow.hpp"
#include "Parser.hpp"
#include "Field.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    Parser parser(argc, argv);

    // Field сам создаёт корову при своём создании
    Field field(parser);

    field.print();

    return 0;
}