#pragma once
#include "Behavior.h"
#include "Camera.h"

/*	
*		ScrollTo s�n�f� Behavior s�n�f�ndan t�retilmi�tir.
*	Bir davran��t�r.
*		Eklendi�i varl���n	her daim ekran ortas�nda 
*	g�r�nmesini sa�lar.
*		��erisinde bulunan Entity* entity de�i�keni ile,
*	etki etti�i s�n�fa eri�ebilir. Entity s�n�f�nda, ScrollTo
*	s�n�f� friend s�n�f olarak tan�mland��� i�in, pozisyon
*	gibi de�i�kenlere eri�erek varl���n pozisyonununa ba�l� 
*	olarak kamera pozisyonunu g�ncellemekle y�k�ml�d�r.
*/

class ScrollTo : public Behavior{
public:
	ScrollTo(Entity* entity);

	/* Kameran�n g�ncel pozisyonunu g�nceller ve 
	   pencereye ilgili kameran�n g�r���n� aktar�r. */
	void update(float dt);

	/* Etki edece�i karakterin bulundu�u pencerenin
	   referans�n� g�nceller. */
	void setWindow(sf::RenderWindow* window);
private:
	/* Kameran�n etki etti�i pencereyi tutar. */
	sf::RenderWindow* window;

	/* Hareket ettirilecek kamera tan�mlan�r. */
	Camera camera;
};

