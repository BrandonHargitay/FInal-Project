//
// Created by Brandon Hargitay on 12/14/22.
//

#include "Top_Hat_Guy_Runner.h"
#include "topHatGuy.h"
void Top_Hat_Guy_Runner::run() {
    sf::RenderWindow window({1300,1000,32},"Card");
    window.setFramerateLimit(60);
    topHatGuy t;
    t.setPosition(459,459);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if (sf::Event::Closed == event.type)
                window.close();
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)){
                window.close();
            }
        }

        window.clear();
        window.draw(t);
        window.display();
    }
}
