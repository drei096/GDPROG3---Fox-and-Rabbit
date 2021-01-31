/*
    GDPROG3 - MACHINE PROJECT - FOX AND RABBIT
    DEVELOPERS: GAURANA, ALDREY 
                TALLADOR, ERYN

    SUBMITTED ON: 

    UPDATE LIST 1/31/2021
    - Added Fox Sprite Animations
    - Added Rabbit Sprite Animations
    - Added Random Initial Positions of Fox and Rabbit
    - Added current enemies variable in Level.h
    - Added moves variable in Level.h
    - Added array modifier for enem in Level.h
    - Added random Rabbit movements
    - Set max enemies to 50
    - Set initial current enemies to 3
    - Added eat rabbits in "case Event::KeyPressed:" (either by collision or moving to rabbit tile; checks 2 times)
    - Added rabbit multiplier and move checker inside "Level::update()"
    - Added checker if rabbits are more than 50 or 0 inside "Level::update()"
    - Added multiple render of rabbits based on the current number of enemies
    - Added checker inside rabbit render if rabbit initial position is the same as player
    - Removed commented out code

    NOTE: Yung ginawa ko para magamit tong SFML file na ito is dun sa properties pinath ko lang yung C++ at Linker sa own SFML folders ko (include(C++) and lib(Linker))
    If ayaw gumana try mo gamitin si 32-bit version ni SFML tas debug is set to x86 and platform is Win32
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>

#include "Level.h"
#include "Game.h"
#include "Button.h"
#include "GameTile.h"


using namespace std;
using namespace sf;

int main()
{
    //random seed generator
    srand(static_cast<unsigned>(time(0)));

    Game game;
    
    //MAIN MENU
    while (game.isWindowOpen())
    {
        game.update();
        game.render();
    }

    Level gameLevel;

    //GAME LEVEL
    while (gameLevel.isWindowOpen())
    {
        gameLevel.update();
        gameLevel.render();
    }

    return 0;
}
