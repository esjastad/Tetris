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

class shape
{
public:
    sf::Sprite block[4];
    shape();
    bool movement(sf::Vector2f destination, char temp);
    void rotater();

private:
    sf::Texture blockTexture;
    int gen;
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

