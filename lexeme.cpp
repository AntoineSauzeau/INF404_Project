#include "lexeme.hpp"

Lexeme::Lexeme() {
    cout << "Constructor Lexeme" << endl;
}

Lexeme::~Lexeme() {
    cout << "Destructor Lexeme" << endl;
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