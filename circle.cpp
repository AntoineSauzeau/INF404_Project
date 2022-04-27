#include "circle.hpp"

Circle::Circle(std::map<std::string, std::string>* l_property, type_object type):Object(l_property) {

    this->radius = std::stof((*l_property)["radius"]);

    this->type = type;

    circle = new sf::CircleShape (radius);
}

void Circle::Draw(sf::RenderWindow *window) {
    
    circle->setPosition(sf::Vector2f(x, y));
    circle->setRotation(rotation);
    circle->setFillColor(color);

    window->draw(*circle);
}

sf::FloatRect Circle::GetBounds() {
    return circle->getGlobalBounds();
}
