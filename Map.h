#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include "Globals.h"

// TODO: Ýçe aktarmada bazý sorunlar var yeniden yazýlmasý gerekebilir.
// TODO: Konfigürasyon dosyasýndaki offset ve spacing 
// deðerlerine göre içe aktarým yapýlmalý.

/*
*       Map objesi yüklenecek harita ile ilgili 
*   iþlemleri yapmakla yükümlüdür.
*       ...
*/

/* Okunacak olan tilemap dosyasýnýn özellikleri tutulur. */
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
// TODO: fix aþaðý 1'den fazla numaralý tile'lar'a eriþemiyor.
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
