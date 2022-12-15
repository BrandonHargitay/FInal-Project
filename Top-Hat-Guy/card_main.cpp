//
// Created by Sherman Yan on 10/19/22.
//
#include "topHatGuy.h"

int main(){
    sf::RenderWindow window({1000,1000,32},"Card");
    window.setFramerateLimit(60);
    topHatGuy t;
    t.setPosition(459,459);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if (sf::Event::Closed == event.type)
                window.close();
        }

        window.clear();
        window.draw(t);
        window.display();
    }
    return 0;
}