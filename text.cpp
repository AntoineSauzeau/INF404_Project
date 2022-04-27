#include "text.hpp"

Text::Text(std::map<std::string, std::string>* l_property, type_object type):Object(l_property) {

    this->type = type;

    font_name = (*l_property)["font"];
    font_size = std::stoi((*l_property)["font_size"]);
    text_value = (*l_property)["text_value"];

    if((*l_property)["style"] == "bold"){
        style = sf::Text::Bold;
    }
    else if((*l_property)["style"] == "underlined"){
        style = sf::Text::Underlined;
    }
    else if((*l_property)["style"] == "italic"){
        style = sf::Text::Italic;
    }
    else if((*l_property)["style"] == "strike_through"){
        style = sf::Text::StrikeThrough;
    }
    else {
        style = sf::Text::Regular;
    }

    if(!font.loadFromFile("Fonts/" + font_name))
    {
        std::cerr << "Impossible d'ouvrir la police : " << font_name << std::endl;
    }

    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString(text_value);

    // set the character size
    text.setCharacterSize(font_size);

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(style);

}

void Text::Draw(sf::RenderWindow *window) {

    text.setPosition(sf::Vector2f(x, y));

    window->draw(text);
}

sf::FloatRect Text::GetBounds() {
    return text.getGlobalBounds();
}