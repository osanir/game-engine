#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics/View.hpp>
#include <iostream>
#include "Globals.h"

/* 
*       Bu sýnýf kullanýcýnýn ekran görmek istediði alanlarý
*   görebilmesi ve görüþ pozisyonunu güncellemesini saðlar. 
*/
class Camera{
public:
    Camera();

    /* Kamerayý parametre olarak gelen pozisyona taþýr.
       Eðer görüþ alaný dýþýndaki bir alan görüntülenmek
       istenirse bu engellenir ve kamera pozisyonu ilgili
       pozisyona en yakýn pozisyon olarak güncellenir.*/
    void update(sf::Vector2f);

    /* Kameranýn gördüðü alaný geri döndürür. 
       Her bir pencerenin bir view'ý vardýr ve ilgili
       pencereye bu view atamasý gerçekleþtirilmez ise
       kamera doðru çalýþmaz. */
    sf::View getView();

    /* Kameranýn görülebilir alan ölçeklendirmesi
       yeniden yapýlýr. Pencere boyutlandýrmasý gibi
       durumlarda bu fonksiyonun tetiklenmesi gerekir. */
    void reset();
private:
    /* Bir önceki kareye ait pencere kenarlarýný tutar. */
    sf::VideoMode lastWindowBounds;

    /* Kameranýn görülebilir alan bilgilerini tutar. */
    sf::View view;

    /* Kameranýn pozisyonunu tutar. */
    sf::Vector2f position;
};

