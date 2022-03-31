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

        Lexeme(const Lexeme &l1);

        lex_type GetLexType();
        string GetValue();
        int GetLine();
        int GetColumn();

        void SetLexType(lex_type type);
        void SetValue(string value);
        void SetLine(int line);
        void SetColumn(int column);

        static lex_type GetLexTypeFromString(string lex);

    private:
        lex_type type;
        string value;
        int line, column;
};
