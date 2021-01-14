#pragma once
#include "Behavior.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

/*
*		TopDown s�n�f� Behavior s�n�f�ndan t�retilmi�tir.
*	Bir davran��t�r. 
*		Eklendi�i varl���n	klavye kontrolleri ile hareket 
*	ettirilebilmesini sa�lar.
*		��erisinde bulunan Entity* entity de�i�keni ile,
*	etki etti�i s�n�fa eri�ebilir. Entity s�n�f�nda, TopDown
*	s�n�f� friend s�n�f olarak tan�mland��� i�in, movementSpeed
*	gibi de�i�kenlere eri�erek varl���n pozisyonunu g�ncellemekle
*	y�k�ml�d�r. 
*/

class TopDown : public Behavior{
public:
	TopDown(Entity *entity);

	/* Kullan�c� girdilerini al�r ve hareket vekt�rlerine
	   g�re etki etti�i varl��� hareket ettirir. */
	void update(float dt);

private:
	// TODO: Kontrolleri de�i�tirilebilir olarak yap.
	/* Kontroller varsay�lan olarak W,A,S,D tu�lar�
	   ile kontrol edilir.*/
	bool defaultControls = true;

	/* W,A,S,D tu�lar�na basma durumlar�na g�re etki
	   etti�i varl���n hareket vekt�rlerini g�nceller. */
	void handlePlayerInput();
};

