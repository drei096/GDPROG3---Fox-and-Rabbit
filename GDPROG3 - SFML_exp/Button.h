#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>
#include <sstream>

using namespace std;
using namespace sf;

class Button
{
private:
	RectangleShape button;
	Text textButton;

public:
	Button();
	void initFont(Font &font);
	void setBackColor(Color color);
	void setTextColor(Color color);
	void setPosition(Vector2f pos);
	void renderButton(RenderTarget *target, string text, float buttonX, float buttonY, float textX, float textY);
	bool isMouseHover(RenderWindow& window);

private:
	void initShape();
};

