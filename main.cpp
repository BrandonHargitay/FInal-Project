//
// Created by Brandon Hargitay on 12/13/22.
//
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

int main()
{
    sf::Font font;
    sf::RenderWindow window(sf::VideoMode(1080, 780), "SFML works!");
    sf::Text name;
    sf::Text crn;
    sf::Text classNum;
    font.loadFromFile("Asteroids-Game/Fonts/Pixellari.ttf");
    name.setFont(font);
    crn.setFont(font);
    classNum.setFont(font);

    name.setString("Brandon Hargitay");
    crn.setString("CRN: 72623");
    classNum.setString("CS-003A");

    name.setPosition(800,30);
    crn.setPosition(800, 70);
    classNum.setPosition(800, 110);

    MainMenu m;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            m.click(window);
        }

        window.clear({111,121,133});
        window.draw(m);
        window.draw(name);
        window.draw(crn);
        window.draw(classNum);
        window.display();
    }

    return 0;
}


