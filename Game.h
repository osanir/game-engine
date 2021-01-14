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
*	    Bu sýnýf oyunun temel oyun döngüsünü baþlatýr. 
*	Kullanýcý bu sýnýftan türettiði bir sýnýfýn run()
*	fonksiyonunu tetikleyerek oyunu baþlatabilir. 
*	    
*		Bu sýnýftan türetilen sýnýflarýn override ederek
*	yeniden yazmasý gereken OnStart() ve OnUpdate() fonksiyonlarý
*	içerisi kullanýcý tarafýndan düzenlenecek þekilde tasarlanmýþtýr.
*/
class Game{
public:
	// Constructor & Destructor
	Game();
	~Game();

	/* Oyuna yeni state eklemek için kullanýlýr. */
	void addState(State* state);

	/* En üst state'e yeni varlýk eklemek için kullanýlýr. */
	void addEntity(Entity* entity);

	/* Oyunu baþlatmak için kullanýlýr. */
	void run();

	// Getters //////////////////////////////////////////
	/* Çalýþan pencereyi döndürür. */
	sf::RenderWindow* getWindow();

	/* Ýmlecin mevcut pencereye göre konumu tutulur.
	   Pencerenin sol üst köþesi (0,0) kabul edilir. */
	sf::Vector2i getMousePosition();

	/* Kullanýcý tarafýndan kullanýlacak OnStart ve OnUpdate fonksiyonlarý. */
	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
private:
	/* Gerekli baþlatma iþlemleri burada yapýlýr. */
	void init();

	/* Pencere olaylarý burada kontrol edilir. */
	void processEvents();

	/* Oyun zamanýný günceller. 
	dt, iki kare arasýnda geçen zamaný ifader eder.*/
	void updateDt();

	/* Bütün state'leri günceller. */
	void update();

	/* Çizim iþlemleri burada yapýlýr.
	   Bütün state'leri ekrana çizer. */
	void render();
	

	// Initialization
	/* State'leri baþlatýr. */
	void initStates();

	/* En üst state'te varlýklarý baþlatýr. */
	void initEntities();

	
	/* Ýki kare arasýnda geçen zamaný tutar. */
	sf::Clock dtClock;
	float dt;

	/* Oyun ana penceresi */
	sf::RenderWindow window;

	/* Bütün state'ler burada tutulur. */
	std::stack<State*> states;

	/* Kullanýcý tarafýndan eklenmek istenen
	   varlýklar burada tutulur. */
	std::vector<Entity*> newEntities;
};
