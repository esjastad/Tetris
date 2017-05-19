#include "header.h"

menumaker::menumaker()
{
    font.loadFromFile("arial.ttf");
    bot.setFont(font);
    bot.setString("Hard");
    bot.setCharacterSize(80);
    bot.setColor(sf::Color::White);
}

textmaker::textmaker()
{
    font.loadFromFile("arial.ttf");
    levelt.setFont(font);
    levelt.setString("1");
    levelt.setCharacterSize(40);
    levelt.setColor(sf::Color::White);
    levelt.setStyle(sf::Text::Bold);
    levelt.setOrigin((levelt.getLocalBounds().width/2),(levelt.getLocalBounds().height/2));

    scoret.setFont(font);
    scoret.setString("0");
    scoret.setCharacterSize(40);
    scoret.setColor(sf::Color::White);
    scoret.setStyle(sf::Text::Bold);
    scoret.setOrigin((scoret.getLocalBounds().width/2),(scoret.getLocalBounds().height/2));

    score = 0;
    level = 1;
    speed = (1.50/level);
    prevscore = 0;
}

void textmaker::valuechange(bool flag)
{
    std::stringstream ss;
    if (flag == true)
    {
        ss << score;
        scoret.setString(ss.str());
        scoret.setOrigin((scoret.getLocalBounds().width/2),(scoret.getLocalBounds().height/2));
        scoret.setPosition(850,350);
    }
    else
    {
        prevscore = score;
        ss << level;
        levelt.setString(ss.str());
        levelt.setOrigin((levelt.getLocalBounds().width/2),(levelt.getLocalBounds().height/2));
        levelt.setPosition(850,490);
        speed = 1.50/level;
    }
}

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
        temporary = sf::Color::Cyan;
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
    gen = rand()%7+1;

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

bool TileMap::isempty(sf::Vector2u tileSize, int* tiles, unsigned int width, unsigned int height, node * current, char direction)
{
    bool temp = false;
    sf::Vector2f holder;

    for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // get the current tile number
                int tileNumber = tiles[i + j * width];
                if (tileNumber)
                {
                    sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                    quad[0].position = sf::Vector2f((i * tileSize.x), (j * tileSize.y));
                    for (int k = 0;k<4;++k)
                    {
                        holder = current->data.block[k].getPosition();

                        if (direction=='s' && holder.y == quad[0].position.y && holder.x == (quad[0].position.x+260) || holder.y == 800)
                        {
                            temp = true;
                        }
                        if (direction=='a' && holder.y == (quad[0].position.y + 40) && holder.x == (quad[0].position.x+300))
                        {
                            temp = true;
                        }
                        if (direction=='d' && holder.y == (quad[0].position.y + 40) && holder.x == (quad[0].position.x + 220))
                        {
                            temp = true;
                        }

                    }

                    //std::cout << "\n" << quad[0].position.x << "\t" << quad[0].position.y;
                }
                for (int k = 0;k<4;++k)
                {
                    holder = current->data.block[k].getPosition();
                    if (holder.y == 800 && direction=='s')
                        temp = true;
                }

            }

    return temp;
}

bool TileMap::stamp(node * current, int tiles[], sf::Vector2u tileSize, unsigned int width, unsigned int height, sf::Clock clock, sf::Time elapsed1, sf::RenderWindow & window, node * temp, TileMap gameboard, background game, sf::Sound sound, sf::SoundBuffer soundstamp, textmaker & mytext, sf::Music & music)
{
    sf::Vector2f holder;

    for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // get the current tile number
                int tileNumber = tiles[i + j * width];
                if (!tileNumber)
                {
                    sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                    quad[0].position = sf::Vector2f((i * tileSize.x), (j * tileSize.y));
                    for (int k = 0;k<4;++k)
                    {
                        holder = current->data.block[k].getPosition();

                        if (holder.y == (quad[0].position.y + 40) && holder.x == (quad[0].position.x+260))
                        {
                            tiles[i + j * width] = 1;


                        }
                        if (holder.y == 0)
                            reset = true;



                    }
                }
            }

    if (reset)
    {
        music.stop();
        mytext.score = 0;
        mytext.level = 1;
        mytext.speed = (1.50/mytext.level);
        mytext.prevscore = 0;


        sound.setBuffer(soundstamp);
        for (int i = height-1; i > -1; --i)
        {
            for (int j = 0; j < width; ++j)
            {
                tiles[j + i * width] = 1;
            }

            if (gameboard.load("mainmap.png", sf::Vector2u(40, 40), tiles, 10, 20))
            std::cout << "\n";

            sound.play();

            clock.restart();
            elapsed1 = clock.getElapsedTime();
            while (elapsed1.asSeconds() < 0.05 && window.isOpen())
            {
                elapsed1 = clock.getElapsedTime();
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                    {
                    window.close();
                    }
                }


                window.clear();
                window.draw(gameboard);
                window.draw(game.border);
                window.draw(mytext.scoret);
                window.draw(mytext.levelt);
                window.display();
            }

        }

        clock.restart();
        while (elapsed1.asSeconds() < 3 && window.isOpen())
        {
            elapsed1 = clock.getElapsedTime();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                window.close();
                }
            }
        }

        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
            {
                tiles[j + i * width] = 0;
            }

        if (gameboard.load("mainmap.png", sf::Vector2u(40, 40), tiles, 10, 20))
        std::cout << "\n";

        reset=false;
        mytext.valuechange(true);
        mytext.valuechange(false);
        return true;
    }
    return false;
}

void TileMap::tetris(int tiles[], unsigned int width, unsigned int height, sf::Clock clock, sf::Time elapsed1, sf::RenderWindow & window, node * temp, TileMap gameboard, background game, sf::Sound sound, sf::SoundBuffer soundtetris, textmaker & mytext, sf::SoundBuffer specialbuf)
{
    bool eraser = true;
    bool reassign = false;
    int location[]= {0,0,0,0,};
    int repetitions = 0;
    int r=0;
    sound.setBuffer(soundtetris);
    sf::Sound special;
    special.setBuffer(specialbuf);
    for (unsigned int i = 0; i < height; ++i)
    {
            for (unsigned int j = 0; j < width; ++j)
            {
                if (tiles[j + i * width] != 1)
                {

                    eraser = false;
                }
            }

            if (eraser)
            {
                location[repetitions] = i;
                ++repetitions;
                mytext.score = mytext.score + (1000 * repetitions);
                if (repetitions == 4)
                {
                    special.play();
                }

                reassign = true;
            }
        eraser = true;
    }

    clock.restart();
    sf::Clock clock2;
    sf::Time elapsed2;
    clock2.restart();
    elapsed1 = clock.getElapsedTime();
    elapsed2 = clock2.getElapsedTime();

    if (repetitions)
    {
        mytext.valuechange(true);
        if (repetitions!=4)
            sound.play();
                while ( elapsed1.asSeconds() < 0.5  && window.isOpen())
                {
                    elapsed1 = clock.getElapsedTime();
                    elapsed2 = clock2.getElapsedTime();
                    if (elapsed2.asSeconds() < 0.1)
                    {
                        for (int i = location[r]; r < repetitions;++r)
                        {
                            i = location[r];
                            for (int j = 0; j < width; ++j)
                            {
                                tiles[j + i * width] = 2;
                            }

                        }


                    }
                    r=0;
                    if (elapsed2.asSeconds() > 0.1)
                    {
                        for (int i = location[r]; r < repetitions;++r)
                        {
                            i = location[r];
                            for (int j = 0; j < width; ++j)
                            {
                                tiles[j + i * width] = 1;
                            }
                        }

                    }
                    r=0;
                    if (gameboard.load("mainmap.png", sf::Vector2u(40, 40), tiles, 10, 20))
                    std::cout << "\n";

                    if (elapsed2.asSeconds() > 0.2)
                        clock2.restart();

                    sf::Event event;
                    while (window.pollEvent(event))
                    {
                        if(event.type == sf::Event::Closed)
                        {
                        window.close();
                        }
                    }
                    window.clear();
                    window.draw(gameboard);
                    for(int i=0;i<4;++i)
                    {
                        window.draw(temp->data.block[i]);
                    }
                    window.draw(mytext.scoret);
                    window.draw(mytext.levelt);
                    window.draw(game.border);
                    window.display();
                }
                for (int i = location[r]; r < repetitions;++r)
                    for (unsigned int j = 0; j < width; ++j)
                    {
                        tiles[j + i * width] = 0;
                    }

    }

    if (reassign)
    {

        for (int p = 0; p < repetitions;++p)
        {
            for (int i = location[p]-1; i > -1; --i)
            {
                for (int j = 0; j < width; ++j)
                {
                    tiles[j + (i+1)* width] = tiles[j + i * width];
                }
            }
        }


        for (int j = 0; j < width; ++j)
        {
            tiles[j] = 0;
        }

    }

}
