#pragma once

#include <vector>
#include <map>
#include <string>

class AstNode {

    public:
        AstNode(std::string node_name);
        ~AstNode();

        void SetAttributes(std::map<std::string, std::string> l_attribute);
        void SetNodeName(std::string name);

        std::string GetNodeName();
        std::map<std::string, std::string>* GetAttributes();
        std::vector<AstNode*>* GetChildrens();

        void AddChildren(AstNode *node);

    private:
        std::vector<AstNode*> l_children;
        std::map<std::string, std::string> l_attribute;
        std::string node_name;
};