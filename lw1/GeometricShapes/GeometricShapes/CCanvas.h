#pragma once
#include "Const.h"
#include "ICanvas.h"
#include "IShape.h"
#include "SFML/Graphics.hpp"

const sf::Color BACKGROUND_COLOR_RECTANGLE = sf::Color::Red;
const sf::Color BACKGROUND_COLOR_TRIANGLE = sf::Color::Yellow;
const sf::Color BACKGROUND_COLOR_CIRCLE = sf::Color::Green;

class CCanvas : public ICanvas
{
public:
	CCanvas(const unsigned int windowWidth, const unsigned int windowHeight, const std::string name);
	~CCanvas() = default;

	void DrawingShapes(std::vector<std::shared_ptr<IShape>>& shapes);
	void DrawCircle(const CPoint& center, float radius) override;
	void DrawRectangle(const CPoint& leftTop, float width, float height) override;
	void DrawTriangle(const std::vector<CPoint>& points) override;

private:
	sf::RenderWindow m_window;

	unsigned int m_windowWidth;
	unsigned int m_windowHeight;

	std::string m_windowName;
};