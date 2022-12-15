//
// Created by Brandon Hargitay on 11/22/22.
//

#ifndef CLASSEXAMPLE1122_FONTS_H
#define CLASSEXAMPLE1122_FONTS_H

#include "fontsEnum.h"
#include <SFML/Graphics.hpp>
#include <map>
class Fonts {
private:
    static std::map<fontsEnum, sf::Font> map;
    static void load(fontsEnum font);
    static std::string getPath(fontsEnum font);
public:
    static sf::Font& getFont(fontsEnum font);
};


#endif //CLASSEXAMPLE1122_FONTS_H
