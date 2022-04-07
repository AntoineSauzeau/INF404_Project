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
        Lexeme LexemeCourant();
        void NextLexeme();
        lex_type GetNextLexemeType();

        void DisplayContent();

        void PushList(Lexeme lex);
        bool IsAplhaNumeric(char c);
        bool CarInLexique(char c);
        bool IsSeparator(char c);

        void AnalyseSyntactical();
        void RecDblBaliseExpr();
        void RecExpr();
        void RecBaliseName();
        void RecSeqAttribute();
        void RecSeqText();

        void LexicalError(int l, int c, char car);
        void SyntacticalError(Lexeme lex);

    private:
        list<Lexeme> lex_seq;
        list<Lexeme>::iterator it_lexeme_list;
        //bool lex_seq_end = false;
        ifstream *file;

};
