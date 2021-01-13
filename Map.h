#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <list>
#include <fstream>
#include <vector>

struct TilemapData{
    std::string fileName;
    int imageWidth;
    int imageHeight;
    int gridWidth;
    int gridHeight;
    int offsetX;
    int offsetY;
    int spaceX;
    int spaceY;
};

class Map : public sf::Drawable{
public:
    Map();
    Map(std::string fileName);
    void initMap();
    std::list<sf::RectangleShape*> getSolidObjets();
    void readMap();
    //void drawTile(sf::RenderWindow& window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    
    /* void createRandomObjects(); */
    sf::Texture tileset_texture;
    sf::Sprite* tileset_spr;
    std::vector <std::vector<int> > map_tiles;
    std::list<sf::RectangleShape*> solidObjects;

};
