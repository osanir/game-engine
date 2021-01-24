#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include "Globals.h"

// TODO: ��e aktarmada baz� sorunlar var yeniden yaz�lmas� gerekebilir.
// TODO: Konfig�rasyon dosyas�ndaki offset ve spacing 
// de�erlerine g�re i�e aktar�m yap�lmal�.

/*
*       Map objesi y�klenecek harita ile ilgili 
*   i�lemleri yapmakla y�k�ml�d�r.
*       ...
*/

/* Okunacak olan tilemap dosyas�n�n �zellikleri tutulur. */
struct TilemapData{
    std::string fileName;
    std::string mapName;
    int imageWidth;
    int imageHeight;
    int gridWidth;
    int gridHeight;
    int offsetX;
    int offsetY;
    int spaceX;
    int spaceY;
    int gridCountWidth;
    int gridCountHeight;
};
// TODO: fix a�a�� 1'den fazla numaral� tile'lar'a eri�emiyor.
class Map : public sf::Drawable{
public:
    Map();
    Map(std::string fileName);
    std::list<sf::RectangleShape*> getSolidObjets();
    void readMap();
    //void drawTile(sf::RenderWindow& window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // Getters
    sf::Vector2f getLayoutSize();

private:
    
    /* void createRandomObjects(); */
    sf::Texture tileset_texture;
    sf::Sprite* tileset_spr;
    std::vector <std::vector<int> > map_tiles;
    std::list<sf::RectangleShape*> solidObjects;
    TilemapData tilemapData;

};
