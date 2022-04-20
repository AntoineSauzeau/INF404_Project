#pragma once

#include <string>

#include "object.hpp"

class Window : public Object {

    public:
        Window(std::map<std::string, std::string>* l_property);

        int GetWidth();
        int GetHeight();

    private:
        int width = 0;
        int height = 0;
};