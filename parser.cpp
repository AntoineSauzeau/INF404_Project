#include "parser.hpp"

using namespace std;

Parser::Parser(string file_name) {
    cout << "Constructor Parser" << endl;

    file = new ifstream;
    file->open(file_name);

    if(!file->is_open()){
        cerr << "Impossible d'ouvrir le fichier :" << file_name << endl;
    }
}

Parser::~Parser() {
    cout << "Destructor Parser" << endl;
}

void Parser::AnalyseLexical() {

    aut_state state;
    string buffer = "";

    while(ReadWord(&string)){
        
        for(int i = 0; i < buffer.length; i++){

            Lexeme lex = new Lexeme();

            switch (string[i])
            {
            case '<':

            
            default:
                break;
            }
        }
    }

}

void Parser::LexemeCourant() {

}

bool ReadWord(string *buffer) {
    buffer->clear();

    ifstream >> buffer;
    if(buffer->compare("") == 1){
        return false;
    }
    
    return true;
    
}

void Parser::DisplayContent() {
   // std::cout << file_content << endl;
}
