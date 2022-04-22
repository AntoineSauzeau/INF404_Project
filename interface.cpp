#include "interface.hpp"

Interface::Interface(Window *window_abstract_object) {

    std::cout << window_abstract_object->GetWidth() << window_abstract_object->GetHeight();
    window = new sf::RenderWindow(sf::VideoMode(500, 500), "Interface");
    this->window_abstract_object = window_abstract_object;
}

void Interface::TreatEvents() {

    while (window->isOpen())
    {

        std::cout << "dqs";

        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window->pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }
}

void Interface::Draw() {
    
    window->clear();

    RecDraw(window_abstract_object);

    window->display();
}

void Interface::RecDraw(Object* object) {

    for(std::vector<Object*>::iterator child = object->GetChildrens()->begin(); child != object->GetChildrens()->end(); child++){
        
        (*child)->Draw();
        RecDraw((*child));
    }
}