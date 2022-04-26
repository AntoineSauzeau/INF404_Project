#pragma once

#include <map>
#include <string>

#include "object.hpp"

#include <SFML/Graphics.hpp>

class Image : public Object {

    public:
        Image(std::map<std::string, std::string>* l_property, type_object type);
        void Draw_(sf::RenderWindow* window);

    private:
        std::string file_path;
        bool smooth = false;
        sf::Texture *texture = nullptr;
        sf::Sprite *sprite = nullptr;
        double scale_x = 1;
        double scale_y = 1;
};