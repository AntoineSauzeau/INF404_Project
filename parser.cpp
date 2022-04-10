#include "parser.hpp"

using namespace std;




Parser::Parser(string file_name) {

    file = new ifstream;
    file->open(file_name);

    if(!file->is_open()){
        cerr << "Impossible d'ouvrir le fichier :" << file_name << endl;
    }
}

int Parser::Analyse() {

    std::cout << "Analyse..." << std::endl;

    try {
        AnalyseLexical();
        AnalyseSyntactical();
    } catch(std::runtime_error& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << "\033[1;32mAucune erreur détectée !\033[0m" << std::endl;

    for (auto &i: Parser::lex_seq) {
        cout << i.GetValue() << " -- ";
    }
    cout << endl;

    return 0;
}

Parser::~Parser() {

    file->close();

    for(std::vector<Object*>::iterator it = l_object.begin() ; it != l_object.end(); ++it){
        delete *it;
    }
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
                    case '/':
                        lex.SetLexType(SLASH);
                        lex.SetValue("/");
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
                        lex.SetLine(l);
                        lex.SetColumn(i);
                        Parser::PushList(lex);
                    }

                    break;

                    case E_TEXT:

                        if(!IsAplhaNumeric(buffer[i])){
                            sta = E_INIT;
                            lex.SetLexType(TEXT);
                            lex.SetValue(text);
                            lex.SetLine(l);
                            lex.SetColumn(i - text.length() - 1);
                            Parser::PushList(lex);

                            if(buffer[i] != ' ') {
                                string s;
                                s.append(1, buffer[i]);
                                lex.SetValue(s);
                                lex.SetLexType(Lexeme::GetLexTypeFromString(s));
                                lex.SetLine(l);
                                lex.SetColumn(i);
                                Parser::PushList(lex);
                            }

                                text = "";
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

    lex.SetLexType(END);
    lex.SetValue("FIN DE CHAINE");
    Parser::PushList(lex);

    it_lexeme_list = lex_seq.begin();

}

AstNode* Parser::AnalyseSyntactical() {

    AstNode *head = RecTagCouple(nullptr);

    if(LexemeCourant().GetLexType() != END){
        SyntacticalError(LexemeCourant());
    }

    return head;
}

AstNode* Parser::RecTagCouple(AstNode* parent) {
    RecExpr(true);
}

AstNode* Parser::RecExpr(bool tag_couple, AstNode* parent) {

    if(tag_couple){
        if(LexemeCourant().GetLexType() != CHEVRON_O){
            SyntacticalError(LexemeCourant());
        }
    }
    else{
        if(LexemeCourant().GetLexType() == TEXT){
            RecSeqText(nullptr);
            return nullptr;
        }
    }

    if(GetNextLexemeType() == SLASH) {
        return nullptr;
    }

    std::string tag1_name;
    std::string tag2_name;
    std::map<std::string, std::string> l_attribute;

    NextLexeme();
    tag1_name = RecTagName();
    RecSeqAttribute(l_attribute);

    if(LexemeCourant().GetLexType() != CHEVRON_C){
        SyntacticalError(LexemeCourant());
    }

    NextLexeme();

    AstNode* node = new AstNode(tag1_name);
    node->SetAttributes(l_attribute);
    RecExpr(node);

    if(LexemeCourant().GetLexType() != CHEVRON_O){
        SyntacticalError(LexemeCourant());
    }

    NextLexeme();

    if(LexemeCourant().GetLexType() != SLASH){
        SyntacticalError(LexemeCourant());
    }

    NextLexeme();
    tag2_name = RecTagName();

    if(tag1_name != tag2_name) {
        SyntacticalError(LexemeCourant());
    }

    if(LexemeCourant().GetLexType() != CHEVRON_C){
        SyntacticalError(LexemeCourant());
    }

    NextLexeme();

    if(!tag_couple){
        RecTagCouple(parent);
    }

    return node;
}

void Parser::RecSeqAttribute(std::map<std::string, std::string> &l_attribute) {

    std::string a_name;
    std::string a_value;

    if(LexemeCourant().GetLexType() == CHEVRON_C){
        return;
    }

    if(LexemeCourant().GetLexType() != TEXT){
        SyntacticalError(LexemeCourant());
    }

    a_name = LexemeCourant().GetValue();

    NextLexeme();

    if(LexemeCourant().GetLexType() != EQUAL){
        SyntacticalError(LexemeCourant());
    }

    NextLexeme();

    if(LexemeCourant().GetLexType() != D_QUOTE){
        SyntacticalError(LexemeCourant());
    }

    NextLexeme();
    RecSeqText(&a_value);

    if(LexemeCourant().GetLexType() != D_QUOTE){
        SyntacticalError(LexemeCourant());
    }

    l_attribute[a_name] = a_value;

    NextLexeme();
    RecSeqAttribute(l_attribute);
}

void Parser::RecSeqText(std::string *text) {

    if(LexemeCourant().GetLexType() != TEXT){
        return;
    }

    if(text != nullptr){
        *(text) += LexemeCourant().GetValue();
    }

    NextLexeme();
    RecSeqText(text);
}

std::string Parser::RecTagName(){

    if(LexemeCourant().GetLexType() != TEXT){
        SyntacticalError(LexemeCourant());
    }

    std::string tag_name;
    tag_name = LexemeCourant().GetValue();
    NextLexeme();
    
    return tag_name;
}

Object* Parser::CreateGoodObjectFromHisName(std::string name) {

    if(name == "button") {
        return new Button;
    }
}

Lexeme Parser::LexemeCourant() {
    return *it_lexeme_list;

}

void Parser::NextLexeme(){
    if(it_lexeme_list != lex_seq.end()){
        it_lexeme_list++;
    }
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
    case '/':
        return true;
        break;
    default:
        break;
    }

    return false;
}

bool Parser::IsSeparator(char c){
    return c == ' ' || c == '\n' || c == '\r';
}

void Parser::LexicalError(int l, int c, char car) {

    std::ostringstream error_string_s;
    error_string_s << "\033[1;31mErreur lexicale (" << l << ", " << c << ") : Le caractère " << car << " ne fait pas partie du lexique\033[0m" << std::endl;
    
    throw runtime_error(error_string_s.str());
}

void Parser::SyntacticalError(Lexeme lexeme) {

    std::ostringstream error_string_s;
    error_string_s << "\033[1;31mErreur syntaxique (" << lexeme.GetLine() << ", " << lexeme.GetColumn() << ")\033[0m" << std::endl;

    throw runtime_error(error_string_s.str());
}

lex_type Parser::GetNextLexemeType() {
    return ((Lexeme)*std::next(it_lexeme_list, 1)).GetLexType();
}

bool Parser::IsValidTagName(string name){

    return name == "window" || name == "property";
}