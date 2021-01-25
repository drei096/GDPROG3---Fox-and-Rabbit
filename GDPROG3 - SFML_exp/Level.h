#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Button.h"
#include "GameTile.h"
#include "Fox.h"
#include "Rabbit.h"
using namespace sf;
using namespace std;

class Level
{
private:
	RenderWindow *window2;
	Event event;
	Vector2i mousePosWindow;
	Font font;
	Text ctrlUp,ctrlDown,ctrlLeft,ctrlRight,scoreText,rabbitsLeft;
	Texture grass, fenceHorizontal, fenceVertical, house, house2, house3;
	Sprite grassTile, fenceHSprite, fenceVSprite, houseSprite, house2Sprite, house3Sprite;
	Fox player;
	Rabbit enem[100];

	vector<vector<GameTile*>> tiles;
	vector<vector<GameTile*>> dirt;
	vector<vector<GameTile*>> trees;
	vector<Vector2i>enemyPos;
	

	float maxSpawnTimer, spawnTimer;
	int maxEnemies, gridLength, moves, currentEnemies;

public:
	Button exitButton;
	

private:
	void initVars();
	void initWindow();
	void initFont();
	void initText();
	void initTiles();
	
	//void generateEnemy();
public:
	Level();
	void update(); 
	void render();
	void renderGUI(RenderTarget* target);
	void pollEvents();
	const bool isWindowOpen() const;
	//void spawnEnemies();
	void updateGUI();
	void initEnemies();
	void updateEnemies();
};

