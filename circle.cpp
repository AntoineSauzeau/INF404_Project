#include "circle.hpp"

Circle::Circle(std::map<std::string, std::string>* l_property, type_object type) {

    this->x = std::stoi((*l_property)["x"]);
    this->y = std::stoi((*l_property)["y"]);
    this->radius = std::stof((*l_property)["radius"]);

    this->type = type;
}

void Circle::Draw(sf::RenderWindow *window) {
    
    sf::CircleShape circle(radius);
    circle.setPosition(sf::Vector2f(x, y));
    circle.setFillColor(sf::Color(100, 250, 50));

    window->draw(circle);
}