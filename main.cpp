#include <iostream>

#include "parser.hpp"

using namespace std;

int main(int argc, char *argv[]){
    
    if (argc != 2) {
        cout << "Usage <program> <file>" << endl;
        return EXIT_FAILURE;
    }

    std::cout << "Starting..." << std::endl;

    Parser parser(argv[1]);

    return EXIT_SUCCESS;
}