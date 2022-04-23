#include "interface.hpp"

ProgInterface::ProgInterface(Window *window_abstract_object, sf::RenderWindow *window) 
{
    this->window = window;
    this->window_abstract_object = window_abstract_object;
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
        case RECT:
            ((Rect *) (*child))->Draw(window);
            break;
        case CIRCLE:
            ((Circle *) (*child))->Draw(window);
            break;
        case TRIANGLE:
            ((Triangle *) (*child))->Draw(window);

        default:
            break;
        }

        RecDraw((*child));
    }
}