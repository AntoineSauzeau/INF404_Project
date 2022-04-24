#include "triangle.hpp"

Triangle::Triangle(std::map<std::string, std::string>* l_property, type_object type) {

    this->x = std::stoi((*l_property)["x"]);
    this->y = std::stoi((*l_property)["y"]);
    this->radius = std::stof((*l_property)["radius"]);
    this->color = GetColorFromName((*l_property)["color"]);

    this->type = type;
}

void Triangle::Draw(sf::RenderWindow *window) {
    
    sf::CircleShape triangle(radius, 3);
    triangle.setPosition(sf::Vector2f(x, y));
    triangle.setFillColor(color);

    window->draw(triangle);
}