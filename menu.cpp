#include "menu.h"
using namespace sf;

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
    menu[1].setString("Game mode");
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
Options::Options(int w, int h)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        // handle error
    }

    menuOptions[0].setFont(font);
    menuOptions[0].setFillColor(Color::Red);
    menuOptions[0].setString("Beginner");
    menuOptions[0].setPosition(Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menuOptions[1].setFont(font);
    menuOptions[1].setFillColor(Color::White);
    menuOptions[1].setString("Intermediate");
    menuOptions[1].setPosition(Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menuOptions[2].setFont(font);
    menuOptions[2].setFillColor(Color::White);
    menuOptions[2].setString("Legendary");
    menuOptions[2].setPosition(Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemOptionsIndex = 0;
}
void Options::draw(RenderWindow &window_)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window_.draw(menuOptions[i]);
    }
}

void Options::MoveUpOptions()
{
    if (selectedItemOptionsIndex - 1 >= 0)
    {
        menuOptions[selectedItemOptionsIndex].setFillColor(Color::White);
        selectedItemOptionsIndex--;
        menuOptions[selectedItemOptionsIndex].setFillColor(Color::Red);
    }
}

void Options::MoveDownOptions()
{
    if (selectedItemOptionsIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menuOptions[selectedItemOptionsIndex].setFillColor(Color::White);
        selectedItemOptionsIndex++;
        menuOptions[selectedItemOptionsIndex].setFillColor(Color::Red);
    }
}
