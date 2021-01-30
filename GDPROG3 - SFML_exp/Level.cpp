#include<iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include "Level.h"

using namespace sf;
using namespace std;
using namespace this_thread;
using namespace chrono;

void Level::initVars()
{
	this->window2 = nullptr;
    this->maxSpawnTimer = 10.0f;
    this->spawnTimer = this->maxSpawnTimer;
    this->maxEnemies = 50;
    this->gridLength = 20;
    this->moves = 0;
    this->currentEnemies = 3;
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
    this->scoreText1.setFont(this->font);
    this->rabbitsLeft1.setFont(this->font);
    this->scoreText2.setFont(this->font);
    this->rabbitsLeft2.setFont(this->font);
    this->gameLost.setFont(this->font);
    this->gameWon.setFont(this->font);

    this->ctrlDown.setFillColor(Color::White);
    this->ctrlUp.setFillColor(Color::White);
    this->ctrlLeft.setFillColor(Color::White);
    this->ctrlRight.setFillColor(Color::White);
    this->scoreText1.setFillColor(Color::White);
    this->rabbitsLeft1.setFillColor(Color::White);
    this->scoreText2.setFillColor(Color::White);
    this->rabbitsLeft2.setFillColor(Color::White);

    this->ctrlDown.setCharacterSize(24);
    this->ctrlUp.setCharacterSize(24);
    this->ctrlLeft.setCharacterSize(24);
    this->ctrlRight.setCharacterSize(24);
    this->scoreText1.setCharacterSize(24);
    this->rabbitsLeft1.setCharacterSize(24);
    this->scoreText2.setCharacterSize(24);
    this->rabbitsLeft2.setCharacterSize(24);
    this->gameLost.setCharacterSize(24);
    this->gameWon.setCharacterSize(24);
    
    
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
            dirtRows.push_back(new GameTile("dirt.png", i * 37 + 45, 34 * j, true, false));
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
    target->draw(this->scoreText1);
    target->draw(this->rabbitsLeft1);
    target->draw(this->scoreText2);
    target->draw(this->rabbitsLeft2);
}

void Level::updateGUI()
{
    string score, enemCount;
    score = to_string(this->player.foxScore);
    enemCount = to_string(currentEnemies);

   this->ctrlUp.setString("W: Up");
   this->ctrlUp.setPosition(1000.0f, 50.0f);
   this->ctrlDown.setString("A: Left");
   this->ctrlDown.setPosition(1000.0f, 100.0f);
   this->ctrlLeft.setString("S: Down");
   this->ctrlLeft.setPosition(1000.0f, 150.0f);
   this->ctrlRight.setString("D: Right");
   this->ctrlRight.setPosition(1000.0f, 200.0f);

   this->scoreText1.setString("Score:");
   this->scoreText1.setColor(Color::Green);
   this->scoreText1.setPosition(1000.0f, 300.0f);
   this->scoreText2.setString(score);
   this->scoreText2.setColor(Color::Green);
   this->scoreText2.setPosition(1200.0f, 300.0f);
   this->rabbitsLeft1.setString("Rabbits:");
   this->rabbitsLeft1.setColor(Color::Green);
   this->rabbitsLeft1.setPosition(1000.0f, 350.0f);
   this->rabbitsLeft2.setString(enemCount);
   this->rabbitsLeft2.setColor(Color::Green);
   this->rabbitsLeft2.setPosition(1200.0f, 350.0f);
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

    this->levelMusic.openFromFile("level_use.ogg");
    this->levelMusic.setVolume(20);
    this->levelMusic.play();
    this->levelMusic.setLoop(true);

    //this->stepFx.openFromFile("stepdirt_7.ogg");
    //this->stepFx.setVolume(80);

    
    this->initEnemies();
    //this->generateEnemy();
}

void Level::update()
{

    //rabbit updater every 3 moves
    if (moves == 3) {
        this->bunnyMultiply.openFromFile("boing.ogg");
        this->bunnyMultiply.setVolume(50);
        this->bunnyMultiply.play();

        currentEnemies *= 2;
        moves = 0;

        if (currentEnemies >= maxEnemies)
        {
            this->levelMusic.stop();
            this->over.openFromFile("game_over.ogg");
            this->over.setVolume(30);
            this->over.play();
        }
        
    }

    //check if rabbits are 50 and above //LOSS
    if (currentEnemies >= maxEnemies) 
    {
        this->isGameOver = 1;
        this->isGameWon = 0;
    }
    //check if no more rabbits  //WIN
    else if (currentEnemies == 0) 
    {
        this->won.openFromFile("win.ogg");
        this->won.setVolume(30);
        this->won.play();

        this->isGameOver = 1;
        this->isGameWon = 1;
    }

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

    //DRAW INITIAL RABBITS
    for (int i = 0; i < currentEnemies; i++) {
        this->enem[i].render(this->window2);
        //check if rabbit spawns on player tile
        if ((player.playerPos.x - 13 == enem[i].rabbitPos.x) && (player.playerPos.y == enem[i].rabbitPos.y)) 
        {
            for (int j = i; j < (currentEnemies - 1); j++)
                enem[j] = enem[j + 1];
            i--;
        }

        //check if rabbit spawns on top of another rabbit
        //ISSUES: Naghhang pag masyado na maraming rabbit
        /*
        for (int k = 0; k < i; k++) 
        {
            if ((enem[k].rabbitPos.x == enem[i].rabbitPos.x) && (enem[k].rabbitPos.y == enem[i].rabbitPos.y))
            {
                for (int j = i; j < (currentEnemies - 1); j++) 
                {
                    enem[j] = enem[j + 1];
                }
                i--;
            }
        }
        */
    }

    //DRAW GAME OVER
    if (this->isGameOver == 1 && this->isGameWon == 0)
    {
        this->gameLost.setString("You Lose!");
        this->gameLost.setColor(Color::Red);
        this->gameLost.setPosition(1000.0f, 450.0f);
        this->window2->draw(this->gameLost);
    }

    //DRAW GAME WON
    if (this->isGameOver == 1 && this->isGameWon == 1)
    {
        this->gameWon.setString("You Win!");
        this->gameWon.setColor(Color::Green);
        this->gameWon.setPosition(1000.0f, 450.0f);
        this->window2->draw(this->gameWon);
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
            {
                this->window2->close();
                break;
            }
            case Event::Resized: 
            {
                //prints window width and height after resize
                cout << "New window width:" << event.size.width << "   New window height:" << event.size.height << endl;
                break;
            }
            case Event::KeyPressed:
            {
                if (this->event.key.code == Keyboard::Escape)
                    this->window2->close();
                if (this->isGameOver == 0 && this->isGameWon == 0)
                {
                    if (this->event.key.code == Keyboard::W)
                    {
                        this->stepFx.openFromFile("stepdirt.ogg");
                        this->stepFx.setVolume(50);
                        this->stepFx.play();
                        this->stepFx.setLoop(false);
                        
                        this->player.spriteMove(10, 3);
                        if (this->player.playerPos.y <= 15)
                        {
                            this->player.playerPos.y = player.playerPos.y;
                        }
                        else
                            this->player.move(0, -34);
                    }

                    if (this->event.key.code == Keyboard::A)
                    {
                        this->stepFx.openFromFile("stepdirt.ogg");
                        this->stepFx.setVolume(50);
                        this->stepFx.play();
                        this->stepFx.setLoop(false);
                        
                        this->player.spriteMove(10, 1);
                        if (this->player.playerPos.x <= 75)
                        {
                            this->player.playerPos.x = player.playerPos.x;
                        }
                        else
                            this->player.move(-37, 0);
                    }

                    if (this->event.key.code == Keyboard::S)
                    {
                        this->stepFx.openFromFile("stepdirt.ogg");
                        this->stepFx.setVolume(50);
                        this->stepFx.play();
                        this->stepFx.setLoop(false);
                        
                        this->player.spriteMove(10, 0);
                        if (this->player.playerPos.y >= 646)
                            this->player.playerPos.y = player.playerPos.y;
                        else
                            this->player.move(0, 34);
                    }

                    if (this->event.key.code == Keyboard::D)
                    {
                        this->stepFx.openFromFile("stepdirt.ogg");
                        this->stepFx.setVolume(50);
                        this->stepFx.play();
                        this->stepFx.setLoop(false);
                        
                        this->player.spriteMove(10, 2);
                        if (this->player.playerPos.x >= 748)
                            this->player.playerPos.x = player.playerPos.x;
                        else
                            this->player.move(37, 0);
                    }

                    //Eats rabbit when fox ends up in same tile with rabbit (fox moves to same tile)
                    for (int i = 0; i < currentEnemies; i++)
                    {
                        if ((player.playerPos.x - 13 == enem[i].rabbitPos.x) && (player.playerPos.y == enem[i].rabbitPos.y))
                        {

                            this->eaten.openFromFile("eat.ogg");
                            this->eaten.setVolume(50);
                            this->eaten.play();
                            this->eaten.setLoop(false);

                            for (int j = i; j < (currentEnemies - 1); j++)
                                enem[j] = enem[j + 1];
                            i--;
                            currentEnemies--;
                            this->player.foxScore++;
                        }
                    }

                    //3 rabbits movement
                    for (int i = 0; i < currentEnemies; i++)
                    {
                        int rMove = rand() % 4;
                        //Upwards
                        if (rMove == 0) {
                            this->enem[i].spriteMove(0, 0);
                            if (this->enem[i].rabbitPos.y <= 15)
                            {
                                this->enem[i].rabbitPos.y = enem[i].rabbitPos.y;
                            }
                            else
                                this->enem[i].move(0, -34);
                        }
                        //Left
                        if (rMove == 1) {
                            this->enem[i].spriteMove(0, 1);
                            if (this->enem[i].rabbitPos.x <= 62)
                            {
                                this->enem[i].rabbitPos.x = enem[i].rabbitPos.x;
                            }
                            else
                                this->enem[i].move(-37, 0);
                        }
                        //Down
                        if (rMove == 2) {
                            this->enem[i].spriteMove(0, 2);
                            if (this->enem[i].rabbitPos.y >= 646)
                            {
                                this->enem[i].rabbitPos.y = enem[i].rabbitPos.y;
                            }
                            else
                                this->enem[i].move(0, 34);
                        }
                        //Right
                        if (rMove == 3) {
                            this->enem[i].spriteMove(0, 3);
                            if (this->enem[i].rabbitPos.x >= 735)
                            {
                                this->enem[i].rabbitPos.x = enem[i].rabbitPos.x;
                            }
                            else
                                this->enem[i].move(37, 0);
                        }
                    }


                    //Eats rabbit when fox ends up in same tile with rabbit (Collision)
                    for (int i = 0; i < currentEnemies; i++)
                    {
                        if ((player.playerPos.x - 13 == enem[i].rabbitPos.x) && (player.playerPos.y == enem[i].rabbitPos.y))
                        {
                            this->eaten.openFromFile("eat.ogg");
                            this->eaten.setVolume(50);
                            this->eaten.play();
                            this->eaten.setLoop(false);
                            for (int j = i; j < (currentEnemies - 1); j++)
                                enem[j] = enem[j + 1];
                            i--;
                            currentEnemies--;
                            this->player.foxScore++;
                        }
                    }
                    moves++;
                    break;
                }
                else
                    break; 
            }
            case Event::MouseMoved:
            {
                if (exitButton.isMouseHover(*window2))
                {
                    exitButton.setBackColor(Color::Cyan);
                }
                else
                {
                    exitButton.setBackColor(Color::White);
                }
                break;
            }
            case Event::MouseButtonPressed: 
            {
                if (exitButton.isMouseHover(*window2))
                {
                    this->exit.openFromFile("menupress.ogg");
                    this->exit.setVolume(100);
                    this->exit.play();

                    //sleep_for(milliseconds(3000 ));
                    //sleep_until(system_clock::now() + milliseconds(3000));

                    this->window2->close();
                }
                break;
            }
            default: 
            {
                break;
            }
        }
    }
}

