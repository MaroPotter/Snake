#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3
using namespace std;
class Game
{
    int sizeBlock = 48;
    int width = sizeBlock * columns;
    int height = sizeBlock * rows;
    int sizeSnake, moveDirection = 4;
    //sf::RenderWindow window;
public:
   // Game();
    constexpr static int columns = 20;
    constexpr static int rows = 15;
    void move();
    void play();
    void start();
};
struct Snake
{
    int x,y;
};
struct Apple
{
    int x,y;
};

class Menu
{
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
public:
    Menu(int w, int h);
	void draw(sf::RenderWindow &window_);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
};


/* class Settings
{
    SetTableSize();

    SetSpeed();

    SetGameMode(); //

    SetDifficulty();
};
class Bonusses
{
    friend Snake;


};


class Apple
{
private:
    int appleCoordinate;

public:
    Eated()
    {
        If ( IsApleSnakeCollision() )
        {
            appleCoordinate = randint(x);
            Grow(DifficultyAmplifiel);
        }

    }

};

class Snake
{

private:
    int headCoordinate;
    int tailCoordinate;
    double speed;
    int snakeSize;

public:

    Grow(double x)
    {
        speed += x;
    }
    //////////////// Zmiany kierunku ruchu weza
    MoveLeft()
    {
        If(IsLeft)
        {
            ///

        }

    }

    MoveRight()
    {
        If(IsRight)
        {
            ///

        }

    }


    MoveUp()
    {
        If(IsUp)
        {
            ///

        }

    }

    MoveDown()
    {
        If(IsDown)
        {
            ///

        }

    }

};
*/
