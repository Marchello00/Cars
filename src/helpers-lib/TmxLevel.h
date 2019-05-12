#ifndef CARS_TMXLEVEL_H
#define CARS_TMXLEVEL_H

#pragma once

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>

// В картах TMX объект - это область на карте, имеющая имя, тип,
//  границы, набор пользовательских свойств (в формате ключ-значение)
//  и текстурные координаты.
// Текстурные координаты позволяют связать с объектом спрайт,
//  использующий основную текстуру карты как источник данных.
struct TmxObject {
    int getPropertyInt(const std::string &propertyName);

    float getPropertyFloat(const std::string &propertyName);

    std::string getPropertyString(const std::string &propertyName);

    void moveBy(const sf::Vector2f &movement);

    void moveTo(const sf::Vector2f &position);

    std::string name;
    std::string type;
    sf::FloatRect rect;
    std::map<std::string, std::string> properties;

    sf::Sprite sprite;
};

// В картах TMX слой - это набор тайлов (спрайтов),
//  из которых складывается ландшафт карты.
// Слоёв может быть несколько, что позволяет нарисовать,
//  например, слой травы поверх слоя земли.
struct TmxLayer {
    sf::Uint8 opacity = 0;
    std::vector<sf::Sprite> tiles;
};

class TmxLevel {
public:
    // Загружает данные из TMX в память объекта.
    bool loadFromFile(const std::string &filepath);

    TmxObject getFirstObject(const std::string &name) const;

    std::vector<TmxObject> getAllObjects(const std::string &name) const;

    sf::Vector2i getTileSize() const;

    float getTilemapWidth() const;

    float getTilemapHeight() const;

    sf::Vector2f getTilemapSize() const;

    // Рисует все слои тайлов один за другим,
    //  но не рисует объекты (рисованием которых должна заниматься игра).
    // Принимает любую цель для рисования, например, sf::RenderWindow.
    void render(sf::RenderTarget &target) const;

protected:
    int m_width = 0;
    int m_height = 0;
    int m_tileWidth = 0;
    int m_tileHeight = 0;
    int m_firstTileID = 0;
    int m_spacing = 0;
    sf::Texture m_tilesetImage;
    std::vector<TmxObject> m_objects;
    std::vector<TmxLayer> m_layers;
};

class CSVReader {
public:
    CSVReader(std::string text);

    unsigned getNext();

private:
    std::string text;

    int ptr = 0;
};

class RotatorAdapter {
public:
    void flipVertically();

    void flipHorizontally();

    void flipDiagonally();

    float getAngle();

private:
    void mult(int [2][2]);

    int matrix[2][2] = {{1, 0},
                        {0, 1}};

    int diagonal[2][2] = {{0, 1},
                          {1, 0}};

    int vertical[2][2] = {{-1, 0},
                          {0, 1}};

    int horizontal[2][2] = {{1, 0},
                            {0, -1}};
};

#endif // CARS_TMXLEVEL_H