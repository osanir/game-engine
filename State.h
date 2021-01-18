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
*		State sýnýfý, oyunda yeni bir sahne oluþturmak
*	istendiði zaman üretilecek sýnýflar için bir Base 
*	sýnýftýr. 
*		Her oyun sahnesi içerisinde varlýklarý, kaplamalarý
*	ve haritayý tutmakla yükümlüdür. 
*		sf::Drawable sýnýfýndan türetilmiþtir ve haritayý
*	ve varlýklarý bu fonksiyonda ekrana çizer.
*/

class State : public sf::Drawable{
public:
	State();
	virtual ~State();

	/* Mevcut state'i bitirmek isteyip istemediðini sorar. */
	const bool& getQuit() const;

	/* Mevcut state'i bitirmek için gerekli tuþlara basýlýp
	   basýlmadýðýný kontrol eder. */
	virtual void checkForQuit();

	/* Mevcut state'i sonlandýrmak için kullanýlýr. */
	virtual void endState() = 0;

	/* Mevcut state'te basýlan tuþlarý kontrol eder. */
	virtual void updateKeybinds(const float& dt) = 0;

	/* Mevcut state'in durumunu günceller. */
	virtual void update(const float& dt) = 0;

	/* sf::Drawable sýnýfýndan türetilmiþ sýnýflarýn
	   yazmasý gereken sanal draw fonksiyonu. */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	/* Mevcut state'e yeni varlýk eklemek için kullanýlýr. */
	void addEntity(Entity* entity);

	// GETTERS
	/* State'te bulunan varlýk listesini döndürür. */
	std::vector<Entity*> *getEntities();

	//void checkEntityCollisions();
protected:
	/* Mevcut state'te bulunan bütün varlýklarý ekrana çizer. */
	virtual void drawEntities(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	/* State'te bulunan bütün varlýklarý günceller. */
	virtual void updateEntities(const float& dt) const = 0;

	/* Mevcut state'te bulunan bütün varlýklarý tutar. */
	std::vector<Entity*> entities;

	/* Mevcut state'te kullanýlacak haritayý tutar. */
	Map *map;


private:
	/* Mevcut state'te kullanýlan varlýklarýn 
	   kaplamalarýný tutar. */
	std::vector<sf::Texture> textures;
	
	/* Mevcut state bitirilmek isterse doðru olur. */
	bool quit;

};

