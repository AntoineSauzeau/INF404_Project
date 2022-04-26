#include "rect.hpp"

Rect::Rect(std::map<std::string, std::string>* l_property, type_object type):Object(l_property) {

    this->width = std::stoi((*l_property)["width"]);
    this->height = std::stoi((*l_property)["height"]);

    this->type = type;
}

void Rect::Draw(sf::RenderWindow *window) {
    
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition(sf::Vector2f(x, y));
    rect.setRotation(rotation);
    rect.setFillColor(color);

    window->draw(rect);
}