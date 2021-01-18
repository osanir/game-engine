#pragma once
#include <iostream>
#include <vector>
#include <stack>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/View.hpp>

#include "Entity.h"
#include "Map.h"
#include "Camera.h"

/*
*		State s�n�f�, oyunda yeni bir sahne olu�turmak
*	istendi�i zaman �retilecek s�n�flar i�in bir Base 
*	s�n�ft�r. 
*		Her oyun sahnesi i�erisinde varl�klar�, kaplamalar�
*	ve haritay� tutmakla y�k�ml�d�r. 
*		sf::Drawable s�n�f�ndan t�retilmi�tir ve haritay�
*	ve varl�klar� bu fonksiyonda ekrana �izer.
*/

class State : public sf::Drawable{
public:
	State();
	virtual ~State();

	/* Mevcut state'i bitirmek isteyip istemedi�ini sorar. */
	const bool& getQuit() const;

	/* Mevcut state'i bitirmek i�in gerekli tu�lara bas�l�p
	   bas�lmad���n� kontrol eder. */
	virtual void checkForQuit();

	/* Mevcut state'i sonland�rmak i�in kullan�l�r. */
	virtual void endState() = 0;

	/* Mevcut state'te bas�lan tu�lar� kontrol eder. */
	virtual void updateKeybinds(const float& dt) = 0;

	/* Mevcut state'in durumunu g�nceller. */
	virtual void update(const float& dt) = 0;

	/* sf::Drawable s�n�f�ndan t�retilmi� s�n�flar�n
	   yazmas� gereken sanal draw fonksiyonu. */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	/* Mevcut state'e yeni varl�k eklemek i�in kullan�l�r. */
	void addEntity(Entity* entity);

	// GETTERS
	/* State'te bulunan varl�k listesini d�nd�r�r. */
	std::vector<Entity*> *getEntities();

	//void checkEntityCollisions();
protected:
	/* Mevcut state'te bulunan b�t�n varl�klar� ekrana �izer. */
	virtual void drawEntities(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	/* State'te bulunan b�t�n varl�klar� g�nceller. */
	virtual void updateEntities(const float& dt) const = 0;

	/* Mevcut state'te bulunan b�t�n varl�klar� tutar. */
	std::vector<Entity*> entities;

	/* Mevcut state'te kullan�lacak haritay� tutar. */
	Map *map;


private:
	/* Mevcut state'te kullan�lan varl�klar�n 
	   kaplamalar�n� tutar. */
	std::vector<sf::Texture> textures;
	
	/* Mevcut state bitirilmek isterse do�ru olur. */
	bool quit;

};

