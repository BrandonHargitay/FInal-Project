//
// Created by Brandon Hargitay on 10/12/22.
//

#ifndef UNTITLED_SCOREBOARD_H
#define UNTITLED_SCOREBOARD_H
#include <SFML/Graphics.hpp>


class ScoreBoard2 : public sf::Text {
private:
    sf::Vector2f scoreBoardPosition;
    sf::Font font;

public:
    ScoreBoard2();
    ScoreBoard2(sf::Vector2f scoreBoardPosition);
    void setScoreBoard();
    void updateScoreBoard(int score);
};


#endif //UNTITLED_SCOREBOARD_H
