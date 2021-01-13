#include "Camera.h"

Camera::Camera(){
    view.reset(sf::FloatRect(0, 0, 854, 480));
    view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

    position.x = 854 / 2;
    position.y = 480 / 2;
}

void Camera::update(sf::Vector2f pos){
    if(pos.x > 854 / 2)
        position.x = pos.x;
    else
        position.x = 854 / 2;

    if(pos.y > 480 / 2)
        position.y = pos.y;
    else
        position.y = 480 / 2;

    //std::cout << position.x << "  " << position.y << std::endl;
    view.setCenter(position);
}

sf::View Camera::getView(){
    return view;
}