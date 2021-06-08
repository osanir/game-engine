#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

Game::Game() : window(sf::VideoMode(360, 240), "SFML Game Engin"){
	this->dt = this->dtClock.restart().asSeconds();

	/* Pencere ile ilgili konfig�rasyonlar dosyadan okunur. */
	std::ifstream ifs("Config/Window.config");
	std::string title = "None";
	sf::VideoMode windowBounds(854, 480);
	unsigned frame_limit = 120;
	bool vertical_sync_enabled = false;

	if( ifs.is_open() ){
		std::getline(ifs, title);
		ifs >> windowBounds.width >> windowBounds.height;
		ifs >> frame_limit;
		ifs >> vertical_sync_enabled;
	} else{
		// std::cout << "File Error: Could not open file" << std::endl;
	}

	/* Konfig�rasyon dosyas�ndan okunan veriler global olarak tutulur. */
	globals.setWindowBounds(windowBounds);
	
	/* Pencere i�lemleri ger�ekle�tirilir. */
	this->window.setSize(sf::Vector2u(windowBounds.width, windowBounds.height));
	this->window.setTitle(title);
	this->window.setFramerateLimit(frame_limit);
	this->window.setVerticalSyncEnabled(vertical_sync_enabled);

	ifs.close();
}

Game::~Game(){
	/* Herhangi bir state kalmayana kadar stack'i 
	   bo�alt�r ve oyunu bitirir. */
	while(!this->states.empty()){
		// TODO: Burada ��k�yor.
		//delete this->states.top();
		this->states.pop();
	}
}

void Game::addState(State* state){
	this->states.push(state);
}

void Game::addEntity(Entity* entity){
	this->newEntities.push_back(entity);
}

void Game::updateDt(){
	/* Calculates the elapsed time between two sequential frames. */

	this->dt = this->dtClock.restart().asSeconds();
	
	/* �ki kare aras�nda ge�en zaman
	   This shows elapsed time between two frames */
	//std::cout << this->dt << std::endl;
	
	/* FPS Sayac�
	   This shows the count of frames per second */
	//std::cout << "FPS: " << 1.f / this->dt << std::endl;
}

void Game::run(){
	this->init();
	this->OnStart();
	while(window.isOpen()){
		this->updateDt();
		this->processEvents();
		this->OnUpdate();
		this->update();
		this->render();
	}
}

sf::RenderWindow* Game::getWindow(){
	return &this->window;
}

sf::Vector2i Game::getMousePosition(){
	return sf::Mouse::getPosition(this->window);
}

void Game::processEvents(){
	/* Pencere ile ilgili olaylar burada tan�mlan�r. */
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed){
			window.close();
		}
		if(event.type == sf::Event::Resized){
			globals.setWindowBounds(sf::VideoMode(this->window.getSize().x, this->window.getSize().y));
			//std::cout << this->window.getSize().x << " : " << this->window.getSize().y << std::endl;
		}
		if(this->states.empty()){
			window.close();
		}
	}
}

void Game::init(){
	/* Init something
	   Stateler ve eklenecek varl�klar burada setleniyor. */
	this->initStates();
	this->initEntities();

	globals.setCurrentEntities(this->states.top()->getEntities());
}

void Game::update(){
	/* Stack'te tutulan statelerin en �stteki update ediliyor. */
	if(!this->states.empty()){
		this->states.top()->update(dt);

		if(this->states.top()->getQuit()){
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
			globals.setCurrentEntities(this->states.top()->getEntities());
		}

	} 
}

void Game::render(){
	this->window.clear(sf::Color::White);
	//this->window.clear(sf::Color(128, 190, 31));
	/* Ekrana �izdirme olaylar� burada ger�ekle�iyor. */
	if(!this->states.empty()){
		/* State s�n�flar� da sf::Drawable s�n�f�ndan 
		   t�retildi�i i�in bu �ekilde bir kullan�m yapabiliyoruz. */
		this->window.draw(*this->states.top());
	}
	
	this->window.display();
}

void Game::initStates(){
	/* Oyun ba�lat�ld���nda herhangi bir state belirtilmemi�se
	   GameState t�r�nde bir state ile oyun ba�lat�l�yor. */
	if(this->states.empty()){
		this->states.push(new GameState());
	}
}

void Game::initEntities(){
	/* Kullan�c� taraf�ndan eklenecek entityler, 
	   state listesinin en �st�ne ekleniyor. */
	if(!this->states.empty()){
		for(auto* newEntity : this->newEntities){
			this->states.top()->addEntity(newEntity);
		}
	}
}

