#include <iostream>

#include "parser.hpp"
#include "button.hpp"

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 2) {
        cout << "Usage <program> <file>" << endl;
        return EXIT_FAILURE;
    }

    std::cout << "Starting..." << std::endl;

    Parser parser(argv[1]);
    if(!parser.Analyse()){
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
