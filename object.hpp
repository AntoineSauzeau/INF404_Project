#pragma once

#include <map>
#include <vector>
#include <string>

class Object {

    public:
        Object(Object* parent = nullptr);

        void SetStringPropertyValue(std::string property, std::string value);
        void SetIntegerPropertyValue(std::string property, double value);

        std::string GetStringPropertyValue(std::string property);
        double GetIntegerPropertyValue(std::string propery);

        void AddChildren(Object *children);

    protected:
        //Quand on parse on vérifie le format de l'entrée et on convertis à ce moment là en entier si besoin. On évite ainsi de le faire 40 fois ensuite 
        std::map<std::string, double> list_n_properties;
        std::map<std::string, std::string> list_s_properties;

        Object* parent;
        std::vector<Object*> l_children;

};