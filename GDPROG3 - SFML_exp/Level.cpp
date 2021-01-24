#include<iostream>
#include "Level.h"

using namespace sf;
using namespace std;

void Level::initVars()
{
	this->window2 = nullptr;
    this->maxSpawnTimer = 10.0f;
    this->spawnTimer = this->maxSpawnTimer;
    this->maxEnemies = 10;
    this->gridLength = 20;
    this->playerPos = Vector2i(this->gridLength-1, this->gridLength-1);
}

void Level::initFont()
{
    this->font.loadFromFile("Pixeled.ttf");
}

void Level::initText()  
{
    this->ctrlDown.setFont(this->font);
    this->ctrlUp.setFont(this->font);
    this->ctrlLeft.setFont(this->font);
    this->ctrlRight.setFont(this->font);
    this->scoreText.setFont(this->font);
    this->rabbitsLeft.setFont(this->font);

    this->ctrlDown.setFillColor(Color::White);
    this->ctrlUp.setFillColor(Color::White);
    this->ctrlLeft.setFillColor(Color::White);
    this->ctrlRight.setFillColor(Color::White);
    this->scoreText.setFillColor(Color::White);
    this->rabbitsLeft.setFillColor(Color::White);

    this->ctrlDown.setCharacterSize(24);
    this->ctrlUp.setCharacterSize(24);
    this->ctrlLeft.setCharacterSize(24);
    this->ctrlRight.setCharacterSize(24);
    this->scoreText.setCharacterSize(24);
    this->rabbitsLeft.setCharacterSize(24);
    
    
    //this->text.setPosition(20.0f, 20.0f);
    //this->text.setString("Health:");
}

void Level::initTiles() //we draw here the game tiles
{
    tiles.clear();
    
    //GRASS
    for (int i = 0; i < 33; i++)
    {
        vector<GameTile*> grassRows;
        
        for (int j = 0; j < 33; j++)
        {
            grassRows.push_back(new GameTile("grass.jpg", j * 30, i * 30, true, false));
        }
        tiles.push_back(grassRows);
    }

    //UPPER LEFT FENCE
    for (int i = 0; i < 20; i++)
    {
        vector<GameTile*> fenceRows;
        fenceRows.push_back(new GameTile("fence_horizontal.png", i*16, 0, false, false));
        tiles.push_back(fenceRows);
    }

    //LOWER LEFT VERTICAL FENCE
    for (int i = 0; i < 10; i++)
    {
        vector<GameTile*> fenceRows;
        fenceRows.push_back(new GameTile("fence_vertical.png", 0, 700 - i * 16, false, false));
        tiles.push_back(fenceRows);
    }

    //LOWER LEFT FENCE
    for (int i = 0; i < 20; i++)
    {
        vector<GameTile*> fenceRows;
        fenceRows.push_back(new GameTile("fence_horizontal.png", i * 16, 700, false, false));
        tiles.push_back(fenceRows);
    }
    
    //UPPER RIGHT FENCE
    for (int i = 0; i < 20; i++)
    {
        vector<GameTile*> fenceRows;
        fenceRows.push_back(new GameTile("fence_horizontal.png", 950-16*i, 0, false, false));
        tiles.push_back(fenceRows);
    }

    //LOWER RIGHT VERTICAL FENCE
    for (int i = 0; i < 10; i++)
    {
        vector<GameTile*> fenceRows;
        fenceRows.push_back(new GameTile("fence_vertical.png", 965, 700 - i * 16, false, false));
        tiles.push_back(fenceRows);
    }

    //LOWER RIGHT FENCE
    for (int i = 0; i < 20; i++)
    {
        vector<GameTile*> fenceRows;
        fenceRows.push_back(new GameTile("fence_horizontal.png", 950 - 16 * i, 700, false, false));
        tiles.push_back(fenceRows);
    }

    //UPPER LEFT VERTICAL FENCE
    for (int i = 0; i < 10; i++)
    {
        vector<GameTile*> fenceRows;
        fenceRows.push_back(new GameTile("fence_vertical.png", 0, i*16 + 16, false, false));
        tiles.push_back(fenceRows);
    }

    //UPPER RIGHT VERTICAL FENCE
    for (int i = 0; i < 10; i++)
    {
        vector<GameTile*> fenceRows;
        fenceRows.push_back(new GameTile("fence_vertical.png", 965, i * 16 + 13, false, false));
        tiles.push_back(fenceRows);
    }
}


/*
void Game::spawnEnemies()
{
    
    if (this->spawnTimer < this->maxSpawnTimer)
    {
        this->spawnTimer += 1.0f;
    }
    else
    {
    
        if (this->enemies.size() < this->maxEnemies)
        {
            this->enemies.push_back(Enemy());
            cout << this->enemies.size();
            //this->spawnTimer = 0.0f;
        }
    }
}
*/

void Level::initEnemies()
{
    this->maxSpawnTimer = 40.0f;
    this->spawnTimer = this->maxSpawnTimer;
}

void Level::updateEnemies()
{
    
}

void Level::renderGUI(RenderTarget *target)
{
    target->draw(this->ctrlUp);
    target->draw(this->ctrlDown);
    target->draw(this->ctrlLeft);
    target->draw(this->ctrlRight);
    target->draw(this->scoreText);
    target->draw(this->rabbitsLeft);
}

void Level::updateGUI()
{
   this->ctrlUp.setString("W: Up");
   this->ctrlUp.setPosition(1150.0f, 50.0f);
   this->ctrlDown.setString("A: Left");
   this->ctrlDown.setPosition(1150.0f, 100.0f);
   this->ctrlLeft.setString("S: Down");
   this->ctrlLeft.setPosition(1150.0f, 150.0f);
   this->ctrlRight.setString("D: Right");
   this->ctrlRight.setPosition(1150.0f, 200.0f);

   this->scoreText.setString("Score:");
   this->scoreText.setColor(Color::Green);
   this->scoreText.setPosition(1100.0f, 300.0f);
   this->rabbitsLeft.setString("Rabbits:");
   this->rabbitsLeft.setColor(Color::Green);
   this->rabbitsLeft.setPosition(1100.0f, 350.0f);
}


void Level::initWindow()
{
	this->window2 = new RenderWindow(VideoMode::getDesktopMode(), "Fox and Rabbit");
    this->window2->setFramerateLimit(60);
}


Level::Level()
{
	this->initVars();
	this->initWindow();
    this->initFont();
    this->initText();
    this->exitButton.initFont(this->font);
    this->initTiles();
    
    this->initEnemies();
    //this->generateEnemy();
}

void Level::update()
{
    this->pollEvents();
    //this->spawnEnemies();

    //this->updateEnemies();
    this->updateGUI();
}

void Level::render()
{
    this->window2->clear(); 

    //DRAW GAME OBJECTS HERE
   
    this->renderGUI(this->window2);  //GUI
    this->exitButton.renderButton(this->window2, "Exit!", 1050.0f, 600.0f, 1145.0f, 635.0f); //EXIT BUTTON
    
    //DRAW GRASS
    for (int i = 0; i < 33; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            this->window2->draw(this->tiles[i][j]->sprite); 
        }
    }

    //DRAW FENCES
    for (int i = 0; i < 120; i++)
    {
        this->window2->draw(this->tiles[33+i][0]->sprite); 
    }
    
    
    this->window2->display();
}

/*
void Game::generateEnemy()
{
    this->enemy.setPosition(50.0f, 50.0f);
    this->enemy.setSize(Vector2f(100.0f, 100.0f));
    this->enemy.setFillColor(Color::Cyan);
}
*/


const bool Level::isWindowOpen() const
{
	return this->window2->isOpen();
}



void Level::pollEvents()
{
    while (this->window2->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case Event::Closed:
            this->window2->close();
            break;
        case Event::Resized:
            //prints window width and height after resize
            cout << "New window width:" << event.size.width << "   New window height:" << event.size.height << endl;
            break;
        case Event::KeyPressed:
            if (this->event.key.code == Keyboard::Escape)
                this->window2->close();
            break;  
        case Event::MouseMoved:
            if (exitButton.isMouseHover(*window2))
            {
                exitButton.setBackColor(Color::Cyan);
            }
            else
            {
                exitButton.setBackColor(Color::White);
            }
            break;
        case Event::MouseButtonPressed:
            if (exitButton.isMouseHover(*window2))
            {
                this->window2->close();
            }
        default:
            break;
        }
    }
}

