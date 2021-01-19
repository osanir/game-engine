#include "Map.h"
Map::Map(){
    /* createRandomObjects(); */
    tileset_spr = new sf::Sprite();
    tileset_spr->setTexture(tileset_texture);
    readMap();
    initMap();
}

Map::Map(std::string configFileName){

    std::ifstream ifs("Config/" + configFileName);

    if(ifs.is_open()){
        std::getline(ifs, tilemapData.fileName);
        std::getline(ifs, tilemapData.mapName);
        ifs >> tilemapData.imageWidth >> tilemapData.imageHeight;
        ifs >> tilemapData.gridWidth >> tilemapData.gridHeight;
        ifs >> tilemapData.offsetX >> tilemapData.offsetY;
        ifs >> tilemapData.spaceX>> tilemapData.spaceY;
    } else{
        // std::cout << "File Error: Could not open file" << std::endl;
    }

    ifs.close();

    tileset_texture.loadFromFile("Resources/Textures/" + tilemapData.fileName);
    tileset_spr = new sf::Sprite();
    tileset_spr->setTexture(tileset_texture);
    readMap();
    initMap();
}

/* void Map::createRandomObjects(){
    for(int i=0; i<10; i++){
        RectangleShape* shape = new RectangleShape({20,20});
        shape->setFillColor(Color::Black);
        shape->setPosition({float(rand()%1024), float(rand()%768)});
        solidObjects.push_back(shape);
    }
} */

void Map::readMap(){
    std::vector<int> tempMap;
    tempMap.clear();
    map_tiles.clear();

    std::ifstream openFile("Resources/Maps/" + tilemapData.mapName);

    if(openFile.is_open()){

        int str;
        while(openFile >> str){
            if(str != -2){
                tempMap.push_back(str);
                //std::cout << str;
            } else{
                map_tiles.push_back(tempMap);
                tempMap.clear();
                //std::cout << std::endl;
            }

        }
    }


    globals.setLayoutSize(this->getLayoutSize());
}

//void Map::drawTile(sf::RenderWindow& window){
//
//    for(int y = 0; y < map_tiles.size(); y++){
//        for(int x = 0; x < map_tiles[1].size(); x++){
//            //tek bir sprite ýn boyutu kadar yer ayýr
//            tileset_spr.setPosition(x * 42.f, y * 42.f);
//            //resimden parça parça seç
//            tileset_spr.setTextureRect(sf::IntRect(map_tiles[y][x] * 42, 0, 42, 42));
//            window.draw(tileset_spr);
//        }
//    }
//}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int y = 0; y < map_tiles.size(); y++){
        for(int x = 0; x < map_tiles[0].size(); x++){
            //tek bir sprite ýn boyutu kadar yer ayýr
            tileset_spr->setPosition(x * tilemapData.gridWidth, y * tilemapData.gridHeight);
            //resimden parça parça seç
            tileset_spr->setTextureRect(sf::IntRect(map_tiles[y][x] / map_tiles[0].size() * tilemapData.gridWidth , map_tiles[y][x] / map_tiles.size() * tilemapData.gridHeight, tilemapData.gridWidth, tilemapData.gridHeight));
            target.draw(*tileset_spr);
        }
    }
}

sf::Vector2f Map::getLayoutSize(){
    return sf::Vector2f(map_tiles[0].size() * tilemapData.gridWidth, map_tiles.size() * tilemapData.gridHeight);
}

void Map::initMap(){

    for(int y = 0; y < map_tiles.size(); y++){
        for(int x = 0; x < map_tiles[1].size(); x++){
            //tek bir sprite ýn boyutu kadar yer ayýr
            tileset_spr->setPosition(x * tilemapData.gridWidth, y * tilemapData.gridHeight);
            //resimden parça parça seç
            tileset_spr->setTextureRect(sf::IntRect(map_tiles[y][x] * tilemapData.gridWidth, 0, tilemapData.gridWidth, tilemapData.gridHeight));
            if(map_tiles[y][x] == 0){

                sf::RectangleShape* shape = new sf::RectangleShape({(float)tilemapData.gridWidth, (float)tilemapData.gridHeight});
                shape->setFillColor(sf::Color::Black);
                shape->setPosition({(float)x * tilemapData.gridWidth  , (float)y * tilemapData.gridHeight});
                solidObjects.push_back(shape);

            }
        }
    }


}
std::list<sf::RectangleShape*> Map::getSolidObjets(){
    return solidObjects;
}