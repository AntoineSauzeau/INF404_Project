#pragma once

#include <vector>
#include <map>
#include <string>

class AstNode {

    public:
        AstNode(std::string node_name);
        ~AstNode();

        void AddChildren(AstNode *node);
        void SetAttributes(std::map<std::string, std::string> l_attribute);
        void SetNodeName(std::string name);

    private:
        std::vector<AstNode*> l_children;
        std::map<std::string, std::string> l_attribute;
        std::string node_name;
};