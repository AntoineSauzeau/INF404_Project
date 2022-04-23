#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

enum type_object {WINDOW, RECT, CIRCLE, TRIANGLE};

class Object {

    public:
        Object(Object* parent = nullptr);

        void SetProperty(std::string property, std::string value);
        void SetProperties(std::map<std::string, std::string>*l_property);
        void SetParent(Object *parent);

        std::string GetProperty(std::string property);
        std::vector<Object*> *GetChildrens();
        type_object GetType();
        sf::Color GetColorFromName(std::string name);

        void AddChildren(Object *children);

        virtual void Draw();

    protected:
        std::map<std::string, std::string> l_property;

        Object* parent = nullptr;
        std::vector<Object*> l_children;

        type_object type;
};