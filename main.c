#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <sstream>

int main ()
{
    sf::Window window(sf::VideoMode(1000, 800), "Tetris");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }






    return 0;
}
