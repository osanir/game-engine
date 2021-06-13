#include "Map.h"
Map::Map(){
    /* createRandomObjects(); */
    tileset_spr = new sf::Sprite();
    tileset_spr->setTexture(tileset_texture);
    readMap();
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
    tilemapData.gridCountWidth = this->tileset_texture.getSize().x / tilemapData.gridWidth;
    tilemapData.gridCountHeight = this->tileset_texture.getSize().y / tilemapData.gridHeight;
    readMap();
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

void Map::createSolidObjects(){
    std::string fileName = "Resources/Maps/";
    fileName += "platformFrog_Solid.txt";
    // TODO: Config dosyasýna objeler için eklenecek dosya adýný kullanarak içe aktar.
    std::ifstream file(fileName);
    int objectCount = 0;
    if(!file.is_open()){
        // Print error
        return;
    }
    file >> objectCount;
    for(int i = 0; i < objectCount; i++){
        Solid* solid = new Solid("solid.png");
        int x, y, w, h;
        file >> x >> y >> w >> h;
        solid->setOrigin(sf::Vector2f(0, 0));
        solid->setPosition(sf::Vector2f(x, y));
        solid->setSize(sf::Vector2f(w, h));
        this->solidObjects.push_back(solid);
    }
    std::vector<Entity*> *currentEntities = globals.getCurrentEntities();
    for(auto entity : this->solidObjects){
        currentEntities->push_back(entity);
    }
    globals.setCurrentEntities(currentEntities);
    file.close();
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
            if(map_tiles[y][x] == 0) continue;
            //tek bir sprite ýn boyutu kadar yer ayýr
            tileset_spr->setPosition(x * tilemapData.gridWidth, y * tilemapData.gridHeight);
            //resimden parça parça seç
            // map_tile[y][x] * gridWidth
            int left, top;
            left = ((map_tiles[y][x] - 1) % tilemapData.gridCountWidth ) * tilemapData.gridWidth;
            top  = ((map_tiles[y][x] - 1) / tilemapData.gridCountWidth) * tilemapData.gridHeight;
            tileset_spr->setTextureRect(sf::IntRect(left, top, tilemapData.gridWidth, tilemapData.gridHeight));
            target.draw(*tileset_spr);
        }
    }
}

sf::Vector2f Map::getLayoutSize(){
    return sf::Vector2f(map_tiles[0].size() * tilemapData.gridWidth, map_tiles.size() * tilemapData.gridHeight);
}

std::vector<Solid*> Map::getSolidObjets(){
    return solidObjects;
}