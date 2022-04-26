#include "image.hpp"

Image::Image(std::map<std::string, std::string>* l_property, type_object type):Object(l_property) {

    this->scale_x = std::stof((*l_property)["scale_x"]);
    this->scale_y = std::stof((*l_property)["scale_y"]);

    this->rotation = std::stof((*l_property)["rotation"]);

    file_path = (*l_property)["src"];

    texture = new sf::Texture;
    if (!texture->loadFromFile("./chameau.jpg"))
    {
        std::cerr << "Impossible d'ouvrir l'image : " << file_path << std::endl; 
    }

    if(smooth){
        texture->setSmooth(true);
    }

    sprite = new sf::Sprite;
    sprite->setTexture(*texture);
    sprite->setPosition(sf::Vector2f(x, y));
    sprite->setRotation(rotation);
    sprite->setScale(sf::Vector2f(scale_x, scale_y));
    sprite->setOrigin(sf::Vector2f(sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2));

    this->type = type;

}

void Image::Draw_(sf::RenderWindow *window) {
    
    sprite->setRotation(rotation);
    window->draw(*sprite);
}