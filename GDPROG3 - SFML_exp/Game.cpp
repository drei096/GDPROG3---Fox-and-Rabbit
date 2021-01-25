#include <iostream>
#include "Game.h"

using namespace sf;
using namespace std;

void Game::initVars()
{
    this->window = nullptr;
}

void Game::initFont()
{
    this->font.loadFromFile("Pixeled.ttf");
}

void Game::initText()
{
    this->text.setFont(this->font);
    this->text.setFillColor(Color::White);
    this->text.setCharacterSize(24);
    //this->text.setPosition(20.0f, 20.0f);
}

void Game::initBg()
{
    this->bg.loadFromFile("mmbg.jpeg");
    this->mmBg.setTexture(this->bg);
}


void Game::renderGUI(RenderTarget* target)
{
    target->draw(this->text);
}

void Game::updateGUI(string text,float posX, float posY)
{
    stringstream ss;

    ss << text;

    this->text.setString(ss.str());
    this->text.setPosition(posX, posY);
    this->text.setCharacterSize(35);
}

void Game::renderBg()
{
    this->window->draw(this->mmBg);
}

void Game::initWindow()
{
    this->window = new RenderWindow(VideoMode(1280,720), "Fox and Rabbit");
    this->window->setFramerateLimit(60);
}

Game::Game()
{
    this->initVars();
    this->initWindow();
    this->initBg();
    this->initFont();
    this->button1.initFont(this->font);
    this->button2.initFont(this->font);
    this->initText();
    //this->generateEnemy();
}

void Game::update()
{
    this->pollEvents();
    //this->spawnEnemies();
    this->updateMousePos();

    this->updateGUI("FOX AND RABBIT", 320,20);
}

void Game::render()
{
    this->window->clear();

    //DRAW GAME OBJECTS HERE
    this->renderBg();

    this->renderGUI(this->window);
    this->button1.renderButton(this->window, "Play!", 530, 190, 575, 230);
    this->button2.renderButton(this->window, "Exit!", 530, 600, 575, 640);
    //this->enemy.render(this->window);
    //this->window->draw(this->enemy);

    this->window->display();
}


const bool Game::isWindowOpen() const
{
    return this->window->isOpen();
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case Event::Closed:
            this->window->close();
            exit(0);
            break;
        case Event::Resized:
            //prints window width and height after resize
            cout << "New window width:" << event.size.width << "   New window height:" << event.size.height << endl;
            break;
        case Event::KeyPressed:
            if (this->event.key.code == Keyboard::Escape)
                this->window->close();
            exit(0);
            break;
        case Event::TextEntered:
            if (event.text.unicode < 128)
            {
                printf("%c", event.text.unicode);
            }
            break;
        case Event::MouseMoved:
            if (button1.isMouseHover(*window))
            {
                button1.setBackColor(Color::Cyan);
            }
            else
            {
                button1.setBackColor(Color::White);
            }
            if (button2.isMouseHover(*window))
            {
                button2.setBackColor(Color::Red);
            }
            else
            {
                button2.setBackColor(Color::White);
            }
            break;
        case Event::MouseButtonPressed:
            if (button1.isMouseHover(*window))
            {
                this->window->close();
            }
            if (button2.isMouseHover(*window))
            {
                this->window->close();
                exit(0);
            }
            break;
        default:
            break;
        }
    }
}

void Game::updateMousePos()
{
    this->mousePosWindow = Mouse::getPosition(*this->window);
}