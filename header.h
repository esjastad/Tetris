#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <sstream>
#include <time.h>
#include <cctype>
#include <cstring>

class background
{
public:
    background();
    sf::Sprite border;
private:
    sf::Texture borderTexture;

};

class shape : public sf::Transformable
{
public:
    sf::Sprite block[4];
    shape();
    bool movement(sf::Vector2f destination, char temp);
    void rotater();
    int gen;
    sf::Transform former;
private:
    sf::Texture blockTexture;
    sf::Vector2f position;
    int flag;
    int color;
    sf::Vector2f currentposition;
};

struct node
{
    shape data;
    node * next;
};

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    bool reset= false;
    bool isempty(sf::Vector2u tileSize, int* tiles, unsigned int width, unsigned int height, node * current, char direction);
    void stamp(node * current, int tiles[], sf::Vector2u tileSize, unsigned int width, unsigned int height, sf::Clock clock, sf::Time elapsed1, sf::RenderWindow & window, node * temp, TileMap gameboard, background game, sf::Sound sound, sf::SoundBuffer soundstamp);
    void tetris(int tiles[], unsigned int width, unsigned int height, sf::Clock clock, sf::Time elapsed1, sf::RenderWindow & window, node * temp, TileMap gameboard, background game, sf::Sound sound, sf::SoundBuffer soundtetris);
    bool load(const std::string& tileset, sf::Vector2u tileSize, int* tiles, unsigned int width, unsigned int height)
    {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // get the current tile number
                int tileNumber = tiles[i + j * width];

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

};

