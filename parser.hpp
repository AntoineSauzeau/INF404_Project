#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <string>

#include "lexeme.hpp"
#include "object.hpp"
#include "button.hpp"
#include "window.hpp"
#include "interface.hpp"
#include "ast_node.hpp"
#include "rect.hpp"
#include "circle.hpp"
#include "triangle.hpp"


enum e_aut_state {E_INIT, E_FINAL, E_TEXT};

typedef e_aut_state aut_state;



class Parser {

    public:
        Parser(std::string file_name);
        ~Parser();

        // Retourne la liste de lexeme d'un du fichier
        int Analyse(AstNode **head_ast);
        void AnalyseLexical();
        Lexeme LexemeCourant();
        void NextLexeme();
        lex_type GetNextLexemeType();

        void PushList(Lexeme lex);
        bool IsAplhaNumeric(char c);
        bool CarInLexique(char c);
        bool IsSeparator(char c);
        
        bool IsValidTagName(string name);

        AstNode* AnalyseSyntactical();
        AstNode* RecTagCouple(AstNode* parent);
        AstNode* RecExpr(bool tag_couple = false, AstNode* parent = nullptr);
        std::string RecTagName();
        void RecSeqAttribute(std::map<std::string, std::string> &l_attribute);
        void RecSeqText(std::string *text);
        Object* CreateGoodObjectFromHisName(std::string name,  std::map<std::string, std::string> *l_property);
        void RecCreateObjectsFromAst(AstNode* node, Object* parent);
        void CreateObjectsFromAst(AstNode* node);
        std::map<std::string, std::string> GetObjectPropertiesFromAst(AstNode* node);
        Window* GetWindowObject();

        void LexicalError(int l, int c, char car);
        void SyntacticalError(Lexeme lex);
        void SyntacticalWarning(Lexeme lex);

    private:
        list<Lexeme> lex_seq;
        list<Lexeme>::iterator it_lexeme_list;
        //bool lex_seq_end = false;
        ifstream *file;
        vector<Object*> l_object;

};
