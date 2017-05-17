#include "header.h"
echo "# TetrisClone" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/esjastad/TetrisClone.git
git push -u origin master

data::data()
{

    gen = rand()%7+1;
    L = 340;
    R = 640;
    B = 800;

    if (gen == 1)
    {
        if (!grid.load("block.png", sf::Vector2u(40, 40), line, 4, 4))
            return ;
                    grid.setPosition(500,-40);
        grid.setOrigin(80,120);

    }

    if (gen == 2)
    {
        if (!grid.load("block.png", sf::Vector2u(40, 40), block, 4, 4))
            return ;
                    grid.setPosition(500,-40);
        grid.setOrigin(80,120);
    }

    if (gen == 3)
    {
        if (!grid.load("block.png", sf::Vector2u(40, 40), tshape, 4, 4))
            return ;
                    grid.setPosition(500,-40);
        grid.setOrigin(80,120);
    }

    if (gen == 4)
    {
        if (!grid.load("block.png", sf::Vector2u(40, 40), llshape, 4, 4))
            return ;
                    grid.setPosition(500,-40);
        grid.setOrigin(80,120);
    }

    if (gen == 5)
    {
        if (!grid.load("block.png", sf::Vector2u(40, 40), rlshape, 4, 4))
            return ;
                    grid.setPosition(500,-40);
        grid.setOrigin(80,120);
    }

    if (gen == 6)
    {
        if (!grid.load("block.png", sf::Vector2u(40, 40), zlshape, 4, 4))
            return ;
        grid.setPosition(500,-40);
        grid.setOrigin(80,120);
    }
    if (gen == 7)
    {
        if (!grid.load("block.png", sf::Vector2u(40, 40), zrshape, 4, 4))
            return ;
        grid.setPosition(500,-40);
        grid.setOrigin(80,120);
    }
}

void data::rotater()
{
    if (gen == 6)
    {

        if (flag == false)
        {
            grid.rotate(90);
            grid.setOrigin(80,80);
            flag = true;
            if (grid.getPosition().x == L)
            {
                grid.setPosition((grid.getPosition().x+40), grid.getPosition().y);
            }
            L = L+40;
        }
        else
        {
            grid.setOrigin(80,120);
            grid.rotate(-90);
            flag = false;
            L=L-40;
        }
    }
    return;
}

load::load()
{
    background.loadFromFile("borders.png");
    background.setSmooth(true);
    borders.setTexture(background);
}

