#pragma once

class Animation;
#include "animation.hpp"

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

enum class type_object {WINDOW, RECT, CIRCLE, TRIANGLE, IMAGE, TEXT};

// Classe mère des objets dessinés par SFML
class Object {

    public:
        Object(std::map<std::string, std::string>* l_property);

        // Setters
        void SetProperty(std::string property, std::string value);
        void SetProperties(std::map<std::string, std::string>*l_property);
        void SetParent(Object *parent);
        void SetColor(sf::Color color);

        // Getters
        std::string GetProperty(std::string property);
        std::vector<Object*> *GetChildrens();
        type_object GetType();
        sf::Color GetColor();
        double GetX();
        double GetY();

        void AddChildren(Object *children);
        void AddAnimation(Animation *animation);

        void Rotate(int rotation);
        void Translate(double x, double y);

        static sf::Color GetColorFromName(std::string name);

        // Fonction virtuelle d'affichage des objets
        // Dessine l'objet sur le canvas en attente d'affichage
        virtual void Draw();

    protected:
        Object();

        std::map<std::string, std::string> l_property;
        std::vector<Animation *> l_animation;

        Object* parent = nullptr;
        std::vector<Object*> l_children;

        type_object type;

        sf::Color color;

        double x = 0;
        double y = 0;

        double rotation = 0;
};