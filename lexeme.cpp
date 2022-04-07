#include "lexeme.hpp"

Lexeme::Lexeme() {
    //cout << "Constructor Lexeme" << endl;

    this->line = 0;
    this->column = 0;
}

Lexeme::~Lexeme() {
    //cout << "Destructor Lexeme" << endl;
}

Lexeme::Lexeme(const Lexeme &l1) {
    type = l1.type;
    value = l1.value;

    this->line = l1.line;
    this->column = l1.column;
}

lex_type Lexeme::GetLexType() {
    return this->type;
}

std::string Lexeme::GetValue() {
    return this->value;
}

void Lexeme::SetLexType(lex_type type) {
    this->type = type;
}

void Lexeme::SetValue(string value) {
    this->value = value;
}

lex_type Lexeme::GetLexTypeFromString(string lex) {

    if(lex == "<"){
        return CHEVRON_O;
    }
    else if(lex == ">"){
        return CHEVRON_C;
    }
    else if(lex == "/"){
        return SLASH;
    }
    else if(lex == "\""){
        return D_QUOTE;
    }
    else if(lex == "=") {
        return EQUAL;
    }
} 

int Lexeme::GetLine(){
    return this->line;
}

int Lexeme::GetColumn(){
    return this->column;
}

void Lexeme::SetLine(int line) {
    this->line = line;
}

void Lexeme::SetColumn(int column) {
    this->column = column;
}
