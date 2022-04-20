#pragma once

#include <map>
#include <vector>
#include <string>

class Object {

    public:
        Object(Object* parent = nullptr);

        void SetProperty(std::string property, std::string value);
        void SetProperties(std::map<std::string, std::string>*l_property);
        void SetParent(Object *parent);

        std::string GetProperty(std::string property);
        std::vector<Object*> *GetChildrens();

        void AddChildren(Object *children);

        virtual void Draw();

    protected:
        std::map<std::string, std::string> l_property;

        Object* parent;
        std::vector<Object*> l_children;
};