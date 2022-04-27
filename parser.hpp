#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <string>

#include "lexeme.hpp"
#include "object.hpp"
#include "text.hpp"
#include "window.hpp"
#include "interface.hpp"
#include "ast_node.hpp"
#include "rect.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "animation_handler.hpp"
#include "image.hpp"


enum e_aut_state {E_INIT, E_FINAL, E_TEXT};

typedef e_aut_state aut_state;


// Classe de Parser
class Parser {

    public:
        Parser(std::string file_name);
        ~Parser();

        // Retourne la liste de lexeme d'un du fichier
        int Analyse(AstNode **head_ast);
        void AnalyseLexical();  // Lance l'analyse lexicale
        Lexeme LexemeCourant(); // Renvoie le lexème en cours d'analyse
        void NextLexeme();  // Passe au lexeème suivant
        lex_type GetNextLexemeType();   // Renvoie le typedu lexème suivant

        void PushList(Lexeme lex);  // Push le lexème dans la liste
        bool IsAplhaNumeric(char c);    // Renvoie vrai si le caractère est une lettre, faux sinon
        bool CarInLexique(char c);  // Renvoie vrai si le caractère fait partie du lexique, faux sinon
        bool IsSeparator(char c);   // Renvoie vrai si le caractère est un séparateur, faux sinon
        
        bool IsValidTagName(string name);   // Renvoie vrai si la chaine de caractères fait partie des noms de balise connus, faux sinon

        AstNode* AnalyseSyntactical();  // Lance l'analyse syntaxique
        AstNode* RecTagCouple(AstNode* parent);
        AstNode* RecExpr(bool tag_couple = false, AstNode* parent = nullptr);
        std::string RecTagName();
        void RecSeqAttribute(std::map<std::string, std::string> &l_attribute);
        void RecSeqText(std::string *text);
        Object* CreateGoodObjectFromHisName(std::string name,  std::map<std::string, std::string> *l_property);
        void RecCreateObjectsFromAst(AstNode* node, Object* parent);
        void CreateObjectsFromAst(AstNode* node);
        std::map<std::string, std::string> GetObjectPropertiesFromAst(AstNode* node);
        std::map<std::string, std::string> GetObjectAnimationsFromAst(AstNode* node);
        Window* GetWindowObject();
        void AddAnimationHandler(AnimationHandler *animation_handler);

        void LexicalError(int l, int c, char car);
        void SyntacticalError(Lexeme lex);
        void SyntacticalWarning(Lexeme lex);

    private:
        list<Lexeme> lex_seq;
        list<Lexeme>::iterator it_lexeme_list;
        //bool lex_seq_end = false;
        ifstream *file;
        vector<Object*> l_object;
        AnimationHandler *animation_handler = nullptr;

};
