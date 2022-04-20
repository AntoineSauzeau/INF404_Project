#include <iostream>
#include <unistd.h>

#include "parser.hpp"
#include "button.hpp"
#include "ast_node.hpp"
//#include "interface.hpp"

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 2) {
        cout << "Usage <program> <file>" << endl;
        return EXIT_FAILURE;
    }

    std::cout << "Starting..." << std::endl;


    Parser parser(argv[1]);
    AstNode **head_ast;
    if(parser.Analyse(head_ast)){
        return EXIT_FAILURE;
    }

    parser.CreateObjectsFromAst(*head_ast);
    Window *window_abstract_object = parser.GetWindowObject();

    Interface interface(window_abstract_object);
    interface.TreatEvents();

    return EXIT_SUCCESS;
}
