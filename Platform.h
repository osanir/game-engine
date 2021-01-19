#pragma once
#include "Behavior.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

class Platform : public Behavior{
public:
	Platform(Entity* entity);

	/* Kullanýcý girdilerini alýr ve hareket vektörlerine
	   göre etki ettiði varlýðý hareket ettirir. */
	void update(float dt);
	bool checkCollision(Entity& e1, Entity& e2);
	bool checkCollision(sf::Sprite e1, sf::Sprite e2);
	sf::Vector2f normalize(sf::Vector2f source);

private:
	// TODO: Kontrolleri deðiþtirilebilir olarak yap.
	/* Kontroller varsayýlan olarak W,A,S,D tuþlarý
	   ile kontrol edilir.*/

	/* W,A,S,D tuþlarýna basma durumlarýna göre etki
	   ettiði varlýðýn hareket vektörlerini günceller. */
	void handlePlayerInput();
	bool canJump;
	/* Bir sonraki frame'de varlýðýn yerini bulur. */
	sf::Sprite getNextFrameSprite(float dt);
};

