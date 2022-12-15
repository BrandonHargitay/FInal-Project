//
// Created by Jessie Mejia on 11/22/22.
//

#ifndef CLASSEXAMPLE1122_MOUSEEVENTS_H
#define CLASSEXAMPLE1122_MOUSEEVENTS_H

#include <SFML/Graphics.hpp>

class MouseEvents {
public:
    template<class T>
    static bool isHover(const T& Obj , const sf::RenderWindow& window);

    template<class T>
    static bool isClick(const T& Obj , const sf::RenderWindow& window);

};

#include "MouseEvents.cpp"

#endif //CLASSEXAMPLE1122_MOUSEEVENTS_H
