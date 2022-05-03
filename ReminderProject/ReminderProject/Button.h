#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

enum ButtonStates
{
	BTN_NORMAL,
	BTN_HOVER,
	BTN_CLICKED
};

class Button
{
private:
	short unsigned currentButtonState;
	bool extraToggle;
	sf::RectangleShape shape;
	sf::Color normalColor;
	sf::Color hoverColor;
	sf::Color clickedColor;

public:
	Button(float x, float y, float width, float height, sf::Color normalColor, sf::Color hoverColor, sf::Color clickedColor);
	virtual ~Button();

	const bool isButtonPressed() const;
	
	bool Toggling();

	void UpdateButton(const sf::Vector2f mousePos, bool isToggleButton = false);
	void RenderButton(sf::RenderTarget* window);

	bool GetToggleState()
	{
		return extraToggle;
	}

};

