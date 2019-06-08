#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "snake.h"
using namespace sf;
using namespace std;

//initialization of global variables
// int Game::columns = 15, Game::rows = 20;
Snake snake[Game::columns * Game:: rows];
Apple apple;
float delay = 0.2;
/*Game::Game()
{
    window.create(VideoMode(width, height), "Snake");
}*/

// method responsible for one single move on the board
void Game::gameover(RenderWindow & window_)
{
    snake[0].x = 0;
    snake[0].y = 0;
    sizeSnake = 1;
    moveDirection = 4;
    cout<<"Game over!"<<endl;
    window_.close();


    /*
    RenderWindow window(VideoMode(width, height), "Snake");
    Font font;
    Text text[1];
    if (!font.loadFromFile("arial.ttf"))
    {
        // handle error
    }
    text[0].setFont(font);
    text[0].setFillColor(Color::Red);
    text[0].setString("GAME OVER ");
    text[0].setPosition(Vector2f(width / 2, height / 2));
    window_.clear();
    window_.draw(text[0]);
    window_.display();

} */}
void Game:: move(RenderWindow & window)
{
    // moving of the snake by following head
    for (int i=sizeSnake; i>0; --i)
    {
        snake[i].x=snake[i-1].x;
        snake[i].y=snake[i-1].y;
    }
    // moving of head of the snake
    switch (moveDirection)
    {
    case 0:
        snake[0].y++;
        break;
    case 1:
        snake[0].x--;
        break;
    case 2:
        snake[0].x++;
        break;
    case 3:
        snake[0].y--;
        break;
    }
//eating apple
    if ((snake[0].x==apple.x) && (snake[0].y==apple.y))
    {
        sizeSnake++;
        delay -= 0.01;
        apple.x=rand() % columns;
        apple.y=rand() % rows;
    }

    // going through walls
    if (snake[0].x>columns-1)
    {
        //snake[0].x=0;
        gameover(window);
    }

    if (snake[0].x<0)
    {
        //snake[0].x=columns-1;
        gameover(window);
    }

    if (snake[0].y>rows-1)
    {
        gameover(window);// snake[0].y=0;
    }

    if (snake[0].y<0)
    {
       // snake[0].y=rows-1;
       gameover(window);
    }

//snake eating snake
    for (int i=1; i<sizeSnake; i++)
    {
        if (snake[0].x==snake[i].x && snake[0].y==snake[i].y)
        {
            sizeSnake=i;
            delay = 0.3-(0.01*i);
        }
    }


}


Menu::Menu(int w, int h)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        // handle error
    }

    menu[0].setFont(font);
    menu[0].setFillColor(Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}


void Menu::draw(RenderWindow &window_)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window_.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(Color::Red);
    }
}

//main method responsible for entirety of the game, especially graphics section

void Game::play()
{
    RenderWindow window(VideoMode(width, height), "Snake");
    // RenderWindow window(VideoMode(width, height), "Snake", Style::Close | Style::Resize);
    /*RectangleShape snake (Vector2f(300.0f, 100.0f));
    snake.setFillColor(Color::Green);
    snake.setOrigin(0.0f, 0.0f); */
    Texture textureBlock,textureSnake,textureApple;
    textureBlock.loadFromFile("white.png");
    textureSnake.loadFromFile("green.png");
    textureApple.loadFromFile("red.png");

    Sprite blockSprite(textureBlock);
    Sprite snakeSprite(textureSnake);
    Sprite appleSprite(textureApple);
    Clock clock;
    float timer = 0;

    apple.x=rand() %columns;
    apple.y=rand() %rows;
    while(window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        Event evnt; //there is 'evnt' instead of 'event', because 'event' is a special key word reserved for SFML library
        while(window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case Event::Closed:
                window.close();
                break;
                // there were other cases, but they weren't necessary for this game, at least right now
            }

        }
        // SFML part of moving head of the snake
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            moveDirection = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            moveDirection = 2;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            moveDirection=3;
        }

        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            moveDirection=0;
        }

        // nesting of the 'move' function
        if (timer>delay)
        {
            timer=0;
            move(window);
        }

        window.clear();
        // drawing fields
        for (int i=0; i<columns; i++)
        {
            for (int j=0; j<rows; j++)
            {
                blockSprite.setPosition(i*sizeBlock,j*sizeBlock);
                window.draw(blockSprite);
            }
        }
        for (int i=0; i<sizeSnake; i++)
        {
            snakeSprite.setPosition(snake[i].x*sizeBlock, snake[i].y*sizeBlock);
            window.draw(snakeSprite);
        }

        appleSprite.setPosition(apple.x*sizeBlock,  apple.y*sizeBlock);
        window.draw(appleSprite);

        window.display();


    }
}

void Game::start()
{
    RenderWindow window(VideoMode(width, height), "Snake");

    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                switch (event.key.code)
                {
                case Keyboard::Up:
                    menu.MoveUp();
                    break;

                case Keyboard::Down:
                    menu.MoveDown();
                    break;

                case Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        Game::play();
                        break;
                    case 1:
                        std::cout << "Option button has been pressed" << std::endl;
                        break;
                    case 2:
                        window.close();
                        break;
                    }

                    break;
                }

                break;
            case Event::Closed:
                window.close();

                break;

            }
        }
        window.clear();

        menu.draw(window);

        window.display();
    }
}


