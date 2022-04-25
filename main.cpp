#include <iostream>
#include <unistd.h>

#include "parser.hpp"
#include "button.hpp"
#include "ast_node.hpp"
#include "animation_handler.hpp"
//#include "interface.hpp"

#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 2) {
        cout << "Usage <program> <file>" << endl;
        return EXIT_FAILURE;
    }

    std::cout << "Starting..." << std::endl;


    Parser parser(argv[1]);
    AstNode *head_ast;
    if(parser.Analyse(&head_ast)){
        return EXIT_FAILURE;
    }

    AnimationHandler animation_handler;
    parser.AddAnimationHandler(&animation_handler);
    parser.CreateObjectsFromAst(head_ast);
    Window *window_abstract_object = parser.GetWindowObject();

    //Pour une raison inconnue créer la fenêtre ailleurs que dans le main ne fonctionne pas, on la crée donc ici et on passe un pointeur
    sf::RenderWindow window(sf::VideoMode(800, 800), "Interface");
    ProgInterface interface(window_abstract_object, &window);
    interface.Draw();

    animation_handler.AttachInterface(&interface);
    animation_handler.StartAnimationHandling();

    interface.TreatEvents();

    return EXIT_SUCCESS;
}
