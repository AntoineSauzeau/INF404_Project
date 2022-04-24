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
    start_clock_time = clock();

    if(type == COLOR) {
        old_color = object->GetColor();
        object->SetColor(new_color);
    }
}

void Animation::Update() {


    float u = ((float) (clock() - start_clock_time)) / (float) CLOCKS_PER_SEC;
    if((((float) (clock() - start_clock_time)) / (float) CLOCKS_PER_SEC) >= time / 1000){

        enable = false;

        if(reset_at_end){
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
