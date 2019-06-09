#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
class Game
{
    int sizeBlock = 48;
    int width = sizeBlock * columns;
    int height = sizeBlock * rows;
    int sizeSnake;
    int moveDirection = 4;
    vector<int> scores;


    //sf::RenderWindow window;
public:
   // Game();
    constexpr static int columns = 20;
    constexpr static int rows = 15;
    float delay;
    float delay_default = 0.2; // the default level of difficulty: intermediate
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

