#pragma once

#include <iostream>

using namespace std;

enum lex_type {
    CHEVRON_O,
    CHEVRON_C,
    TEXT,
    EQUAL,
    SLASH,
    D_QUOTE
};

class Lexeme {

    public:
        Lexeme();
        ~Lexeme();

        lex_type GetLexType();
        string GetValue();

        void SetLexType(lex_type type);
        void SetValue(string value);

    private:
        lex_type type;
        string value;
};