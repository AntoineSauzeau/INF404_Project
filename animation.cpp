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
    else if((*l_property)["type"] == "rotation"){
        type = ROTATION;
    }

    if((*l_property)["event"] == "none"){
        event = NONE;
    }
    else if((*l_property)["event"] == "onclick"){
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

    if(repeat){
        break_time = std::stof((*l_property)["break_time"]);
    }

    if(type == COLOR) {
        new_color = Object::GetColorFromName((*l_property)["new_color"]);
    }
    else if(type == ROTATION){
        total_rotation_value = std::stof((*l_property)["total_rotation_value"]);
    }
    else if(type == SLIDE){
        slide_x = std::stoi((*l_property)["slide_x"]);
        slide_y = std::stoi((*l_property)["slide_y"]);
    }

    time = std::stof((*l_property)["time"]);

    if(event == NONE){
        Run();
    }
}

Animation::~Animation(){
    
}

void Animation::Run() {

    if(enable){
        return;
    }

    start_time = std::chrono::high_resolution_clock::now();
    enable = true;

    if(type == COLOR) {
        old_color = object->GetColor();
        object->SetColor(new_color);
    }
}

void Animation::Update(int n_update_per_second) {

    int time_elapsed;
    std::chrono::high_resolution_clock::time_point time_now = std::chrono::high_resolution_clock::now();

    time_elapsed = std::chrono::duration_cast<std::chrono::seconds> (time_now - break_start_time).count();
    if(in_break){
        if(time_elapsed >= break_time){
            in_break = false;
            Run();
        }

        return;
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

    if(type == ROTATION) {
        int rotation_value_per_update = floor(total_rotation_value / (time * n_update_per_second));
        object->Rotate(rotation_value_per_update);
    }

    if(type == SLIDE) {
        double slide_x_value_per_update = ((double) slide_x) / (time * n_update_per_second);
        double slide_y_value_per_update = ((double) slide_y) / (time * n_update_per_second);
        object->Translate(slide_x_value_per_update, slide_y_value_per_update);
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

Object *Animation::GetObject() {
    return object;
}

type_animation_event Animation::GetEventType() {
    return event;
}