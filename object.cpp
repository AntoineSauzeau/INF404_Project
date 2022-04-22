#include "object.hpp"

Object::Object(Object *parent) {
    this->parent = parent;
    this->type = type;
}

void Object::SetProperty(std::string property, std::string value) {
    l_property[property] = value;
}


std::string Object::GetProperty(std::string property) {
    return l_property[property];
}

std::vector<Object*> *Object::GetChildrens() {
    return &l_children;
}

type_object Object::GetType() {
    return type;
}

void Object::SetProperties(std::map<std::string, std::string> *l_property) {
    this->l_property = *l_property;
}

void Object::AddChildren(Object *children) {
    l_children.push_back(children);
}

void Object::SetParent(Object* parent) {
    this->parent = parent;
}

void Object::Draw() {
    std::cout << "d";
}