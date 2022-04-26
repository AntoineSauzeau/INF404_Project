#pragma once

class Animation;
#include "animation.hpp"

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

enum type_object {WINDOW, RECT, CIRCLE, TRIANGLE, IMAGE};

class Object {

    public:
        Object(std::map<std::string, std::string>* l_property);

        void SetProperty(std::string property, std::string value);
        void SetProperties(std::map<std::string, std::string>*l_property);
        void SetParent(Object *parent);
        void SetColor(sf::Color color);

        std::string GetProperty(std::string property);
        std::vector<Object*> *GetChildrens();
        type_object GetType();
        sf::Color GetColor();

        void AddChildren(Object *children);
        void AddAnimation(Animation *animation);

        void Rotate(int rotation);

        static sf::Color GetColorFromName(std::string name);

        virtual void Draw();

    protected:
        Object();

        std::map<std::string, std::string> l_property;
        std::vector<Animation *> l_animation;

        Object* parent = nullptr;
        std::vector<Object*> l_children;

        type_object type;

        sf::Color color;

        int x = 0;
        int y = 0;

        double rotation = 0;
};