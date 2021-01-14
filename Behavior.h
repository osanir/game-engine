#pragma once
#include "Entity.h"

/*
*		Bu sýnýf varlýklarýn sahip olduðu davranýþlarý
*	oluþturan sýnýftýr. Yeni bir davranýþ eklenmek isterse bu 
*	sýnýftan türetilmelidir. 
*		Her bir behavior (davranýþ) etki ettiði varlýðý
*	kendi içinde tutmalýdýr. 
*		Örneðin, TopDown adlý sýnýf bu sýnýftan türetilmiþ
*	bir davranýþtýr. TopDown sýnýfý, eklendiði varlýðýn
*	klavye kontrolleri ile hareket ettirilebilmesini saðlar.
*	TopDown sýnýfý, içerisinde bulunan Entity* entity deðiþkeni
*	ile, etki ettiði sýnýfa eriþebilir. Entity sýnýfýnda TopDown
*	sýnýfý friend sýnýf olarak tanýmlandýðý için, movementSpeed
*	gibi deðiþkenlere eriþerek varlýðýn pozisyonunu güncellemekle
*	yükümlüdür. 
*/

class Behavior{
public:
	/* Bir behavior oluþturulduðunda ilgili entity 
	   parametre olarak verilmelidir. 
	   TopDown(this) þeklinde*/
	Behavior(Entity *entity);

	/* Etki ettiði varlýðýn referansýný tutar. */
	Entity* entity;

	/* Davranýþ etkileri update sýnýfýnda gerçekleþir. */
	virtual void update(float dt) = 0;
private:

};

