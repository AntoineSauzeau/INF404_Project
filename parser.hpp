#pragma once

#include <iostream>
#include <fstream>
#include <list>

#include "lexeme.hpp"

class Parser {

    public:
        Parser(std::string file_name);
        ~Parser();

    void analyse_lexeme();
    void lexeme_courant();

    private:
        list<Lexeme> lex_seq;
    
};