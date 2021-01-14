#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Globals.h"

/*
*		Oyunda ekrana �izdirilen b�r�n varl�klar bu 
*	s�n�ftan t�retilir. Bu s�n�ftan t�retilen yeni s�n�flar
*	update fonksiyonunu override ederek yeniden yazmal�d�r.
*		Her bir entity (varl�k) ekrana �izdirilebilirdir ve hareket,
*	kaplama, a��, �arp��ma gibi ortak �zelliklere sahiptir.
*		Kullan�c� yeni bir obje eklemek istedi�i zaman, 
*	ilgili varl���n sahip olmas�n� istedi�i kaplaman�n
*	ad�n� vermesi yeterlidir. �lgili kaplama Resources dizini
*	alt�ndan bulunabilir olacak �ekilde tasarlanm��t�r.
*/

class Entity : public sf::Drawable{
public:
	Entity();
	Entity(sf::Vector2f position, sf::Vector2f size, sf::Color color, float speed);
	Entity(std::string fileName, float speed = 200, sf::Vector2f position = {0,0}, sf::Vector2f scale = {1,1});
	
	/* Her bir kal�t�lan s�n�f�n yazmas� gereken
	   update fonksiyonu. */
	virtual void update(float dt) = 0;

	/* �lgili objenin kat� olma durumudur. Do�ruysa kat�d�r. */
	bool isSolid;

	// Collision
	/* �ki entity aras�ndaki �arp��ma� kontrol eder.
	   �arp��ma varsa true, yoksa false d�nd�r�r.
		   Entity e1;
		   e1.onCollision(e2)
	   �eklinde kullan�l�r.*/
	bool onCollision(Entity& entity);
	
	// Getters
	/* Varl���n sprite'�n� d�nd�r�r.*/
	sf::Sprite getShape();
	/* Varl���n pozisyonunu d�nd�r�r. */
	sf::Vector2f getPosition();
	/* Varl���n boyutunu d�nd�r�r. */
	sf::Vector2u getSize();

	// Setters
	/* Varl���n hareket vekt�r�n� g�nceller. */
	void setMovement(sf::Vector2f movement);
	/* Varl���n hareket h�z�n� g�nceller. */
	void setMovementSpeed(float movementSpeed);
	/* Varl���n pozisyonunu g�nceller. */
	void setPosition(sf::Vector2f newPosition);
	/* Varl���n belirli bir noktaya do�ru a��s�n� g�nceller. */
	void setRotationTowardPosition(sf::Vector2i towardPosition);

	/* Varl��� bulundu�u pozisyona g�re �teler. */
	void move(sf::Vector2f move);
private:
	/* Varl���n hareket vekt�r�n� tutar. */
	sf::Vector2f movement;

	/* Varl���n hareket h�z�n� tutar. */
	float movementSpeed;
	// TODO: Acceleration, deceleration eklenecek. 

	/* sf::Drawable s�n�f�ndan t�retildi�i i�in yaz�lmas�
	   zorunlu �izim fonksiyonu. entity'den t�retilen 
	   her obje bu fonksiyona sahiptir. */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/* Varl���n kaplamas�n� tutar. */
	sf::Texture* texture;
	/* Varl��� somut bir hale getirmek i�in olu�turulur. */
	sf::Sprite shape;

	// Friends
	/* Friend s�n�flar bu s�n�f�n private ile korunan
	   de�i�kenlerine ve fonksiyonlar�na eri�ebilir. 
	   Yeni eklenecek b�t�n Behavior s�n�f�ndan kal�t�lan
	   s�n�flar buraya eklenecek. */
	friend class TopDown;
	friend class ScrollTo;
};
