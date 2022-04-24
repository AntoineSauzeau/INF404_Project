#include "window.hpp"

Window::Window(std::map<std::string, std::string>* l_property, type_object type){

    this->width = std::stoi((*l_property)["width"]);
    this->height = std::stoi((*l_property)["height"]);
    this->color = GetColorFromName((*l_property)["background_color"]);

    this->type = type;
}

int Window::GetWidth() {
    return this->width;
}

int Window::GetHeight() {
    return this->height;
}

void Window::Draw(sf::RenderWindow *window) {

    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setFillColor(color);

    window->draw(rect);
}