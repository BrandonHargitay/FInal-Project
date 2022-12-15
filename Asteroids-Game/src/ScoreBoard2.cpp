//
// Created by Brandon Hargitay on 10/12/22.
//

#include "ScoreBoard2.h"

ScoreBoard2::ScoreBoard2(){
    scoreBoardPosition.x = 0;
    scoreBoardPosition.y = 0;
}
ScoreBoard2::ScoreBoard2(sf::Vector2f poistion){
    scoreBoardPosition.x = poistion.x;
    scoreBoardPosition.y = poistion.y;
    font.loadFromFile("Asteroids-Game/Fonts/Pixellari.ttf");
    sf::Text::setFont(font);

}
void ScoreBoard2::setScoreBoard(){
    sf::Text::setString("Score: ");
    sf::Text::setPosition(scoreBoardPosition);
    sf::Text::setCharacterSize(40);
}
void ScoreBoard2::updateScoreBoard(int score){

    std::string num = "Score: " + std::to_string(score);
    sf::Text::setString(num);
}