#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
class Game
{
    int sizeBlock = 48;
    int width;
    int height;
    int sizeSnake;
    int moveDirection = 4;
    vector<int> scores;


    //sf::RenderWindow window;
public:
   // Game();
    int columns = 0;
    int rows = 0;
    float delay;
    float delay_default = 0.2; // the default level of difficulty: intermediate
    void getPlaceAppleBomb();
    void move(sf::RenderWindow &);
    void drawFields(sf::RenderWindow &);
    void play();
    void start();
    void gameover(sf::RenderWindow&);
};
struct Snake
{
    int x,y;
};
struct Apple
{
    int x,y;
};
struct Bomb
{
    int x,y;
};

