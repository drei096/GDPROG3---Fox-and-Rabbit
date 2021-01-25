#include "Entity.h"

void Fox::move(int playerX, int playerY)
{
	this->foxSprite.setPosition(playerPos.x + playerX, playerPos.y + playerY);
}

void Fox::render(RenderTarget* target)
{
	target->draw(this->foxSprite);
}

Fox::Fox(string textureName, int x, int y)
{
	playerPos = Vector2i(x, y);
	this->setSprite(textureName);
	foxScore = 0;
}

void Fox::setSprite(string textureName)
{
	foxTexture.loadFromFile(textureName);
	foxSprite.setTexture(foxTexture);
	foxSprite.setTextureRect(IntRect(0, 0, 30, 30));
}
