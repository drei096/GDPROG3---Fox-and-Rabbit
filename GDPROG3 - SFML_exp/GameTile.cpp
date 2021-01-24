#include "GameTile.h"

GameTile::GameTile(string textureName, float x, float y, bool passable, bool exit)
{
	pos = Vector2f(x, y);
	sprite.setPosition(pos);
	isPassable = passable;
	isExit = exit;
	this->setSprite(textureName);
}

bool GameTile::setSprite(string textureName)
{
	if (!texture.loadFromFile(textureName))
	{
		return false;
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 30, 30));
	return true;
	
}
