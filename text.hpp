#pragma once

#include <map>
#include <string>

#include "object.hpp"

#include <SFML/Graphics.hpp>

class Text : public Object {

    public:
        Text(std::map<std::string, std::string>* l_property, type_object type);
        void Draw(sf::RenderWindow* window);

        sf::FloatRect GetBounds();

    private:
        sf::Text text;
        sf::Font font;
        std::string font_name;
        int font_size;
        std::string text_value;
        sf::Text::Style style;
};