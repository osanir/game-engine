#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

/*
*		Oyunda ekrana çizdirilen bürün varlýklar bu 
*	sýnýftan türetilir. Bu sýnýftan türetilen yeni sýnýflar
*	update fonksiyonunu override ederek yeniden yazmalýdýr.
*		Her bir entity (varlýk) ekrana çizdirilebilirdir ve hareket,
*	kaplama, açý, çarpýþma gibi ortak özelliklere sahiptir.
*		Kullanýcý yeni bir obje eklemek istediði zaman, 
*	ilgili varlýðýn sahip olmasýný istediði kaplamanýn
*	adýný vermesi yeterlidir. Ýlgili kaplama Resources dizini
*	altýndan bulunabilir olacak þekilde tasarlanmýþtýr.
*/

class Entity : public sf::Drawable{
public:
	Entity();
	Entity(sf::Vector2f position, sf::Vector2f size, sf::Color color, float speed);
	Entity(std::string fileName, float speed = 200, sf::Vector2f position = {0,0}, sf::Vector2f scale = {1,1});
	
	/* Her bir kalýtýlan sýnýfýn yazmasý gereken
	   update fonksiyonu. */
	virtual void update(float dt) = 0;

	/* Ýlgili objenin katý olma durumudur. Doðruysa katýdýr. */
	bool isSolid;
	/* Ýlgili objenin mermi olma durumudur. Doðruysa mermidir. */
	bool isBullet;

	// Collision
	/* Ýki entity arasýndaki çarpýþmaý kontrol eder.
	   Çarpýþma varsa true, yoksa false döndürür.
		   Entity e1;
		   e1.onCollision(e2)
	   þeklinde kullanýlýr.*/
	bool onCollision(Entity& entity);
	
	// Getters
	/* Varlýðýn hareket vektörünü döndürür. */
	sf::Vector2f getMovement();
	/* Varlýðýn hareket hýzýný döndürür. */
	float getMovementSpeed();
	/* Varlýðýn sprite'ýný döndürür.*/
	sf::Sprite getSprite();
	/* Varlýðýn pozisyonunu döndürür. */
	sf::Vector2f getPosition();
	/* Varlýðýn boyutunu döndürür. */
	sf::Vector2u getSize();
	/* Varlýðýn açýsýný döndürür. */
	float getAngle();
	/* Varlýðýn ID'sini döndürür. */
	unsigned int getID();

	// Setters
	/* Varlýðýn hareket vektörünü günceller. */
	void setMovement(sf::Vector2f movement);
	/* Varlýðýn hareket hýzýný günceller. */
	void setMovementSpeed(float movementSpeed);
	/* Varlýðýn pozisyonunu günceller. */
	void setPosition(sf::Vector2f newPosition);
	/* Varlýðýn belirli bir noktaya doðru açýsýný günceller. */
	void setRotationTowardPosition(sf::Vector2i towardPosition);
	/* Varlýðýn açýsýný günceller. */
	void setAngle(float angle);
	/* ID bilgisini günceller. */
	void setID(unsigned int id);

	// MISC
	/* Varlýðý bulunduðu pozisyona göre öteler. */
	void move(sf::Vector2f move);
	/* Bulunduðu konumda bir baþka varlýk oluþturur. */
	void spawnAnotherObject(Entity* entity);
	/* Varlðýý yok eder. */
	void destroy();
	
private:
	unsigned int uid;
	/* Varlýðýn hareket vektörünü tutar. */
	sf::Vector2f movement;

	/* Varlýðýn hareket hýzýný tutar. */
	float movementSpeed;
	// TODO: Acceleration, deceleration eklenecek. 

	/* sf::Drawable sýnýfýndan türetildiði için yazýlmasý
	   zorunlu çizim fonksiyonu. entity'den türetilen 
	   her obje bu fonksiyona sahiptir. */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/* Varlýðýn kaplamasýný tutar. */
	sf::Texture* texture;
	/* Varlýðý somut bir hale getirmek için oluþturulur. */
	sf::Sprite shape;

	// Friends
	/* Friend sýnýflar bu sýnýfýn private ile korunan
	   deðiþkenlerine ve fonksiyonlarýna eriþebilir. 
	   Yeni eklenecek bütün Behavior sýnýfýndan kalýtýlan
	   sýnýflar buraya eklenecek. */
	friend class TopDown;
	friend class ScrollTo;
	friend class Bullet;
};

