//
// Created by Brandon Hargitay on 11/22/22.
//

#include "Texture.h"
std::map<textureEnum, sf::Texture> Texture::map;

void Texture::load(textureEnum texture) {
    map[texture].loadFromFile(getPath(texture));
}

std::string Texture::getPath(textureEnum texture) {
    switch(texture){
        case ROCKET: return "Asteroids-Game/Images/Rocket.png";
        case ROCKET2: return "Asteroids-Game/Images/Main Ship - Base - Full health.png";
        case ASTEROIDS: return "Asteroids-Game/Images/asteriods.png";
        case ASTEROIDPIXEL: return "Asteroids-Game/Images/Baren.png";
        case BULLET: return "Asteroids-Game/Images/Bullet.png";
        case BACKGROUND: return "Asteroids-Game/Images/Space_Stars2.png";
        case HEART: return  "Asteroids-Game/Images/Heart.png";
        case LAST_TEXTURE: return "";
    }
}

sf::Texture &Texture::getTexture(textureEnum texture) {
    load(texture);
    return map[texture];
}
