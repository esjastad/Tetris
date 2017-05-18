#include "header.h"

background::background()
{
    borderTexture.loadFromFile("borders.png");
    borderTexture.setSmooth(true);
    border.setTexture(borderTexture);
}

shape::shape()
{
    flag = 0;
    blockTexture.loadFromFile("block.png");
    blockTexture.setSmooth(true);
    color = rand()%4+1;
    sf::Color temporary;
    if (color == 1)
        temporary = sf::Color::Blue;
    if (color == 2)
        temporary = sf::Color::Green;
    if (color == 3)
        temporary = sf::Color::Yellow;
    if (color == 4)
        temporary = sf::Color::Red;

    for(int i=0;i<4;++i)
    {
        block[i].setTexture(blockTexture);
        block[i].setColor(temporary);
    }

    position = sf::Vector2f(420,0);
    srand(time(NULL));
    gen = 1; //rand()%7+1;

    if (gen==1) //stick
    {
            block[0].setPosition(sf::Vector2f(position.x,position.y-80));
            block[1].setPosition(sf::Vector2f(position.x,position.y-120));
            block[2].setPosition(sf::Vector2f(position.x,position.y-40));
            block[3].setPosition(sf::Vector2f(position.x,position.y));
    }

    if (gen==2)
    {
            block[0].setPosition(position);
            block[1].setPosition(sf::Vector2f(position.x,position.y-40));
            block[2].setPosition(sf::Vector2f(position.x+40,position.y-40));
            block[3].setPosition(sf::Vector2f(position.x+40,position.y));
    }

    if (gen==3)
    {
            block[0].setPosition(sf::Vector2f(position.x,position.y-40));
            block[1].setPosition(sf::Vector2f(position.x,position.y));
            block[2].setPosition(sf::Vector2f(position.x,position.y-80));
            block[3].setPosition(sf::Vector2f(position.x+40,position.y-40));
    }

    if (gen==4)
    {
            block[0].setPosition(sf::Vector2f(position.x,position.y-40));
            block[1].setPosition(sf::Vector2f(position.x,position.y-80));
            block[2].setPosition(sf::Vector2f(position.x,position.y));
            block[3].setPosition(sf::Vector2f(position.x+40,position.y));
    }

    if(gen==5)
    {
            block[0].setPosition(sf::Vector2f(position.x+40,position.y-40));
            block[1].setPosition(sf::Vector2f(position.x+40,position.y-80));
            block[2].setPosition(sf::Vector2f(position.x+40,position.y));
            block[3].setPosition(sf::Vector2f(position.x,position.y));
    }
    if(gen==6)
    {
            block[0].setPosition(sf::Vector2f(position.x,position.y-40));
            block[1].setPosition(sf::Vector2f(position.x,position.y-80));
            block[2].setPosition(sf::Vector2f(position.x+40,position.y-40));
            block[3].setPosition(sf::Vector2f(position.x+40,position.y));
    }
    if(gen==7)
    {
            block[0].setPosition(sf::Vector2f(position.x,position.y-40));
            block[1].setPosition(sf::Vector2f(position.x,position.y));
            block[2].setPosition(sf::Vector2f(position.x+40,position.y-40));
            block[3].setPosition(sf::Vector2f(position.x+40,position.y-80));
    }
}

bool shape::movement(sf::Vector2f destination, char temp)
{
    bool invalid = false;
    for (int i=0;i<4;++i)
        if(block[i].getPosition().y == 800 && temp == 's' || block[i].getPosition().x == 260 && temp == 'a' || block[i].getPosition().x == 620 && temp == 'd' )
            invalid = true;

    if (!invalid)
        for (int i=0;i<4;++i)
            block[i].move(destination);
    position = position + destination;
    return invalid;
}

void shape::rotater()
{

    if (gen == 1)
    {
        sf::Vector2f temp;
        temp = block[0].getPosition();
        if (flag == 0)
        {
            block[1].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x+80,temp.y));
            flag = 1;
        }
        else
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[3].setPosition(sf::Vector2f(temp.x,temp.y+80));
            flag = 0;
        }


        for (int i=0;i<4;++i)
        {
            currentposition = block[i].getPosition();
            if (currentposition.x < 260)
                movement(sf::Vector2f(40,0),'d');
            if (currentposition.x > 620)
                movement(sf::Vector2f(-40,0),'a');
            if (currentposition.y > 800)
                movement(sf::Vector2f(0,-40),'a');
        }
    }
    if (gen == 3)
    {

        sf::Vector2f temp;
        temp = block[0].getPosition();

        if (flag == 0)
        {
            block[1].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x,temp.y-40));

            flag = 1;
        }

        else if (flag == 1)
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[3].setPosition(sf::Vector2f(temp.x-40,temp.y));
            flag = 2;
        }

        else if (flag == 2)
        {
            block[1].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x,temp.y+40));
            flag = 3;
        }

        else if (flag == 3)
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[3].setPosition(sf::Vector2f(temp.x+40,temp.y));
            flag = 0;
        }

    }
    if (gen == 4)
    {

        sf::Vector2f temp;
        temp = block[0].getPosition();

        if (flag == 0)
        {
            block[1].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x+40,temp.y-40));
            flag = 1;
        }

        else if (flag == 1)
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[3].setPosition(sf::Vector2f(temp.x-40,temp.y-40));
            flag = 2;
        }

        else if (flag == 2)
        {
            block[1].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x-40,temp.y+40));
            flag = 3;
        }

        else if (flag == 3)
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[3].setPosition(sf::Vector2f(temp.x+40,temp.y+40));
            flag = 0;
        }

    }
    if (gen == 5)
    {

        sf::Vector2f temp;
        temp = block[0].getPosition();

        if (flag == 0)
        {
            block[1].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x+40,temp.y+40));
            flag = 1;
        }

        else if (flag == 1)
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[3].setPosition(sf::Vector2f(temp.x+40,temp.y-40));
            flag = 2;
        }

        else if (flag == 2)
        {
            block[1].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x-40,temp.y-40));
            flag = 3;
        }

        else if (flag == 3)
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[3].setPosition(sf::Vector2f(temp.x-40,temp.y+40));
            flag = 0;
        }

    }
    if (gen == 6)
    {

        sf::Vector2f temp;
        temp = block[0].getPosition();

        if (flag == 0)
        {
            block[1].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[3].setPosition(sf::Vector2f(temp.x+40,temp.y-40));
            flag = 3;
        }

        else if (flag == 1)
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[2].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x-40,temp.y-40));
            flag = 2;
        }
        else if (flag == 2)
        {
            block[1].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[3].setPosition(sf::Vector2f(temp.x-40,temp.y+40));
            flag = 3;
        }

        else if (flag == 3)
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[2].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x+40,temp.y+40));
            flag = 0;
        }
    }
    if (gen == 7)
    {

        sf::Vector2f temp;
        temp = block[0].getPosition();

        if (flag == 0)
        {
            block[1].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[3].setPosition(sf::Vector2f(temp.x-40,temp.y-40));
            flag = 3;
        }

        else if (flag == 1)
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y-40));
            block[2].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x-40,temp.y+40));
            flag = 2;
        }
        else if (flag == 2)
        {
            block[1].setPosition(sf::Vector2f(temp.x-40,temp.y));
            block[2].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[3].setPosition(sf::Vector2f(temp.x+40,temp.y+40));
            flag = 3;
        }

        else if (flag == 3)
        {
            block[1].setPosition(sf::Vector2f(temp.x,temp.y+40));
            block[2].setPosition(sf::Vector2f(temp.x+40,temp.y));
            block[3].setPosition(sf::Vector2f(temp.x+40,temp.y-40));
            flag = 0;
        }
    }
}
