#pragma once

#include <map>
#include <string>

#include "object.hpp"

#include <SFML/Graphics.hpp>

// Classe fille pour les Cercles
class Circle : public Object {

    public:
        Circle(std::map<std::string, std::string>* l_property, type_object type);   // Constructeur
        ~Circle();
        void Draw(sf::RenderWindow* window);                                        // Fonction d'affichage

        sf::FloatRect GetBounds();

    private:
        float radius = 1;

        sf::CircleShape *circle = nullptr;
};