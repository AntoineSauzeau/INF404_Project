#include "animation_handler.hpp"

AnimationHandler::AnimationHandler() {

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
                (*a)->Update();
            }
        }

        interface->Draw();

        clock_t end = clock();
        double time_elapsed = (end - start) / CLOCKS_PER_SEC;
        if(time_elapsed < (1./6)){
            std::this_thread::sleep_for(std::chrono::milliseconds((int) ((1./6 - time_elapsed) * 1000)));
        }
    }
}

void AnimationHandler::AddAnimation(Animation *animation) {
    l_animation.push_back(animation);
}

void AnimationHandler::AttachInterface(ProgInterface *interface) {
    this->interface = interface;
}