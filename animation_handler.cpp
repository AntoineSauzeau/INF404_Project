#include "animation_handler.hpp"

AnimationHandler::AnimationHandler() {

}

AnimationHandler::~AnimationHandler(){
    delete thread;

    for(std::vector<Animation *>::iterator a = l_animation.begin(); a != l_animation.end(); a++){
        delete (*a);
    }
}   

void AnimationHandler::StartAnimationHandling(){
    thread = new std::thread(&AnimationHandler::Run, this);
    thread->detach();
}

void AnimationHandler::Run() {

    while(1){

        clock_t start = clock();

        for(std::vector<Animation *>::iterator a = l_animation.begin(); a != l_animation.end(); a++){

            if((*a)->IsEnable() || (*a)->IsInBreak()){
                (*a)->Update(N_UPDATE_PER_SECOND);
            }
        }

        interface->Draw();

        clock_t end = clock();
        double time_elapsed = (end - start) / CLOCKS_PER_SEC;
        if(time_elapsed < (1./N_UPDATE_PER_SECOND)){
            std::this_thread::sleep_for(std::chrono::milliseconds((int) ((1./N_UPDATE_PER_SECOND - time_elapsed) * 1000)));
        }
    }
}

void AnimationHandler::Event(sf::Event *event) {

    if(event->type == sf::Event::MouseButtonReleased){

        for(std::vector<Animation *>::iterator a = l_animation.begin(); a != l_animation.end(); a++){

            if((*a)->GetEventType() != type_animation_event::ONCLICK){
                continue;
            }

            Object* object = (*a)->GetObject();
            sf::FloatRect bounds;

            switch (object->GetType())
            {
            case type_object::RECT:
                bounds = ((Rect *) object)->GetBounds();
                break;
            case type_object::CIRCLE:
                bounds = ((Circle *) object)->GetBounds();
                break;
            case type_object::TRIANGLE:
                bounds = ((Triangle *) object)->GetBounds();
                break;
            case type_object::IMAGE:
                bounds = ((Image *) object)->GetBounds();
                break;
            case type_object::TEXT:
                bounds = ((Text *) object)->GetBounds();
                break;
            
            default:
                break;
            }

            double x = object->GetX();
            double y = object->GetY();

            if(bounds.contains(sf::Vector2f(x, y))){
                (*a)->Run();
            }
        }
    }
}

void AnimationHandler::AddAnimation(Animation *animation) {
    l_animation.push_back(animation);
}

void AnimationHandler::AttachInterface(ProgInterface *interface) {
    this->interface = interface;
}