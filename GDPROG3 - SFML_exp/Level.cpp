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
    dirt.clear();
    trees.clear();
    
    
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
        fenceRows.push_back(new GameTile("fence_vertical.png", 0, 730 - i * 16, false, false));
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
        fenceRows.push_back(new GameTile("fence_vertical.png", 965, 730 - i * 16, false, false));
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

    //20x20 DIRT TILES
    for (int i = 1; i <= 20; i++)
    {
        vector<GameTile*> dirtRows;
        for (int j = 1; j <= 20; j++)
        {
            dirtRows.push_back(new GameTile("dirt.png", j * 37 + 45, 34*i, true, false));
        }
        dirt.push_back(dirtRows);
    }

    //LEFT TREES
    for (int i = 0; i < 24; i++)
    {
        vector<GameTile*> treeRows;
        treeRows.push_back(new GameTile("trees_2.png", 0, i * 16 + 190, false, false));
        trees.push_back(treeRows);
    }

    this->house.loadFromFile("house.png");
    this->houseSprite.setTexture(house);
    this->houseSprite.setPosition(870.0f, 160.0f);

    this->house2.loadFromFile("house3.png");
    this->house2Sprite.setTexture(house2);
    this->house2Sprite.setPosition(330.0f, -60.0f);

    this->house3.loadFromFile("house3.png");
    this->house3Sprite.setTexture(house3);
    this->house3Sprite.setPosition(590.0f, -60.0f);
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
   this->ctrlUp.setPosition(1000.0f, 50.0f);
   this->ctrlDown.setString("A: Left");
   this->ctrlDown.setPosition(1000.0f, 100.0f);
   this->ctrlLeft.setString("S: Down");
   this->ctrlLeft.setPosition(1000.0f, 150.0f);
   this->ctrlRight.setString("D: Right");
   this->ctrlRight.setPosition(1000.0f, 200.0f);

   this->scoreText.setString("Score:");
   this->scoreText.setColor(Color::Green);
   this->scoreText.setPosition(1000.0f, 300.0f);
   this->rabbitsLeft.setString("Rabbits:");
   this->rabbitsLeft.setColor(Color::Green);
   this->rabbitsLeft.setPosition(1000.0f, 350.0f);
}


void Level::initWindow()
{
	this->window2 = new RenderWindow(VideoMode(1280,720), "Fox and Rabbit");
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
    this->exitButton.renderButton(this->window2, "Exit!", 1050.0f, 600.0f, 1095.0f, 635.0f); //EXIT BUTTON
    
    //DRAW GRASS
    for (int i = 0; i < 33; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            this->window2->draw(this->tiles[i][j]->sprite); 
        }
    }
    
    //DRAW DIRT TILES
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            this->window2->draw(this->dirt[i][j]->sprite);
        }
    }

    //DRAW FENCES
    for (int i = 0; i < 120; i++)
    {
        this->window2->draw(this->tiles[33 + i][0]->sprite);
    }

    //DRAW TREES
    for (int i = 0; i < 24; i++)
    {
        this->window2->draw(this->trees[i][0]->sprite);
    }
    
    //DRAW HOUSE
    this->window2->draw(this->houseSprite);
    this->window2->draw(this->house2Sprite);
    this->window2->draw(this->house3Sprite);

    //DRAW FOX
    this->player.render(this->window2);
    this->enem.render(this->window2);

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
            if (this->event.key.code == Keyboard::W)
            {
                if (this->player.playerPos.y <= 15)
                {
                    this->player.playerPos.y = 15;
                }
                else
                    this->player.move(0, -34);
            }
                
            if (this->event.key.code == Keyboard::A)
            {
                if (this->player.playerPos.x <= 60)
                {
                    this->player.playerPos.x = 60;
                }
                else
                    this->player.move(-37, 0);
            }
                
            if (this->event.key.code == Keyboard::S)
            {
                if (this->player.playerPos.y >= 680)
                    this->player.playerPos.y = 680;
                else
                    this->player.move(0, 34);
            }
            
            if (this->event.key.code == Keyboard::D)
            {
                if (this->player.playerPos.x >= 785)
                    this->player.playerPos.x = 785;
                else
                    this->player.move(37, 0);
            }
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

