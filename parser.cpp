#include "parser.hpp"

using namespace std;




Parser::Parser(string file_name) {
    cout << "Constructor Parser" << endl;

    file = new ifstream;
    file->open(file_name);

    if(!file->is_open()){
        cerr << "Impossible d'ouvrir le fichier :" << file_name << endl;
    }

    AnalyseLexical();

    for (auto &i: Parser::lex_seq) {
        cout << i.GetValue() << " -- ";
    }
    cout << endl;
}

Parser::~Parser() {
    cout << "Destructor Parser" << endl;
}

void Parser::PushList(Lexeme lex) {
    Lexeme lex_copy = lex;
    Parser::lex_seq.push_back(lex_copy);
}

void Parser::AnalyseLexical() {

    aut_state sta = E_INIT;
    string buffer = "";
    string text = "";
    Lexeme lex = Lexeme();

    getline(*file, buffer);

    cout << buffer.compare("") << endl;

    while(buffer.compare("")!=0){

        for(int i = 0; i < buffer.length(); i++){

            switch (sta) {
                case E_INIT:
                    switch(buffer[i]) {
                    case '<':
                        lex.SetLexType(CHEVRON_O);
                        lex.SetValue("<");
                        Parser::PushList(lex);
                        break;
                    case '>':
                        lex.SetLexType(CHEVRON_C);
                        lex.SetValue(">");
                        Parser::PushList(lex);
                        break;
                    case 'a' ... 'z':
                    case 'A' ... 'Z':
                        sta = E_TEXT;
                        text += buffer[i];
                        break;
                    default:
                        break;
                    }
                    break;

                    case E_TEXT:
                        switch(buffer[i]) {
                        case ' ':
                            sta = E_INIT;
                            lex.SetLexType(TEXT);
                            lex.SetValue(text);
                            Parser::PushList(lex);
                            text = "";
                            break;
                        case 'a' ... 'z':
                        case 'A' ... 'Z':
                            text += buffer[i];
                            break;
                        case '<':
                            sta = E_INIT;
                            lex.SetLexType(TEXT);
                            lex.SetValue(text);
                            Parser::PushList(lex);

                            lex.SetLexType(CHEVRON_O);
                            lex.SetValue("<");
                            Parser::PushList(lex);

                            text = "";
                            break;

                        case '>':
                            sta = E_INIT;
                            lex.SetLexType(TEXT);
                            lex.SetValue(text);
                            Parser::PushList(lex);

                            lex.SetLexType(CHEVRON_C);
                            lex.SetValue(">");
                            Parser::PushList(lex);

                            text = "";
                            break;
                        }

            default:
                break;
            }
        }

        getline(*file, buffer);
    }

}

void Parser::LexemeCourant() {

}



void Parser::DisplayContent() {
   // std::cout << file_content << endl;
}
