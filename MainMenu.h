//
// Created by Brandon Hargitay on 12/14/22.
//

#ifndef FINAL_PROJECT_MAINMENU_H
#define FINAL_PROJECT_MAINMENU_H
#include "GameSquare.h"

class MainMenu : public sf::Drawable {
public:
    MainMenu();
    void click(sf::RenderWindow &window);
private:
    GameSquare asteroid;
    GameSquare card;
    GameSquare greenCircle;
    GameSquare pingPong;
    GameSquare poker;
    GameSquare playingCard;
    GameSquare topHatGuy;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //FINAL_PROJECT_MAINMENU_H
