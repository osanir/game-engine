#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics/View.hpp>
#include <iostream>
class Camera{
public:
    Camera();
    void update(sf::Vector2f);
    sf::View getView();
private:
    sf::View view;
    sf::Vector2f position;
};

