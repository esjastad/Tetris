#include "header.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 900), "Tilemap");
    load game;


    // define the level with an array of tile indices


    // create the tilemap from the level definition

    node * head = new node;
    node * current = head;
    node * temp = NULL;
    int counter = 1;

    sf::Clock clock;
    sf::Time elapsed1 = clock.getElapsedTime();

    // run the main loop
    while (window.isOpen())
    {
        elapsed1 = clock.getElapsedTime();
        if (elapsed1.asSeconds() > 1)
        {
            if (current->shape.grid.getPosition().y < 800)
                current->shape.grid.move(0,40);
            if (current->shape.grid.getPosition().y == 800)
            {
                temp = new node;
                temp->next = NULL;
                current->next = temp;
                current = current->next;
                ++counter;
            }


            clock.restart();
        }

        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                /*if (head->next)
                {
                    while (head->next)
                    {
                        current = head->next;
                        delete head;
                        head = current;
                    }
                //    delete head;
                //    head = NULL;
                }
                else
                    delete head;
                head = NULL;*/
                window.close();
            }


            if(event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && current->shape.grid.getPosition().x > current->shape.L)
                    current->shape.grid.move(-40, 0);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && current->shape.grid.getPosition().x < current->shape.R)
                    current->shape.grid.move(40, 0);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && current->shape.grid.getPosition().y < current->shape.B)
                    current->shape.grid.move(0, 40);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    current->shape.rotater();

            }
        }

        // draw the map
        window.clear();
        temp = head;
        if (temp->next)
        {
            for(int i = 0; i < counter; ++i)
            {
                window.draw(temp->shape.grid);
                temp = temp->next;
            }
        }

        window.draw(current->shape.grid);
        window.draw(game.borders);
        window.display();
    }

    for (int i = 0; i < counter; ++i)
    {
        if (head)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    return 0;
}
