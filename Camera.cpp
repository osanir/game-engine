#include "Camera.h"

Camera::Camera(){
    this->reset();
}

void Camera::update(sf::Vector2f pos){
    // Pencere boyutu ve katman boyutu global olarak al�n�r.
    sf::VideoMode windowBounds(globals.getWindowBounds());
    sf::Vector2f layoutSize(globals.getLayoutSize());

    // Pencere boyutland�rmas� yap�ld�ysa g�r�� alan�n�n g�ncellenmesi gerekiyor.
    // Bu sebeple bir �nceki frame ile pencere boyutu ayn� m� kontrol� sa�lan�yor.
    // De�erler farkl� ise kamera resetleniyor ve view g�ncelleniyor.
    if(this->lastWindowBounds.width != windowBounds.width ||
       this->lastWindowBounds.height != windowBounds.height){
       
        this->reset();
        this->lastWindowBounds.width = windowBounds.width;
        this->lastWindowBounds.height = windowBounds.height;
    }

    //std::cout << pos.x << " " << pos.y << "  " << layoutSize.x << "-" << layoutSize.y << std::endl;
    
    /*
    * Kameran�n istenilen konuma ta��n�p ta��namayaca��n�n kontrol� yap�l�yor.
    * E�er verilen pozisyon g�r�n�r alan�n d���ndaysa kamera g�r�n�r alan�
    * g�sterecek �ekilde tekrar konumland�r�l�yor.
    */
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
    /* Pencrenin yeni boyutu al�n�r. */
    sf::VideoMode windowBounds(globals.getWindowBounds());
    
    /* Pencere boyutuna g�re g�r�n�r alan d�zenlenir. */
    view.reset(sf::FloatRect(0, 0, windowBounds.width, windowBounds.height));

    /* G�r�n�r alan�n �l�eklendirmesi yap�l�r. */
    view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

    /* Kamera pozisyonu ortalan�r. */
    position.x = windowBounds.width / 2.f;
    position.y = windowBounds.height / 2.f;
}
