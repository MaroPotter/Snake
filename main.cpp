#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "menu.h"
using namespace std;

int main()
{

    srand(time(NULL));
    Game game;
    game.start();
    return 0;
}
