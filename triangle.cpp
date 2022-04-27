#include "triangle.hpp"

Triangle::Triangle(std::map<std::string, std::string>* l_property, type_object type):Object(l_property) {

    this->radius = std::stof((*l_property)["radius"]);

    this->type = type;

    triangle = new sf::CircleShape(radius, 3);
}

void Triangle::Draw(sf::RenderWindow *window) {
    
    triangle->setPosition(sf::Vector2f(x, y));
    triangle->setRotation(rotation);
    triangle->setFillColor(color);

    window->draw(*triangle);
}

sf::FloatRect Triangle::GetBounds(){
    return triangle->getGlobalBounds();
}