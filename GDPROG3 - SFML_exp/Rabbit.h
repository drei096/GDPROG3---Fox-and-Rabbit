#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

class Rabbit
{
private:
	Texture rabbitTexture;
	Sprite rabbitSprite;
public:
	Vector2f rabbitPos;
	IntRect rabbitMove;
public:
	void move(int playerX, int playerY);
	void spriteMove(int left, int top);
	void render(RenderTarget* target);
	Rabbit();
	void setSprite();
	Vector2f setInitPos(float x, float y);
	~Rabbit();
};

