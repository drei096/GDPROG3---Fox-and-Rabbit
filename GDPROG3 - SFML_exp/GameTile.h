#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameTile
{
public:
	Vector2f pos;
	Texture texture;
	Sprite sprite;
	bool isPassable;
	bool isExit;

public:
	GameTile(string, float, float, bool, bool);
	bool setSprite(string);
};

