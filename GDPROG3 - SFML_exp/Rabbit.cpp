#include "Rabbit.h"

void Rabbit::render(RenderTarget* target)
{
	this->rabbitSprite.setPosition(rabbitPos);
	target->draw(this->rabbitSprite);
}

Rabbit::Rabbit()
{
	this->setSprite();
	rabbitPos = this->setInitPos(119.0f, 34.0f);
}

void Rabbit::setSprite()
{
	rabbitTexture.loadFromFile("rabbit.png");
	rabbitSprite.setTexture(rabbitTexture);
	rabbitSprite.setScale(0.16f, 0.16f);
}

Vector2f Rabbit::setInitPos(float x, float y)
{
	return Vector2f(x,y);
}

Rabbit::~Rabbit()
{
}

