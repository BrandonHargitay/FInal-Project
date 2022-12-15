//
// Created by Bradnon Hargitay on 10/10/22.
//

#include "ball.h"
ball::ball(float radius){
    sf::CircleShape::setRadius(radius);

    buffer.loadFromFile("Ping-Pong-Game/src/assets_beep.ogg");
    sound.setBuffer(buffer);
}
void ball::setVelocity(sf::Vector2f velocity)
{
    this->velocity = velocity;
}
void ball::bounce(const sf::Vector2u& windowSize, sf::FloatRect leftPaddle, sf::FloatRect rightPaddle)
{
    sf::FloatRect b = getGlobalBounds();
    if (b.top + b.height >= windowSize.y || b.top <= 0)
    {
        sound.play();
        velocity.y = -velocity.y;
    }

    if(rightPaddle.intersects(getGlobalBounds()))
    {
        sound.play();
        velocity.x = -velocity.x;
        changeColor();
        std::cout << "Collision";
    }
    if(leftPaddle.intersects(getGlobalBounds()))
    {
        sound.play();
        velocity.x = -velocity.x;
        changeColor();
        std::cout << "Collision";
    }

    sf::CircleShape::move(velocity);
}
void ball::changeColor(){
    sf::Color color(
            rand() % 256,
            rand() % 256,
            rand() % 256
    );
    setFillColor(color);
}


