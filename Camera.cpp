#include "Camera.h"

Camera::Camera(){
    this->reset();
}

void Camera::update(sf::Vector2f pos){
    sf::VideoMode windowBounds(globals.getWindowBounds());
    sf::Vector2f layoutSize(globals.getLayoutSize());

    if(this->lastWindowBounds.width != windowBounds.width ||
       this->lastWindowBounds.height != windowBounds.height){
       
        this->reset();
        this->lastWindowBounds.width = windowBounds.width;
        this->lastWindowBounds.height = windowBounds.height;
    }
    //std::cout << pos.x << " " << pos.y << "  " << layoutSize.x << "-" << layoutSize.y << std::endl;
    if(pos.x > windowBounds.width / 2.f && pos.x < layoutSize.x - windowBounds.width / 2.f)
        position.x = pos.x;
    else if(pos.x < windowBounds.width / 2.f)
        position.x = windowBounds.width / 2.f;
    else
        position.x = layoutSize.x - windowBounds.width / 2.f;

    if(pos.y > windowBounds.height / 2.f && pos.y < layoutSize.y - windowBounds.height / 2.f)
        position.y = pos.y;
    else if(pos.y < windowBounds.height / 2.f)
        position.y = windowBounds.height / 2.f;
    else
        position.y = layoutSize.y - windowBounds.height / 2.f;

    //std::cout << position.x << "  " << position.y << std::endl;
    view.setCenter(position);
}

sf::View Camera::getView(){
    return view;
}

void Camera::reset(){
    sf::VideoMode windowBounds(globals.getWindowBounds());
    view.reset(sf::FloatRect(0, 0, windowBounds.width, windowBounds.height));
    view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

    position.x = windowBounds.width / 2.f;
    position.y = windowBounds.height / 2.f;
}
