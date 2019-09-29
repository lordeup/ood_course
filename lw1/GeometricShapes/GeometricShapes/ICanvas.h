#pragma once
#include "CPoint.h"
#include "SFML/Graphics.hpp"
#include <vector>

class ICanvas
{
public:
	ICanvas() = default;
	virtual ~ICanvas() = default;

	virtual void DrawCircle(sf::CircleShape circle, const CPoint& center) = 0;
	virtual void DrawRectangle(sf::RectangleShape rectangle, float width, float height) = 0;
	virtual void DrawTriangle(sf::ConvexShape triangle, const std::vector<CPoint>& points) = 0;
};
