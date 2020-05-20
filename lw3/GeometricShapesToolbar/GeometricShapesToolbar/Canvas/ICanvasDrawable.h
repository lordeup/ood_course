#pragma once
#include "SFML/Graphics.hpp"

class ICanvasDrawable
{
public:
	ICanvasDrawable() = default;
	virtual ~ICanvasDrawable() = default;

	virtual void DrawShape(sf::RenderWindow& window) = 0;
	virtual void DrawFrame(sf::RenderWindow& window) = 0;

	virtual bool IsCheckSide(const sf::Vector2f& position) = 0;

	virtual void UpdatePosition(const sf::Vector2f& position) = 0;
	virtual void UpdatingDifferentPosition(const sf::Vector2f& position) = 0;
};