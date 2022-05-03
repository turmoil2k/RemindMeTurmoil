#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Color incNormalColor, sf::Color incHoverColor, sf::Color incClickedColor)
{
	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(width, height));

	this->normalColor = incNormalColor;
	this->hoverColor = incHoverColor;
	this->clickedColor = incClickedColor;

	this->shape.setFillColor(this->normalColor);

	this->currentButtonState = BTN_NORMAL;

	extraToggle = false;
}

Button::~Button()
{
	
}

//Accessors
const bool Button::isButtonPressed() const
{
	if (this->currentButtonState == BTN_CLICKED)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Button::Toggling()
{
	return extraToggle = !extraToggle;
}

//Functions

void Button::UpdateButton(const sf::Vector2f mousePos, bool isToggleButton)
{
	this->currentButtonState = BTN_NORMAL;

	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->currentButtonState = BTN_HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->currentButtonState = BTN_CLICKED;
			if (isToggleButton)
			{
				Toggling();
			}
		}
	}

	switch (this->currentButtonState)
	{
		case BTN_NORMAL:
			this->shape.setFillColor(this->normalColor);
			break;

		case BTN_HOVER:
			this->shape.setFillColor(this->hoverColor);
			break;

		case BTN_CLICKED:
			this->shape.setFillColor(this->clickedColor);
			break;

		default:
			this->shape.setFillColor(sf::Color::Magenta);
			break;
	}
}

void Button::RenderButton(sf::RenderTarget* targetWindow)
{
	targetWindow->draw(this->shape);
}
