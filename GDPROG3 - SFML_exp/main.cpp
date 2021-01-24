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
