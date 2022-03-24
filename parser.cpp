#include "parser.hpp"

using namespace std;

Parser::Parser(string file_name) {
    cout << "Constructor Parser" << endl;

    ifstream file;
    file.open(file_name);

    if(!file.is_open()){
        cerr << "Impossible d'ouvrir le fichier :" << file_name << endl;
    }

    file >> file_content;

}

Parser::~Parser() {
    cout << "Destructor Parser" << endl;
}

void Parser::analyse_lexical() {

    
}

void Parser::lexeme_courant() {

}

void Parser::display_content() {
    std::cout << file_content << endl;
}
