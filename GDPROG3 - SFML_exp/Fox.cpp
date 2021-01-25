#include "Fox.h"

void Fox::move(int playerX, int playerY)
{
	this->foxSprite.setPosition(playerPos.x + playerX, playerPos.y + playerY);
	playerPos = Vector2f(playerPos.x + playerX, playerPos.y + playerY);
}

void Fox::render(RenderTarget* target)
{
	target->draw(this->foxSprite);
}

Fox::Fox()
{
	this->setSprite();
	playerPos = this->setInitPos(60.0f, 15.0f);
	foxScore = 0;
}

void Fox::setSprite()
{
	foxTexture.loadFromFile("fox.gif");
	foxSprite.setTexture(foxTexture);
	foxSprite.setScale(0.1f, 0.1f);
}

Vector2f Fox::setInitPos(float x, float y)
{
	this->foxSprite.setPosition(x, y);
	return Vector2f(x, y);
}
