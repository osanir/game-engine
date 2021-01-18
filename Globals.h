#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Entity.h"

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

	/* Mevcut state'teki varl�klar� d�nd�r�r. */
	std::vector< Entity * > *getCurrentEntities();

	// Setters
	/* Pencere g�ncellendi�inde bu fonksiyon tetiklenir. 
	   Yeni pencere boyutlar� ile g�ncellemek i�in kullan�l�r. */
	void setWindowBounds(sf::VideoMode windowBounds);

	/* Harita y�klendi�inde bu fonksiyon tetiklenir.
	   Yeni harita boyutlar� ile g�ncellemek i�in kullan�l�r. */
	void setLayoutSize(sf::Vector2f layoutSize);

	/* Mevcut varl�klar� setler. */
	void setCurrentEntities(std::vector< Entity * > *currentEntities);
private:
	/* Pencere boyutlar�n� tutar. */
	sf::VideoMode windowBounds;

	/* Harita boyutlar�n� tutar. */
	sf::Vector2f layoutSize;

	/* Mevcut state'teki varl�klar�n referans�n� tutar. */
	std::vector< Entity * > *currentEntities;

};

extern Globals globals;


