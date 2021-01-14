#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
/*
*		Globals s�n�f�, yayg�n olarak kullan�lan 
*	de�i�kenlerin eri�ebilece�i de�i�kenleri tutar.
*		Bu dosyada tutulan extern anahtar kelimesi ile
*	belirtilmi� globals de�i�keni ile bu dosyay� dahil 
*	eden b�t�n dosyalar bu de�i�kenlere eri�ebilir.
*/
class Globals{
public:
	Globals();

	// Getters
	/* Pencerenin boyutlar�n� d�nd�r�r. */
	sf::VideoMode getWindowBounds();

	/* Y�klenen haritan�n katman boyutunu d�nd�r�r. */
	sf::Vector2f getLayoutSize();

	// Setters
	/* Pencere g�ncellendi�inde bu fonksiyon tetiklenir. 
	   Yeni pencere boyutlar� ile g�ncellemek i�in kullan�l�r. */
	void setWindowBounds(sf::VideoMode windowBounds);

	/* Harita y�klendi�inde bu fonksiyon tetiklenir.
	   Yeni harita boyutlar� ile g�ncellemek i�in kullan�l�r. */
	void setLayoutSize(sf::Vector2f layoutSize);
private:
	/* Pencere boyutlar�n� tutar. */
	sf::VideoMode windowBounds;

	/* Harita boyutlar�n� tutar. */
	sf::Vector2f layoutSize;
};

extern Globals globals;


