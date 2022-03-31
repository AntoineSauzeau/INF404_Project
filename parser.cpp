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
    unsigned int l = 1;

    cout << buffer.compare("") << endl;

    while(getline(*file, buffer)){

        for(int i = 0; i < buffer.length(); i++){

            if(!CarInLexique(buffer[i]) && !IsSeparator(buffer[i])){
                LexicalError(l, i+1, buffer[i]);
            }

            switch (sta) {

                case E_INIT:

                    switch(buffer[i]) {
                    case '<':
                        lex.SetLexType(CHEVRON_O);
                        lex.SetValue("<");
                        break;
                    case '>':
                        lex.SetLexType(CHEVRON_C);
                        lex.SetValue(">");
                        break;
                    case '\"':
                        lex.SetLexType(D_QUOTE);
                        lex.SetValue("\"");
                        break;
                    case '\\':
                        lex.SetLexType(SLASH);
                        lex.SetValue("\\");
                        break;
                    case '=':
                        lex.SetLexType(EQUAL);
                        lex.SetValue("=");
                        break;
                    case 'a' ... 'z':
                    case 'A' ... 'Z':
                        sta = E_TEXT;
                        text += buffer[i];
                        break;
                    default:
                        break;
                    }

                    if(sta != E_TEXT && !IsSeparator(buffer[i])) {
                        Parser::PushList(lex);
                    }

                    break;

                    case E_TEXT:

                        if(!IsAplhaNumeric(buffer[i])){
                            sta = E_INIT;
                            lex.SetLexType(TEXT);
                            lex.SetValue(text);
                            Parser::PushList(lex);

                            if(buffer[i] != ' ') {
                                string s;
                                s.append(1, buffer[i]);
                                lex.SetValue(s);
                                lex.SetLexType(Lexeme::GetLexTypeFromString(s));
                                Parser::PushList(lex);

                                text = "";
                            }
                        }
                        else if(buffer[i] == ' '){
                            text = "";
                        }
                        else{
                            text += buffer[i];
                        }

                        break;

            default:
                break;
            }
        }
    }

    it_lexeme_list = lex_seq.begin();

}

void Parser::AnalyseSyntactical() {
    
}

void Parser::RecChevronO(){

}

void Parser::RecBaliseName() {

}

void Parser::RecSlash() {
    
}

Lexeme Parser::LexemeCourant() {
    return *it_lexeme_list;
}

void Parser::NextLexeme(){
    it_lexeme_list++;
}


void Parser::DisplayContent() {
   // std::cout << file_content << endl;
}


bool Parser::IsAplhaNumeric(char c) {
    return (c >= 65 && c <= 90) || (c >= 48 && c <= 57) || (c >= 97 && c <= 122);
}

bool Parser::CarInLexique(char c) {
    
    if(IsAplhaNumeric(c)){
        return true;
    }

    switch (c)
    {
    case '<':
    case '>':
    case '\"':
    case '=':
    case '\\':
        return true;
        break;
    default:
        break;
    }

    return false;
}

bool Parser::IsSeparator(char c){
    return c == ' ';
}

void Parser::LexicalError(int l, int c, char car) {
    fprintf(stderr, "Erreur lexicale (%i, %i) : Le caractère %c ne fait pas partie du lexique\n", l, c, car);
    exit(EXIT_FAILURE);
}
