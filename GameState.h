#pragma once
#include "State.h"
#include "Globals.h"

/*
*		GameState, State s�n�f�ndan t�retilmi� bir s�n�ft�r.
*	Ana oyun sahnesi bu state ile olu�turulur. 
*		
*		
*/

class GameState : public State{
public:
	/* Bir oyun sahnesi olu�turuldu�unda varsay�lan
	   konfig�rasyon dosyas� i�e aktar�l�r. */
	GameState();

	/* Parametre olarak gelen konfig�rasyon dosyas�n�
	   okuyarak haritay� y�kler. */
	GameState(std::string configFileName);
	virtual ~GameState();

	// Functions
	/* Sahneyi sonland�r�r. */
	void endState();

	/* Mevcut state'te bas�lan tu�lar� kontrol eder. */
	void updateKeybinds(const float& dt);
	
	/* Mevcut state'in durumunu g�nceller. */
	void update(const float& dt);

	/* sf::Drawable s�n�f�ndan t�retilmi� s�n�flar�n
	   yazmas� gereken sanal draw fonksiyonu. */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	/* Mevcut state'te bulunan b�t�n varl�klar� ekrana �izer. */
	void drawEntities(sf::RenderTarget& target, sf::RenderStates states) const;
	
	/* State'te bulunan b�t�n varl�klar� g�nceller. */
	void updateEntities(const float&dt) const ;
private:

};

