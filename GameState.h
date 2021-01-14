#pragma once
#include "State.h"
#include "Globals.h"

/*
*		GameState, State sýnýfýndan türetilmiþ bir sýnýftýr.
*	Ana oyun sahnesi bu state ile oluþturulur. 
*		
*		
*/

class GameState : public State{
public:
	/* Bir oyun sahnesi oluþturulduðunda varsayýlan
	   konfigürasyon dosyasý içe aktarýlýr. */
	GameState();

	/* Parametre olarak gelen konfigürasyon dosyasýný
	   okuyarak haritayý yükler. */
	GameState(std::string configFileName);
	virtual ~GameState();

	// Functions
	/* Sahneyi sonlandýrýr. */
	void endState();

	/* Mevcut state'te basýlan tuþlarý kontrol eder. */
	void updateKeybinds(const float& dt);
	
	/* Mevcut state'in durumunu günceller. */
	void update(const float& dt);

	/* sf::Drawable sýnýfýndan türetilmiþ sýnýflarýn
	   yazmasý gereken sanal draw fonksiyonu. */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	/* Mevcut state'te bulunan bütün varlýklarý ekrana çizer. */
	void drawEntities(sf::RenderTarget& target, sf::RenderStates states) const;
	
	/* State'te bulunan bütün varlýklarý günceller. */
	void updateEntities(const float&dt) const ;
private:

};

