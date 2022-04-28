#include "object.hpp"

Object::Object() {

}

Object::Object(std::map<std::string, std::string>* l_property) {

    if((*l_property)["x"] != ""){
        this->x = std::stoi((*l_property)["x"]);
    }
    else{
        x = 0;
    }

    if((*l_property)["rotation"] != ""){
        this->rotation = std::stoi((*l_property)["rotation"]);
    }
    else{
        rotation = 0;
    }

    if((*l_property)["y"] != ""){
        this->y = std::stoi((*l_property)["y"]);
    }
    else{
        y = 0;
    }

    if((*l_property)["color"] != "") {
        this->color = GetColorFromName((*l_property)["color"]);
    }
    else{
        color = GetColorFromName("red");
    }
}

Object::~Object(){

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

sf::Color Object::GetColorFromName(std::string name) {
    
    if(name == "red"){
        return sf::Color(255, 87, 51);
    }
    else if(name == "green") {
        return sf::Color(44, 232, 41);
    }
    else if(name == "blue") {
        return sf::Color(31, 93, 234);
    }
    else if(name == "cyan") {
        return sf::Color(15, 218, 225);
    }
    else if(name == "grey" || name == "gray"){
        return sf::Color(92, 92, 92);
    }
    else if(name == "black") {
        return sf::Color(0, 0, 0);
    }
    else if(name == "white") {
        return sf::Color(255, 255, 255);
    }
    else {
        std::cout << name << " ne fait pas partie de la palette de couleur possible !" << std::endl;
    }
}

sf::Color Object::GetColor(){
    return color;
}

double Object::GetX() {
    return x;
}

double Object::GetY() {
    return y;
}

void Object::SetProperties(std::map<std::string, std::string> *l_property) {
    this->l_property = *l_property;
}

void Object::SetColor(sf::Color color) {
    this->color = color;
}

void Object::AddChildren(Object *children) {
    l_children.push_back(children);
}

void Object::AddAnimation(Animation *animation) {
    l_animation.push_back(animation);
}

void Object::Rotate(int rotation) {
    this->rotation = this->rotation + (rotation % 360);
}

void Object::Translate(double x, double y) {
    this->x += x;
    this->y += y;
}

void Object::SetParent(Object* parent) {
    this->parent = parent;
}

void Object::Draw() {
    
}