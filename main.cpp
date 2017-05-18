#include "header.h"

int main()
{
    int gamemap[] =
    {
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
    };

    TileMap gameboard;
    if (!gameboard.load("mainmap.png", sf::Vector2u(40, 40), gamemap, 10, 20))
        return -1;
    gameboard.setPosition(300,40);

    sf::RenderWindow window(sf::VideoMode(1000, 900), "Tilemap");
    background game;
    node * head = new node;
    node * current = head;
    current->next = new node;
    node * temp = current->next;

    if (temp->data.gen == 2)
    {
        temp->data.movement(sf::Vector2f(350,160),'s');
    }
    else if (temp->data.gen == 1)
    {
        temp->data.former.scale(0.8f,0.8f);
        temp->data.former.translate(235,60);
        temp->data.movement(sf::Vector2f(350,190),'s');
    }
    else
        temp->data.movement(sf::Vector2f(350,190),'s');


    sf::SoundBuffer soundtetris;
    soundtetris.loadFromFile("tetris.wav");

    sf::SoundBuffer soundstamp;
    soundstamp.loadFromFile("stamp.wav");

    sf::Sound sound;


    sf::Music music;
    music.setVolume(20);
    music.openFromFile("music.ogg");
    music.play();

    sf::Clock clock;
    sf::Time elapsed1 = clock.getElapsedTime();
    sf::Clock song;
    sf::Time elapsed2 = song.getElapsedTime();
    bool next = false;





    while (window.isOpen())
    {
        elapsed2 = song.getElapsedTime();
        elapsed1 = clock.getElapsedTime();
        if (elapsed2.asSeconds() > 84)
        {
            song.restart();
            music.play();
        }
        if (elapsed1.asSeconds() > 0.5)
        {
            next = gameboard.isempty(sf::Vector2u(40,40), gamemap, 10, 20,current,'s');

            if (next)
            {
                gameboard.stamp(current, gamemap, sf::Vector2u(40,40), 10, 20, clock, elapsed1, window, temp, gameboard, game, sound, soundstamp);
                sound.setBuffer(soundstamp);
                sound.play();

                gameboard.tetris(gamemap, 10, 20, clock, elapsed1, window, temp, gameboard, game, sound, soundtetris);



                if (gameboard.load("mainmap.png", sf::Vector2u(40, 40), gamemap, 10, 20))
                    std::cout << "\n";

                current = current->next;
                if (current->data.gen == 2)
                {
                    current->data.movement(sf::Vector2f(-350,-160),'s');
                }
                else
                    current->data.movement(sf::Vector2f(-350,-190),'s');

                delete head;
                head = current;
                current->next = new node;
                temp = current->next;

                if (temp->data.gen == 2)
                {
                    temp->data.movement(sf::Vector2f(350,160),'s');
                }
                else if (temp->data.gen == 1)
                {
                    temp->data.former.scale(0.8f,0.8f);
                    temp->data.former.translate(235,60);
                    temp->data.movement(sf::Vector2f(350,190),'s');
                }
                else
                    temp->data.movement(sf::Vector2f(350,190),'s');

            }
            else
            {
                current->data.movement(sf::Vector2f(0,40),'s');
            }
            clock.restart();

            //std::cout << "\n\n" << current->data.block[0].getPosition().x << "\t" << current->data.block[0].getPosition().y;
        }

        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    next = gameboard.isempty(sf::Vector2u(40,40), gamemap, 10, 20,current,'s');
                    if(!next)
                        current->data.movement(sf::Vector2f(0,40),'s');
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    next = gameboard.isempty(sf::Vector2u(40,40), gamemap, 10, 20,current,'a');
                    if(!next)
                        current->data.movement(sf::Vector2f(-40,0),'a');
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    next = gameboard.isempty(sf::Vector2u(40,40), gamemap, 10, 20,current,'d');
                    if(!next)
                        current->data.movement(sf::Vector2f(40,0),'d');
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    current->data.rotater();
                }

            }

        }


        window.clear();
        window.draw(gameboard);
        for(int i=0;i<4;++i)
        {
            window.draw(current->data.block[i]);
            window.draw(temp->data.block[i],temp->data.former);
        }
        window.draw(game.border);
        window.display();
    }


    return 0;
}
