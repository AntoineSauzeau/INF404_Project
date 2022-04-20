#include "rect.hpp"

Rect::Rect(std::map<std::string, std::string>* l_property) {

    this->x = std::stoi((*l_property)["x"]);
    this->y = std::stoi((*l_property)["y"]);
    this->width = std::stoi((*l_property)["width"]);
    this->height = std::stoi((*l_property)["height"]);
}

void Rect::Draw(sf::RenderWindow *window) {
    
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition(sf::Vector2f(x, y));

    window->draw(rect);
}