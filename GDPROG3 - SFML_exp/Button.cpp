#include "Button.h"

using namespace sf;
using namespace std;

Button::Button()
{
	this->initShape();
	this->setBackColor(Color::White);
	button.setOutlineColor(Color::Blue);
	button.setOutlineThickness(10.0f);
	this->setTextColor(Color::Blue);
}

void Button::initFont(Font& font)
{
	textButton.setFont(font);
}

void Button::setBackColor(Color color)
{
	button.setFillColor(color);
}

void Button::setTextColor(Color color)
{
	textButton.setColor(color);
}


void Button::setPosition(Vector2f pos)
{
	button.setPosition(pos);
	float xPos = (pos.x + button.getLocalBounds().width / 2) - textButton.getLocalBounds().width / 2; 
	float yPos = (pos.y + button.getLocalBounds().height / 2) - textButton.getLocalBounds().height / 2;
	textButton.setPosition(xPos, yPos);
}

void Button::renderButton(RenderTarget* target, string text, float buttonX, float buttonY, float textX, float textY)
{
	this->textButton.setString(text);
	textButton.setPosition(textX, textY);
	button.setPosition(buttonX, buttonY);
	target->draw(this->button);
	target->draw(this->textButton);
}

bool Button::isMouseHover(RenderWindow &window)
{
	float mouseX = Mouse::getPosition(window).x, mouseY = Mouse::getPosition(window).y;

	float btnPosX = button.getPosition().x, btnPosY = button.getPosition().y;

	float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
	float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
	{
		return true;
	}
	return false;
}

void Button::initShape()
{
	this->button.setSize(Vector2f(300.0f, 100.0f));
}
