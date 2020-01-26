#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class ICanvas
{
public:
	ICanvas() = default;
	virtual ~ICanvas() = default;

	virtual void DrawCircle(sf::CircleShape circle) = 0;
	virtual void DrawRectangle(sf::RectangleShape rectangle, float width, float height) = 0;
	virtual void DrawTriangle(sf::ConvexShape triangle, const std::vector<sf::Vector2f>& points) = 0;
};
