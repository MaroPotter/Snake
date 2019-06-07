#ifndef SNAKE_H_
#define SNAKE_H_
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class Game
{
    int sizeBlock = 48;
    int width = sizeBlock * columns;
    int height = sizeBlock * rows;
    int sizeSnake, moveDirection = 4;
public:
    constexpr static int columns = 20, rows = 15;
    friend struct Snake;
    Game() {};
    void play();
    void move();

};
struct Snake
{
    int x,y;
};
struct Apple
{
    int x,y;
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
#endif
