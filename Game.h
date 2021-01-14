#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>

#include "Globals.h"
#include "Entity.h"
#include "GameState.h"
#include "Camera.h"
#include "TopDown.h"
#include "ScrollTo.h"

/*
*	    Bu s�n�f oyunun temel oyun d�ng�s�n� ba�lat�r. 
*	Kullan�c� bu s�n�ftan t�retti�i bir s�n�f�n run()
*	fonksiyonunu tetikleyerek oyunu ba�latabilir. 
*	    
*		Bu s�n�ftan t�retilen s�n�flar�n override ederek
*	yeniden yazmas� gereken OnStart() ve OnUpdate() fonksiyonlar�
*	i�erisi kullan�c� taraf�ndan d�zenlenecek �ekilde tasarlanm��t�r.
*/
class Game{
public:
	// Constructor & Destructor
	Game();
	~Game();

	/* Oyuna yeni state eklemek i�in kullan�l�r. */
	void addState(State* state);

	/* En �st state'e yeni varl�k eklemek i�in kullan�l�r. */
	void addEntity(Entity* entity);

	/* Oyunu ba�latmak i�in kullan�l�r. */
	void run();

	// Getters //////////////////////////////////////////
	/* �al��an pencereyi d�nd�r�r. */
	sf::RenderWindow* getWindow();

	/* �mlecin mevcut pencereye g�re konumu tutulur.
	   Pencerenin sol �st k��esi (0,0) kabul edilir. */
	sf::Vector2i getMousePosition();

	/* Kullan�c� taraf�ndan kullan�lacak OnStart ve OnUpdate fonksiyonlar�. */
	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
private:
	/* Gerekli ba�latma i�lemleri burada yap�l�r. */
	void init();

	/* Pencere olaylar� burada kontrol edilir. */
	void processEvents();

	/* Oyun zaman�n� g�nceller. 
	dt, iki kare aras�nda ge�en zaman� ifader eder.*/
	void updateDt();

	/* B�t�n state'leri g�nceller. */
	void update();

	/* �izim i�lemleri burada yap�l�r.
	   B�t�n state'leri ekrana �izer. */
	void render();
	

	// Initialization
	/* State'leri ba�lat�r. */
	void initStates();

	/* En �st state'te varl�klar� ba�lat�r. */
	void initEntities();

	
	/* �ki kare aras�nda ge�en zaman� tutar. */
	sf::Clock dtClock;
	float dt;

	/* Oyun ana penceresi */
	sf::RenderWindow window;

	/* B�t�n state'ler burada tutulur. */
	std::stack<State*> states;

	/* Kullan�c� taraf�ndan eklenmek istenen
	   varl�klar burada tutulur. */
	std::vector<Entity*> newEntities;
};
