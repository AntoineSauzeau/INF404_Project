#pragma once

#include <iostream>

#include "window.hpp"
#include "rect.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "image.hpp"
#include "text.hpp"

class AnimationHandler;
#include "animation_handler.hpp"

#include <SFML/Graphics.hpp>

// Classe de gestion de la fenêtre SFML
class ProgInterface {

    public:
        ProgInterface(Window *window_abstract_object, sf::RenderWindow *window, AnimationHandler *animation_handler);

        void TreatEvents();     // Création de la boucle d'évènements
        void RecDraw(Object *); // Dessin récursif des objets
        void Draw();            // Dessin de la fenêtre

    private:
        sf::RenderWindow *window;
        Window* window_abstract_object = nullptr;
        AnimationHandler *animation_handler = nullptr;
};