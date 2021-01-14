#pragma once
#include "Behavior.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

/*
*		TopDown sýnýfý Behavior sýnýfýndan türetilmiþtir.
*	Bir davranýþtýr. 
*		Eklendiði varlýðýn	klavye kontrolleri ile hareket 
*	ettirilebilmesini saðlar.
*		Ýçerisinde bulunan Entity* entity deðiþkeni ile,
*	etki ettiði sýnýfa eriþebilir. Entity sýnýfýnda, TopDown
*	sýnýfý friend sýnýf olarak tanýmlandýðý için, movementSpeed
*	gibi deðiþkenlere eriþerek varlýðýn pozisyonunu güncellemekle
*	yükümlüdür. 
*/

class TopDown : public Behavior{
public:
	TopDown(Entity *entity);

	/* Kullanýcý girdilerini alýr ve hareket vektörlerine
	   göre etki ettiði varlýðý hareket ettirir. */
	void update(float dt);

private:
	// TODO: Kontrolleri deðiþtirilebilir olarak yap.
	/* Kontroller varsayýlan olarak W,A,S,D tuþlarý
	   ile kontrol edilir.*/
	bool defaultControls = true;

	/* W,A,S,D tuþlarýna basma durumlarýna göre etki
	   ettiði varlýðýn hareket vektörlerini günceller. */
	void handlePlayerInput();
};

