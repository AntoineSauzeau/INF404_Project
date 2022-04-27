#include "interface.hpp"

ProgInterface::ProgInterface(Window *window_abstract_object, sf::RenderWindow *window, AnimationHandler *animation_handler) 
{
    this->window = window;
    this->window_abstract_object = window_abstract_object;
    this->animation_handler = animation_handler;
}

void ProgInterface::TreatEvents() {

    while (window->isOpen())
    {

        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window->waitEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window->close();

            animation_handler->Event(&event);
        }
    }
}

void ProgInterface::Draw() {
    
    window->clear();

    window_abstract_object->Draw(window);
    this->RecDraw(window_abstract_object);

    window->display();
}

void ProgInterface::RecDraw(Object *object) {

    for(std::vector<Object*>::iterator child = object->GetChildrens()->begin(); child != object->GetChildrens()->end(); child++){
        
        switch ((*child)->GetType())
        {
        case type_object::RECT:
            ((Rect *) (*child))->Draw(window);
            break;
        case type_object::CIRCLE:
            ((Circle *) (*child))->Draw(window);
            break;
        case type_object::TRIANGLE:
            ((Triangle *) (*child))->Draw(window);
            break;
        case type_object::IMAGE:
            ((Image *) (*child))->Draw_(window);
            break;
        case type_object::TEXT:
            ((Text *) (*child))->Draw(window);
            break;
        default:
            break;
        }

        RecDraw((*child));
    }
}