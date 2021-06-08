#include "Game.h"
#include "Logger.h"

class Player : public Entity{
public:
	Player(std::string fileName)
		:Entity(fileName)
		,topDown(this)
		//, platform(this)
		, scrollTo(this){
		setPosition(sf::Vector2f(300, 100));
		setMovementSpeed(500);
	}

	void update(float dt){
		topDown.update(dt);
		//platform.update(dt);
		scrollTo.update(dt);
	}
	TopDown topDown;
	//Platform platform;
	ScrollTo scrollTo;

};

class Wall : public Entity{
public:
	Wall(std::string fileName)
		:Entity(fileName){
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
		dol(this){
		bullet.setSpeed(1000);
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
	Missile		missile;
	Mouse		mouse;
	Wall		wall1, wall2, wall3, wall4, wall5, wall6, wall7, wall8, wall9, wall10, wall11, wall12, wall13;
	//std::vector<Wall*> myWalls;

	MyGame() : Game(),
		state("Map3.config"),
		player("blue.png"),
		missile("bullet.png"),
		wall1("box.png"),
		wall2("box.png"),
		wall3("box.png"),
		wall4("box.png"),
		wall5("box.png"),
		wall6("box.png"),
		wall7("box.png"),
		wall8("box.png"),
		wall9("box.png"),
		wall10("box.png"),
		wall11("box.png"),
		wall12("box.png"),
		wall13("box.png"){
		//myWalls.resize(40);
		//for(int i = 0; i < 40; i++){
		//	Wall* wall = new Wall("box.png");
		//	wall->setPosition(sf::Vector2f(i * 70, 640));
		//	myWalls.push_back(wall);
		//}

		wall1.setPosition(sf::Vector2f(1 * 70, 640));
		wall2.setPosition(sf::Vector2f(2 * 70, 640));
		wall3.setPosition(sf::Vector2f(3 * 70, 640));
		wall4.setPosition(sf::Vector2f(4 * 70, 640));
		wall5.setPosition(sf::Vector2f(5 * 70, 640));
		wall6.setPosition(sf::Vector2f(6 * 70, 640));
		wall7.setPosition(sf::Vector2f(7 * 70, 640));
		wall8.setPosition(sf::Vector2f(8 * 70, 640));
		wall9.setPosition(sf::Vector2f(9 * 70, 640));
		wall10.setPosition(sf::Vector2f(10 * 70, 640));
		wall11.setPosition(sf::Vector2f(11 * 70, 640));
		wall12.setPosition(sf::Vector2f(12 * 70, 640));
		wall13.setPosition(sf::Vector2f(13 * 70, 640));

		addState(&state);

		addEntity(&wall1);
		addEntity(&wall2);
		addEntity(&wall3);
		addEntity(&wall4);
		addEntity(&wall5);
		addEntity(&wall6);
		addEntity(&wall7);
		addEntity(&wall8);
		addEntity(&wall9);
		addEntity(&wall10);
		addEntity(&wall11);
		addEntity(&wall12);
		addEntity(&wall13);
		addEntity(&player);
		addEntity(&missile);
	}

	void OnStart(){
		//for(int i = 0; i < 40; i++){
		//	addEntity(myWalls[i]);
		//}

		player.scrollTo.setWindow(this->getWindow());
	}

	void OnUpdate(){

	}
};

int main(){
	MyGame game;
	game.run();
	return 0;
}