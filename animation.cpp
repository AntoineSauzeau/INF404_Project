#include "animation.hpp"

Animation::Animation(Object *object, std::map<std::string, std::string>*l_property) {

    this->object = object;

    if((*l_property)["type"] == "slide"){
        type = SLIDE;
    }
    else if((*l_property)["type"] == "color"){
        type = COLOR;
    }
    else if((*l_property)["type"] == "size"){
        type = SIZE;
    }

    if((*l_property)["event"] == "none"){
        event = NONE;
    }
    else if((*l_property)["type"] == "onclick"){
        event = ONCLICK;
    }

    if((*l_property)["reset_at_end"] == "false"){
        reset_at_end = false;
    }
    else if((*l_property)["reset_at_end"] == "true"){
        reset_at_end = true;
    }   

    if(type == COLOR) {
        new_color = Object::GetColorFromName((*l_property)["new_color"]);
    }

    time = std::stoi((*l_property)["time"]);

    if(event == NONE){
        Run();
    }
}

void Animation::Run() {

    enable = true;
    start_time = std::chrono::system_clock::now();

    if(type == COLOR) {
        old_color = object->GetColor();
        object->SetColor(new_color);
    }
}

void Animation::Update() {

    std::chrono::system_clock::time_point time_now = std::chrono::system_clock::now();
    int time_elapsed = std::chrono::duration_cast<std::chrono::seconds> (time_now - start_time).count();

    if(time_elapsed >= time){

        enable = false;

        if(reset_at_end){
            std::cout << "d" << std::endl;
            Reset();
        }
    }
}

void Animation::Reset() {

    if(type == COLOR) {
        object->SetColor(old_color);
    }
}

bool Animation::IsEnable() {
    return enable;
}
