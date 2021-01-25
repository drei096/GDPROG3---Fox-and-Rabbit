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

/*
    UPDATE LIST 1/26/2021
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

    NOTE: Yung ginawa ko para magamit tong SFML file na ito is dun sa properties pinath ko lang yung C++ at Linker sa own SFML folders ko (include(C++) and lib(Linker))
    If ayaw gumana try mo gamitin si 32-bit version ni SFML tas debug is set to x86 and platform is Win32
*/

using namespace std;
using namespace sf;

int main()
{
    //random seed generator
    srand(static_cast<unsigned>(time(0)));

    Game game;
    

    /*
    RectangleShape player(Vector2f(100.0f,100.0f));
    Texture playerTexture;
    View view(Vector2f(0.0f, 0.0f), Vector2f(1366, 768));

    playerTexture.loadFromFile("spaceship1.png");
    player.setTexture(&playerTexture);
    
    player.setOrigin(50.0f, 50.0f);
    */
    /*
    Animation animation(&playerTexture, Vector2u(4, 0), 0.3f);
    float deltaTime = 0.0f;
    Clock clock;
    */

    while (game.isWindowOpen())
    {
        game.update();
        game.render();
        
        //level.update();
        //level.render();



        //deltaTime = clock.restart().asSeconds();

        //Event event; //event union, class siya pero members can only be accessed one at a time
        

        //animation.update(0, deltaTime);
        //player.setTextureRect(animation.uvRect);

        /*
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos = Mouse::getPosition(window);
            player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }
        

        window.clear();
        
        window.draw(player);
        window.display();
        */
    }

    Level gameLevel;

    while (gameLevel.isWindowOpen())
    {
        gameLevel.update();
        gameLevel.render();
    }

    return 0;
}


//FOR REFERENCE PURPOSES

//KEYBOARD RECOG (WASD INPUTS)
/*
if (Keyboard::isKeyPressed(Keyboard::W))
{
    player.move(0.0f, -0.1f);
}
if (Keyboard::isKeyPressed(Keyboard::S))
{
    player.move(0.0f, 0.1f);
}
if (Keyboard::isKeyPressed(Keyboard::A))
{
    player.move(-0.1f, 0.0f);
}
if (Keyboard::isKeyPressed(Keyboard::D))
{
    player.move(0.1f, 0.0f);
}
*/
