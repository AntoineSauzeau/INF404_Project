#pragma once

#include <string>

#include "object.hpp"

#include <SFML/Graphics.hpp>

// Classe de l'objet Window
// Objet racine qui contient tout les objets
class Window : public Object {

    public:
        Window(std::map<std::string, std::string>* l_property, type_object type);

        void Draw(sf::RenderWindow *window);    // Fonction d'affichage

        int GetWidth();
        int GetHeight();

    private:
        int width = 0;
        int height = 0;
};