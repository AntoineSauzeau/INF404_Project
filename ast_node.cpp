#include "ast_node.hpp"

AstNode::AstNode(std::string node_name) {
    this->node_name = node_name;
}

AstNode::~AstNode() {

    for(std::vector<AstNode*>::iterator it = l_children.begin() ; it != l_children.end(); ++it){
        delete *it;
    }
}

void AstNode::AddChildren(AstNode *node) {
    l_children.push_back(node);
}

void AstNode::SetAttributes(std::map<std::string, std::string> l_attribute) {
    this->l_attribute = l_attribute;
}

void AstNode::SetNodeName(std::string name) {
    this->node_name = name;
}

std::string AstNode::GetNodeName(){
    return this->node_name;
}

std::map<std::string, std::string>* AstNode::GetAttributes() {
    return &this->l_attribute;
}

std::vector<AstNode*>* AstNode::GetChildrens(){
    return &this->l_children;
}