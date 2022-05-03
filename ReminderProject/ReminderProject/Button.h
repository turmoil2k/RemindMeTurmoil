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

	sf::RectangleShape shape;
	sf::Color normalColor;
	sf::Color hoverColor;
	sf::Color clickedColor;

public:
	Button(float x, float y, float width, float height, sf::Color normalColor, sf::Color hoverColor, sf::Color clickedColor);
	virtual ~Button();

	const bool isButtonPressed() const;

	void UpdateButton(const sf::Vector2f mousePos);
	void RenderButton(sf::RenderTarget* window);

};

