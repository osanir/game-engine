#pragma once
#include "Entity.h"

/*
*		Bu s�n�f varl�klar�n sahip oldu�u davran��lar�
*	olu�turan s�n�ft�r. Yeni bir davran�� eklenmek isterse bu 
*	s�n�ftan t�retilmelidir. 
*		Her bir behavior (davran��) etki etti�i varl���
*	kendi i�inde tutmal�d�r. 
*		�rne�in, TopDown adl� s�n�f bu s�n�ftan t�retilmi�
*	bir davran��t�r. TopDown s�n�f�, eklendi�i varl���n
*	klavye kontrolleri ile hareket ettirilebilmesini sa�lar.
*	TopDown s�n�f�, i�erisinde bulunan Entity* entity de�i�keni
*	ile, etki etti�i s�n�fa eri�ebilir. Entity s�n�f�nda TopDown
*	s�n�f� friend s�n�f olarak tan�mland��� i�in, movementSpeed
*	gibi de�i�kenlere eri�erek varl���n pozisyonunu g�ncellemekle
*	y�k�ml�d�r. 
*/

class Behavior{
public:
	/* Bir behavior olu�turuldu�unda ilgili entity 
	   parametre olarak verilmelidir. 
	   TopDown(this) �eklinde*/
	Behavior(Entity *entity);

	/* Etki etti�i varl���n referans�n� tutar. */
	Entity* entity;

	/* Davran�� etkileri update s�n�f�nda ger�ekle�ir. */
	virtual void update(float dt) = 0;
private:

};

