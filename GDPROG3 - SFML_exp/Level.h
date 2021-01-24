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

	//RectangleShape enemy;
	
	

	float maxSpawnTimer, spawnTimer;
	int maxEnemies;

public:
	Button exitButton;
private:
	void initVars();
	void initWindow();
	void initFont();
	void initText();
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

