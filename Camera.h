#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics/View.hpp>
#include <iostream>
#include "Globals.h"


class Camera{
public:
    Camera();
    void update(sf::Vector2f);
    sf::View getView();
    void reset();
private:
    sf::VideoMode lastWindowBounds;
    sf::View view;
    sf::Vector2f position;
};

