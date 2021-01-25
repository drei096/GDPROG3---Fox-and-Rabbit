#include <ctime>
#include "Fox.h"

void Fox::move(int playerX, int playerY)
{
	this->foxSprite.setPosition(playerPos.x + playerX, playerPos.y + playerY);
	playerPos = Vector2f(playerPos.x + playerX, playerPos.y + playerY);
}

void Fox::spriteMove(int left, int top) {
	foxTexture.loadFromFile("foxsprite.png");
	foxSprite.setTexture(foxTexture);
	Vector2u textureSize = foxTexture.getSize();
	textureSize.x /= 12;
	textureSize.y /= 8;
	this->foxSprite.setTextureRect(IntRect(textureSize.x * left, textureSize.y * top, textureSize.x, textureSize.y));
	foxMove = IntRect(textureSize.x * left, textureSize.y * top, textureSize.x, textureSize.y);
}

void Fox::render(RenderTarget* target)
{
	target->draw(this->foxSprite);
}

Fox::Fox()
{
	this->setSprite();
	//randomize fox initial position
	float fInitPosX = rand() % 20;
	float fInitPosY = rand() % 20;
	playerPos = this->setInitPos(75.0f + (37 * fInitPosX), 15.0f + (34 * fInitPosY));
	foxScore = 0;
}

void Fox::setSprite()
{
	foxTexture.loadFromFile("foxsprite.png");
	foxSprite.setTexture(foxTexture);
	Vector2u textureSize = foxTexture.getSize();
	textureSize.x /= 12;
	textureSize.y /= 8;
	foxSprite.setTextureRect(IntRect(textureSize.x * 10, textureSize.y * 0, textureSize.x, textureSize.y));
}

Vector2f Fox::setInitPos(float x, float y)
{
	this->foxSprite.setPosition(x, y);
	return Vector2f(x, y);
}
