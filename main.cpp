#include <iostream>

#include "parser.hpp"

using namespace std;

int main(int argc, char *argv[]){
    
    std::cout << "Starting..." << std::endl;

    Parser parser(argv[1]);

    return EXIT_SUCCESS;
}