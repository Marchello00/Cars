#include <utility>

/*********************************************************************
Quinn Schwab
16/08/2010

SFML Tiled Map Loader

The zlib license has been used to make this software fully compatible
with SFML. See http://www.sfml-dev.org/license.php

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
   you must not claim that you wrote the original software.
   If you use this software in a product, an acknowledgment
   in the product documentation would be appreciated but
   is not required.

2. Altered source versions must be plainly marked as such,
   and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
   source distribution.
*********************************************************************/

#include "level.h"

#include <iostream>
#include <tinyxml2.h>

using tinyxml2::XMLDocument, tinyxml2::XMLElement;

int Object::GetPropertyInt(std::string name) {
    int i;
    i = std::stoi(properties[name].c_str());

    return i;
}

float Object::GetPropertyFloat(std::string name) {
    float f;
    f = strtod(properties[name].c_str(), NULL);

    return f;
}

std::string Object::GetPropertyString(std::string name) {
    return properties[name];
}

Level::Level() {
    //ctor
}

Level::~Level() {
    //dtor
}

void convert(unsigned &gid, bool &hFlipped, bool &vFlipped, bool &dFlipped) {
    hFlipped = bool(gid >> 31U);
    gid ^= (gid >> 31U) << 31U;
    vFlipped = bool(gid >> 30U);
    gid ^= (gid >> 30U) << 30U;
    dFlipped = bool(gid >> 29U);
    gid ^= (gid >> 29U) << 29U;
}

void flipDiagonally(sf::Image &img) {
    sf::Image cimg = img;
    for (int x = 0; x < cimg.getSize().x; ++x) {
        for (int y = 0; y < cimg.getSize().y; ++y) {
            img.setPixel(y, x, cimg.getPixel(x, y));
        }
    }
}

bool Level::LoadFromFile(std::string filename) {
    XMLDocument levelFile;

    if (levelFile.LoadFile(filename.c_str())) {
        std::cout << "Loading level \"" << filename << "\" failed." << std::endl;
        return false;
    }

    //Map element. This is the root element for the whole file.
    XMLElement *map;
    map = levelFile.FirstChildElement("map");

    //Set up misc map properties.
    width = std::stoi(map->Attribute("width"));
    height = std::stoi(map->Attribute("height"));
    tileWidth = std::stoi(map->Attribute("tilewidth"));
    tileHeight = std::stoi(map->Attribute("tileheight"));

    //Tileset stuff
    XMLElement *tilesetElement;
    tilesetElement = map->FirstChildElement("tileset");
    while (tilesetElement) {
        Tileset tileset;
        tileset.firstgid = std::stoi(tilesetElement->Attribute("firstgid"));
        auto tilesSrc = tilesetElement->Attribute("source");

        //Tileset image

        XMLDocument tilesetFile;

        if (tilesetFile.LoadFile(tilesSrc)) {
            std::cout << "Loading tileset \"" << tilesSrc << "\" failed." << std::endl;
        }

        XMLElement *tilesetElementHere;
        tilesetElementHere = tilesetFile.FirstChildElement("tileset");
        
        XMLElement *tileElement;
        tileElement = tilesetElementHere->FirstChildElement("tile");
        while (tileElement) {
            XMLElement *imgElement;
            imgElement = tileElement->FirstChildElement("image");
            Tile tile;
            tile.width = std::stoi(imgElement->Attribute("width"));
            tile.height = std::stoi(imgElement->Attribute("height"));
            std::string tileSource = imgElement->Attribute("source");
            tile.texture.loadFromFile(tileSource);
            tileset.tiles.push_back(tile);
            tileElement = tileElement->NextSiblingElement("tile");
        }
        tilesets.push_back(tileset);

        tilesetElement = tilesetElement->NextSiblingElement("tileset");
    }

    //Layers
    XMLElement *layerElement;
    layerElement = map->FirstChildElement("layer");

    while (layerElement) {
        Layer layer;
        if (layerElement->Attribute("opacity"))//check if opacity attribute exists
        {
            float opacity = strtod(layerElement->Attribute("opacity"),
                                   nullptr);//convert the (string) opacity element to float
            layer.opacity = 255 * opacity;
        } else {
            layer.opacity = 255;//if the attribute doesnt exist, default to full opacity
        }

        //Tiles
        XMLElement *layerDataElement;
        layerDataElement = layerElement->FirstChildElement("data");

        if (!layerDataElement) {
            std::cout << "Bad map. No layer information found." << std::endl;
            return false;
        }

        CSVReader csv(std::string(layerDataElement->GetText()));

        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                unsigned gid = csv.getNext();
                if (!gid) continue;
                bool fh, fv, fd;
                convert(gid, fh, fv, fd);
                int tid = tilesets.size() - 1;
                for (; tilesets[tid].firstgid > gid; --tid) {}
                Tile &tile = tilesets[tid].tileAt(gid - tilesets[tid].firstgid);
                sf::Image img = tile.texture.copyToImage();
                if (fd) flipDiagonally(img);
                if (fh) img.flipHorizontally();
                if (fv) img.flipVertically();
                sf::Sprite sprite;
                sf::Texture forsprite;
                forsprite.loadFromImage(img);
                sprite.setTexture(forsprite);
                sprite.setOrigin(0, tile.height);
                sprite.setPosition(x * tileWidth, y * tileHeight);
                layer.tiles.push_back(sprite);
            }
        }

//        XMLElement *tileElement;
//        tileElement = layerDataElement->FirstChildElement("tile");


//        if (tileElement == NULL) {
//            std::cout << "Bad map. No tile information found." << std::endl;
//            return false;
//        }
//
//        int x = 0;
//        int y = 0;
//
//        while (tileElement) {
//            int tileGID = std::stoi(tileElement->Attribute("gid"));
//            int subRectToUse = tileGID - firstTileID;//Work out the subrect ID to 'chop up' the tilesheet image.
//            if (subRectToUse >= 0)//we only need to (and only can) create a sprite/tile if there is one to display
//            {
//                sf::Sprite sprite;//sprite for the tile
//                sprite.setTexture(tilesetImage);
//                sprite.setTextureRect(subRects[subRectToUse]);
//                sprite.setPosition(x * tileWidth, y * tileHeight);
//                sprite.setColor(sf::Color(255, 255, 255, layer.opacity));//Set opacity of the tile.
//
//                //add tile to layer
//                layer.tiles.push_back(sprite);
//            }
//
//            tileElement = tileElement->NextSiblingElement("tile");
//
//            //increment x, y
//            x++;
//            if (x >= width)//if x has "hit" the end (right) of the map, reset it to the start (left)
//            {
//                x = 0;
//                y++;
//                if (y >= height) {
//                    y = 0;
//                }
//            }
//        }

        layers.push_back(layer);

        layerElement = layerElement->NextSiblingElement("layer");
    }

    //Objects
    XMLElement *objectGroupElement;
    if (map->FirstChildElement("objectgroup"))//Check that there is atleast one object layer
    {
        objectGroupElement = map->FirstChildElement("objectgroup");
        while (objectGroupElement)//loop through object layers
        {
            XMLElement *objectElement;
            objectElement = objectGroupElement->FirstChildElement("object");
            while (objectElement)//loop through objects
            {
                std::string objectType;
                if (objectElement->Attribute("type")) {
                    objectType = objectElement->Attribute("type");
                }
                std::string objectName;
                if (objectElement->Attribute("name")) {
                    objectName = objectElement->Attribute("name");
                }
                int x = (int)std::stod(objectElement->Attribute("x"));
                int y = (int)std::stod(objectElement->Attribute("y"));



                Object object;
                object.name = objectName;
                object.type = objectType;

                sf::Rect<int> objectRect;
                objectRect.top = y;
                objectRect.left = x;
                if (objectElement->Attribute("width")) {
                    int _width = (int) std::stod(objectElement->Attribute("width"));
                    objectRect.width = _width;
                }
                if (objectElement->Attribute("height")) {
                    int _height = (int)std::stod(objectElement->Attribute("height"));
                    objectRect.height = _height;
                }

                if (objectType == "solid") {
                    solidObjects.push_back(objectRect);
                }

                object.rect = objectRect;

                XMLElement *properties;
                properties = objectElement->FirstChildElement("properties");
                if (properties) {
                    XMLElement *prop;
                    prop = properties->FirstChildElement("property");
                    if (prop) {
                        while (prop) {
                            std::string propertyName = prop->Attribute("name");
                            std::string propertyValue = prop->Attribute("value");

                            object.properties[propertyName] = propertyValue;

                            prop = prop->NextSiblingElement("property");
                        }
                    }
                }

                objects.push_back(object);

                objectElement = objectElement->NextSiblingElement("object");
            }
            objectGroupElement = objectGroupElement->NextSiblingElement("objectgroup");
        }
    } else {
        std::cout << "No object layers found..." << std::endl;
    }

    return true;
}

Object Level::GetObject(const std::string& name) {
    for (auto & object : objects) {
        if (object.name == name) {
            return object;
        }
    }
}

void Level::SetDrawingBounds(sf::Rect<float> bounds) {
    drawingBounds = bounds;

    //Adjust the rect so that tiles are drawn just off screen, so you don't see them disappearing.
    drawingBounds.top -= tileHeight;
    drawingBounds.left -= tileWidth;
}

void Level::Draw(sf::RenderWindow &window) {
    for (auto & layer : layers) {
        for (auto & tile : layer.tiles) {
//            if (drawingBounds.contains(tile.getPosition().x,
//                                       tile.getPosition().y)) {
                window.draw(tile);
//            }
        }
    }
}

unsigned CSVReader::getNext() {
    while (text[ptr] == '\n' || text[ptr] == ',') ptr++;
    int len = 0;
    while (text[ptr + len] != ',') len++;
    int res = std::stoul(text.substr(ptr, len));
    ptr += len;
    return res;
}

CSVReader::CSVReader(std::string text) : text(std::move(text)) {}

Tile &Tileset::tileAt(int id) {
    return tiles[id];
}
