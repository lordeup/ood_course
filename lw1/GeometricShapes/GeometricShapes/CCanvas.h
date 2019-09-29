#pragma once
#include "CShapeDecorator.h"
#include "Const.h"

const sf::Color BACKGROUND_COLOR_RECTANGLE = sf::Color::Red;
const sf::Color BACKGROUND_COLOR_TRIANGLE = sf::Color::Yellow;
const sf::Color BACKGROUND_COLOR_CIRCLE = sf::Color::Green;

class CCanvas : public ICanvas
{
public:
	CCanvas(const unsigned int windowWidth, const unsigned int windowHeight, const std::string name);
	~CCanvas() = default;

	void DrawingShapes(const std::vector<ShapePtr>& shapes);
	void DrawCircle(sf::CircleShape circle, const CPoint& center) override;
	void DrawRectangle(sf::RectangleShape rectangle, float width, float height) override;
	void DrawTriangle(sf::ConvexShape triangle, const std::vector<CPoint>& points) override;

private:
	sf::RenderWindow m_window;

	unsigned int m_windowWidth;
	unsigned int m_windowHeight;

	std::string m_windowName;
};