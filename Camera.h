#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics/View.hpp>
#include <iostream>
#include "Globals.h"

/* 
*       Bu s�n�f kullan�c�n�n ekran g�rmek istedi�i alanlar�
*   g�rebilmesi ve g�r�� pozisyonunu g�ncellemesini sa�lar. 
*/
class Camera{
public:
    Camera();

    /* Kameray� parametre olarak gelen pozisyona ta��r.
       E�er g�r�� alan� d���ndaki bir alan g�r�nt�lenmek
       istenirse bu engellenir ve kamera pozisyonu ilgili
       pozisyona en yak�n pozisyon olarak g�ncellenir.*/
    void update(sf::Vector2f);

    /* Kameran�n g�rd��� alan� geri d�nd�r�r. 
       Her bir pencerenin bir view'� vard�r ve ilgili
       pencereye bu view atamas� ger�ekle�tirilmez ise
       kamera do�ru �al��maz. */
    sf::View getView();

    /* Kameran�n g�r�lebilir alan �l�eklendirmesi
       yeniden yap�l�r. Pencere boyutland�rmas� gibi
       durumlarda bu fonksiyonun tetiklenmesi gerekir. */
    void reset();
private:
    /* Bir �nceki kareye ait pencere kenarlar�n� tutar. */
    sf::VideoMode lastWindowBounds;

    /* Kameran�n g�r�lebilir alan bilgilerini tutar. */
    sf::View view;

    /* Kameran�n pozisyonunu tutar. */
    sf::Vector2f position;
};

