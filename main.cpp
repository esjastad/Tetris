#include "header.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(1000, 900), "Tilemap");
    background game;
    node * head = new node;
    node * current = head;
    current->next = new node;
    node * temp = current->next;

    temp->data.movement(sf::Vector2f(350,190),'s');





    sf::Clock clock;
    sf::Time elapsed1 = clock.getElapsedTime();
    bool next = false;





    while (window.isOpen())
    {

        elapsed1 = clock.getElapsedTime();
        if (elapsed1.asSeconds() > 1)
        {
            next = current->data.movement(sf::Vector2f(0,40),'s');
            if (next)
            {
                current = current->next;

                current->data.movement(sf::Vector2f(-350,-190),'s');

                delete head;
                head = current;
                current->next = new node;
                temp = current->next;


                temp->data.movement(sf::Vector2f(350,190),'s');
            }
            clock.restart();

            std::cout << "\n\n" << current->data.block[0].getPosition().x;
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
                    current->data.movement(sf::Vector2f(0,40),'s');
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    current->data.movement(sf::Vector2f(-40,0),'a');
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    current->data.movement(sf::Vector2f(40,0),'d');
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    current->data.rotater();
                }

            }

        }


        window.clear();

        for(int i=0;i<4;++i)
        {
            window.draw(current->data.block[i]);
            window.draw(temp->data.block[i]);
        }
        window.draw(game.border);
        window.display();
    }


    return 0;
}
