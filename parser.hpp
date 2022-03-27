#pragma once

#include <iostream>
#include <fstream>
#include <list>

#include "lexeme.hpp"

enum e_aut_state {E_INIT, E_FINAL, E_TEXT};

typedef e_aut_state aut_state;



class Parser {

    public:
        Parser(std::string file_name);
        ~Parser();

        // Retourne la liste de lexeme d'un du fichier
        void AnalyseLexical();
        void LexemeCourant();

        void DisplayContent();

        void PushList(Lexeme lex);
        bool IsAplhaNumeric(char c);
        bool CarInLexique(char c);
        bool IsSeparator(char c);

        void LexicalError(int l, int c, char car);

    private:
        list<Lexeme> lex_seq;
        ifstream *file;

};
