#include "circle.hpp"

Circle::Circle(std::map<std::string, std::string>* l_property, type_object type):Object(l_property) {

    this->radius = std::stof((*l_property)["radius"]);

    this->type = type;
}

void Circle::Draw(sf::RenderWindow *window) {
    
    sf::CircleShape circle(radius);
    circle.setPosition(sf::Vector2f(x, y));
    circle.setRotation(rotation);
    circle.setFillColor(color);

    window->draw(circle);
}