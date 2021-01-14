#pragma once
#include "Behavior.h"
#include "Camera.h"

/*	
*		ScrollTo sýnýfý Behavior sýnýfýndan türetilmiþtir.
*	Bir davranýþtýr.
*		Eklendiði varlýðýn	her daim ekran ortasýnda 
*	görünmesini saðlar.
*		Ýçerisinde bulunan Entity* entity deðiþkeni ile,
*	etki ettiði sýnýfa eriþebilir. Entity sýnýfýnda, ScrollTo
*	sýnýfý friend sýnýf olarak tanýmlandýðý için, pozisyon
*	gibi deðiþkenlere eriþerek varlýðýn pozisyonununa baðlý 
*	olarak kamera pozisyonunu güncellemekle yükümlüdür.
*/

class ScrollTo : public Behavior{
public:
	ScrollTo(Entity* entity);

	/* Kameranýn güncel pozisyonunu günceller ve 
	   pencereye ilgili kameranýn görüþünü aktarýr. */
	void update(float dt);

	/* Etki edeceði karakterin bulunduðu pencerenin
	   referansýný günceller. */
	void setWindow(sf::RenderWindow* window);
private:
	/* Kameranýn etki ettiði pencereyi tutar. */
	sf::RenderWindow* window;

	/* Hareket ettirilecek kamera tanýmlanýr. */
	Camera camera;
};

