#pragma once
#include "Behavior.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

class Platform : public Behavior{
public:
	Platform(Entity* entity);

	/* Kullan�c� girdilerini al�r ve hareket vekt�rlerine
	   g�re etki etti�i varl��� hareket ettirir. */
	void update(float dt);
	bool checkCollision(Entity& e1, Entity& e2);
	bool checkCollision(sf::Sprite e1, sf::Sprite e2);
	sf::Vector2f normalize(sf::Vector2f source);

private:
	// TODO: Kontrolleri de�i�tirilebilir olarak yap.
	/* Kontroller varsay�lan olarak W,A,S,D tu�lar�
	   ile kontrol edilir.*/

	/* W,A,S,D tu�lar�na basma durumlar�na g�re etki
	   etti�i varl���n hareket vekt�rlerini g�nceller. */
	void handlePlayerInput();
	bool canJump;
	/* Bir sonraki frame'de varl���n yerini bulur. */
	sf::Sprite getNextFrameSprite(float dt);
};

