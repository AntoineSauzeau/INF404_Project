#include "object.hpp"

Object::Object() {

}

void Object::SetStringPropertyValue(std::string property, std::string value) {
    list_s_properties[property] = value;
}

void Object::SetIntegerPropertyValue(std::string property, double value) {
    list_n_properties[property] = value;
}

std::string Object::GetStringPropertyValue(std::string property) {
    return list_s_properties[property];
}

double Object::GetIntegerPropertyValue(std::string property) {
    return list_n_properties[property];
}