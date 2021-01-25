#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

class Entity
{
public:
	virtual void move(int playerX, int playerY) = 0;
	virtual void render(RenderTarget* target) = 0;
};

class Fox : public Entity
{
private:
	Texture foxTexture;
	Sprite foxSprite;
	int foxScore;
	Vector2i playerPos;

private:
	void move(int playerX, int playerY);
	void render(RenderTarget* target);

public:
	Fox(string, int, int);
	void setSprite(string);
};

class Rabbit : public Entity
{

};
