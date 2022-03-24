#pragma once

#include <iostream>
#include <fstream>
#include <list>

#include "lexeme.hpp"

enum e_aut_state {E_INIT, E_FINAL, E_TEXT};
enum e_nature_lexeme {CHEVRON_OP, CHEVRON_CL, EQ, SLASH, DOUBLE_QUOTE, TEXT};

typedef e_aut_state aut_state;
typedef e_nature_lexeme nature_lexeme;

struct s_lexeme {
    e_nature_lexeme nature;
    string value;
}

typedef s_lexeme lexeme;



class Parser {

    public:
        Parser(std::string file_name);
        ~Parser();

        // Retourne la liste de lexeme d'un du fichier
        void analyse_lexical();
        void lexeme_courant();

        void display_content();

    private:
        list<Lexeme> lex_seq;
        std::string file_content;

};
