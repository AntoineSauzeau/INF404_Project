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

    if((*l_property)["repeat"] == "true") {
        repeat = true;
    }
    else if((*l_property)["repeat"] == "false"){
        repeat = false;
    }


    break_time = std::stof((*l_property)["break_time"]);

    if(type == COLOR) {
        new_color = Object::GetColorFromName((*l_property)["new_color"]);
    }

    time = std::stoi((*l_property)["time"]);

    if(event == NONE){
        Run();
    }
}

void Animation::Run() {

    start_time = std::chrono::high_resolution_clock::now();
    enable = true;

    if(type == COLOR) {
        old_color = object->GetColor();
        object->SetColor(new_color);
    }
}

void Animation::Update() {

    int time_elapsed;
    std::chrono::high_resolution_clock::time_point time_now = std::chrono::high_resolution_clock::now();

    time_elapsed = std::chrono::duration_cast<std::chrono::seconds> (time_now - break_start_time).count();
    if(in_break){
        if(time_elapsed < break_time){
            return;
        }
        else{
            in_break = false;
            std::cout << "d";
            Run();
        }
    }

    time_elapsed = std::chrono::duration_cast<std::chrono::seconds> (time_now - start_time).count();
    if(time_elapsed >= time){

        enable = false;

        if(reset_at_end){
            Reset();
        }

        if(repeat){
            if(break_time == 0){
                Run();
            }
            else{
                in_break = true;
                break_start_time = std::chrono::high_resolution_clock::now();
            }
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

bool Animation::IsInBreak() {
    return in_break;;
}