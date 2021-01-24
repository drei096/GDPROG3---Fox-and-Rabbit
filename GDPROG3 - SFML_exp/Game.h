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
#include "Level.h"

using namespace std;
using namespace sf;

class Game
{
private:
	RenderWindow* window;
	Event event;
	Vector2i mousePosWindow;
	Font font;
	Text text;
	Texture bg;
	Sprite mmBg;

public:
	Button button1, button2;

private:
	void initVars();
	void initWindow();
	void initFont();
	void initText();
	void initBg();
	//void generateEnemy();
public:
	Game();
	void update();
	void updateMousePos();
	void render();
	void renderGUI(RenderTarget* target);
	void pollEvents();
	const bool isWindowOpen() const;
	void updateGUI(string text, float posX, float posY);
	void renderBg();
};

