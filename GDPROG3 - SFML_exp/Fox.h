#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;
class Fox
{
private:
	Texture foxTexture;
	Sprite foxSprite;
	int foxScore;
	Vector2f playerPos;
public:
	void move(int playerX, int playerY);
	void render(RenderTarget* target);
	Fox();
	void setSprite();
	Vector2f setInitPos(float x, float y);
};

