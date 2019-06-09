#pragma once
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3
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
    int GetPressedItem()
    {
        return selectedItemIndex;
    }
};
class Options
{
    int selectedItemOptionsIndex;
    sf::Font font;
    sf::Text menuOptions[MAX_NUMBER_OF_ITEMS];
public:
    Options(int, int);
    void draw(sf::RenderWindow &window_);
    void MoveUpOptions();
    void MoveDownOptions();
    int GetPressedOptionsItem()
    {
        return selectedItemOptionsIndex;
    }
};
