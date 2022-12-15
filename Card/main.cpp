#include <iostream>
#include "Card.h"

int main() {
    sf::RenderWindow window({1920, 1080, 32},"Top Hat Guy");
    window.setFramerateLimit(60);
    Card c(SPADES, TEN);
    //Card c2(HEARTS, ACE);
    //c2.setPosition({500,30});
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                window.close();
//            switch (event.type) {
//                case sf::Event::MouseButtonPressed:
//                    std::cout << "Mouse has been clicked" << std::endl;
//                    switch (event.key.code) {
//                        case sf::Mouse::Left:
//                            std::cout << "LEFT KEY PRESSED";
//                            //c.setOrigin(100,100);
//                            c.setPosition({(float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y});
//                            //c.setPosition({500.f, 40.f});
//                            //c.setCardPosition({500.f,10.f});
//                    }
//            }
        }
        c.setPosition({800.f,300.f});
        window.clear(sf::Color(50,168,82));
        window.draw(c);
        //window.draw(c2);
        window.display();
    }
}
