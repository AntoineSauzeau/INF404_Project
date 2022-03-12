#pragma once

#include <iostream>
#include <fstream>
#include <list>

#include "lexeme.hpp"

class Parser {

    public:
        Parser(std::string file_name);
        ~Parser();

        // Retourne la liste de lexeme d'un du fichier
        void analyse_lexeme();
        void lexeme_courant();

        void display_content();

    private:
        list<Lexeme> lex_seq;
        std::string file_content;

};
