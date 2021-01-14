#include "Camera.h"

Camera::Camera(){
    this->reset();
}

void Camera::update(sf::Vector2f pos){
    // Pencere boyutu ve katman boyutu global olarak alýnýr.
    sf::VideoMode windowBounds(globals.getWindowBounds());
    sf::Vector2f layoutSize(globals.getLayoutSize());

    // Pencere boyutlandýrmasý yapýldýysa görüþ alanýnýn güncellenmesi gerekiyor.
    // Bu sebeple bir önceki frame ile pencere boyutu ayný mý kontrolü saðlanýyor.
    // Deðerler farklý ise kamera resetleniyor ve view güncelleniyor.
    if(this->lastWindowBounds.width != windowBounds.width ||
       this->lastWindowBounds.height != windowBounds.height){
       
        this->reset();
        this->lastWindowBounds.width = windowBounds.width;
        this->lastWindowBounds.height = windowBounds.height;
    }

    //std::cout << pos.x << " " << pos.y << "  " << layoutSize.x << "-" << layoutSize.y << std::endl;
    
    /*
    * Kameranýn istenilen konuma taþýnýp taþýnamayacaðýnýn kontrolü yapýlýyor.
    * Eðer verilen pozisyon görünür alanýn dýþýndaysa kamera görünür alaný
    * gösterecek þekilde tekrar konumlandýrýlýyor.
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
    /* Pencrenin yeni boyutu alýnýr. */
    sf::VideoMode windowBounds(globals.getWindowBounds());
    
    /* Pencere boyutuna göre görünür alan düzenlenir. */
    view.reset(sf::FloatRect(0, 0, windowBounds.width, windowBounds.height));

    /* Görünür alanýn ölçeklendirmesi yapýlýr. */
    view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

    /* Kamera pozisyonu ortalanýr. */
    position.x = windowBounds.width / 2.f;
    position.y = windowBounds.height / 2.f;
}
