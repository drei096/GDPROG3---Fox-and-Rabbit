#include "Rabbit.h"

void Rabbit::move(int rabbitX, int rabbitY)
{
	this->rabbitSprite.setPosition(rabbitPos.x + rabbitX, rabbitPos.y + rabbitY);
	rabbitPos = Vector2f(rabbitPos.x + rabbitX, rabbitPos.y + rabbitY);
}

void Rabbit::spriteMove(int left, int top) {
	rabbitTexture.loadFromFile("RabbitSpriteSheet.png");
	rabbitSprite.setTexture(rabbitTexture);
	Vector2u textureSize = rabbitTexture.getSize();
	textureSize.x /= 4;
	textureSize.y /= 8;
	this->rabbitSprite.setTextureRect(IntRect(textureSize.x * left, textureSize.y * top, textureSize.x, textureSize.y));
	rabbitMove = IntRect(textureSize.x * left, textureSize.y * top, textureSize.x, textureSize.y);
}

void Rabbit::render(RenderTarget* target)
{
	this->rabbitSprite.setPosition(rabbitPos);
	target->draw(this->rabbitSprite);
}

Rabbit::Rabbit()
{
	this->setSprite();
	//randomize rabbit initial position
	float rInitPosX = rand() % 20;
	float rInitPosY = rand() % 20;
	rabbitPos = this->setInitPos(62.0f + (37 * rInitPosX), 15.0f + (34 * rInitPosY));
}

void Rabbit::setSprite()
{
	rabbitTexture.loadFromFile("RabbitSpriteSheet.png");
	rabbitSprite.setTexture(rabbitTexture); 
	Vector2u textureSize = rabbitTexture.getSize();
	textureSize.x /= 4;
	textureSize.y /= 8;
	rabbitSprite.setTextureRect(IntRect(textureSize.x * 0, textureSize.y * 2, textureSize.x, textureSize.y));
}

Vector2f Rabbit::setInitPos(float x, float y)
{
	return Vector2f(x,y);
}

Rabbit::~Rabbit()
{
}

