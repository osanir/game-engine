#include "Game.h"

class Player : public Entity{
public:
	Player(std::string fileName)
		:Entity(fileName)
		,topDown(this)
		,scrollTo(this)
	{
		setMovementSpeed(500);
	}

	void update(float dt){
		topDown.update(dt);
		scrollTo.update(dt);
	}
	TopDown topDown;
	ScrollTo scrollTo;

};

class Wall : public Entity{
public:
	Wall(std::string fileName)
		:Entity(fileName)
	{
		setPosition({300,300});
		isSolid = true;
	}
	void update(float dt){
	}
};

class Missile : public Entity{
public:
	Missile(std::string fileName)
		:Entity(fileName),
		bullet(this),
		dol(this)
	{
	}

	void update(float dt){
		bullet.update(dt);
		dol.update(dt);
	}
	Bullet bullet;
	DestroyOutsideLayout dol;
};

class MyGame : public Game{
public:
	GameState	state;
	Player		player;
	Wall		wall;
	Missile		missile;
	Mouse		mouse;

	MyGame(): Game(),
		state("Map2.config"),
		player("player.png"),
		wall("wall.png"),
		missile("bullet.png")
	{
		player.scrollTo.setWindow(this->getWindow());

		addState(&state);
		addEntity(&player);
		addEntity(&wall);
		addEntity(&missile);
	}
	
	void OnStart(){

	}

	void OnUpdate(){
		if(player.onCollision(wall)){
			//wall.destroy();
			std::cout << "Çarpýþtý" << std::endl;
		}

		if(mouse.onButtonClicked("left")){
			player.spawnAnotherObject(new Missile("bullet.png"));
		}

		if(missile.onCollision(wall)){
			missile.destroy();
		}
		std::cout << "Total: " << globals.getCurrentEntities()->size() << std::endl;

		player.setRotationTowardPosition(this->getMousePosition());
	}
};

int main(){
	MyGame game;
	game.run();
	return 0;
}