#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Entity.h"

/*
*		Globals sýnýfý, yaygýn olarak kullanýlan 
*	deðiþkenlerin eriþebileceði deðiþkenleri tutar.
*		Bu dosyada tutulan extern anahtar kelimesi ile
*	belirtilmiþ globals deðiþkeni ile bu dosyayý dahil 
*	eden bütün dosyalar bu deðiþkenlere eriþebilir.
*/
class Globals{
public:
	Globals();

	// Getters
	/* Pencerenin boyutlarýný döndürür. */
	sf::VideoMode getWindowBounds();

	/* Yüklenen haritanýn katman boyutunu döndürür. */
	sf::Vector2f getLayoutSize();

	/* Mevcut state'teki varlýklarý döndürür. */
	std::vector< Entity * > *getCurrentEntities();

	// Setters
	/* Pencere güncellendiðinde bu fonksiyon tetiklenir. 
	   Yeni pencere boyutlarý ile güncellemek için kullanýlýr. */
	void setWindowBounds(sf::VideoMode windowBounds);

	/* Harita yüklendiðinde bu fonksiyon tetiklenir.
	   Yeni harita boyutlarý ile güncellemek için kullanýlýr. */
	void setLayoutSize(sf::Vector2f layoutSize);

	/* Mevcut varlýklarý setler. */
	void setCurrentEntities(std::vector< Entity * > *currentEntities);
private:
	/* Pencere boyutlarýný tutar. */
	sf::VideoMode windowBounds;

	/* Harita boyutlarýný tutar. */
	sf::Vector2f layoutSize;

	/* Mevcut state'teki varlýklarýn referansýný tutar. */
	std::vector< Entity * > *currentEntities;

};

extern Globals globals;


