#include "CCanvas.h"

CCanvas::CCanvas(const unsigned int windowWidth, const unsigned int windowHeight, const std::string name)
	: m_windowWidth(windowWidth)
	, m_windowHeight(windowHeight)
	, m_windowName(name)
{
}

void CCanvas::DrawingShapes(const std::vector<ShapePtr>& shapes)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = ANTIALIASING_LEVEL;
	m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), m_windowName, sf::Style::Default, settings);

	m_window.clear();

	for (auto shape : shapes)
	{
		shape->Draw(*this);
	}

	m_window.display();

	while (m_window.isOpen())
	{
		sf::Event event;

		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}
	}
}

void CCanvas::DrawCircle(sf::CircleShape circle, const CPoint& center)
{
	if (m_window.isOpen())
	{
		circle.setPosition(center.GetX() - circle.getRadius(), center.GetY() - circle.getRadius());
		circle.setFillColor(BACKGROUND_COLOR_CIRCLE);
		m_window.draw(circle);
	}
}

void CCanvas::DrawRectangle(sf::RectangleShape rectangle, float width, float height)
{
	if (m_window.isOpen())
	{
		float halfWidth = width / MULTIPLICATION_FACTOR;
		float halfHeight = height / MULTIPLICATION_FACTOR;
		rectangle.setSize({ width, height });
		rectangle.setPosition(halfWidth, halfHeight);
		rectangle.setFillColor(BACKGROUND_COLOR_RECTANGLE);
		m_window.draw(rectangle);
	}
}

void CCanvas::DrawTriangle(sf::ConvexShape triangle, const std::vector<CPoint>& points)
{
	if (m_window.isOpen())
	{
		triangle.setFillColor(BACKGROUND_COLOR_TRIANGLE);

		for (size_t i = 0; i < points.size(); ++i)
		{
			triangle.setPoint(i, { points[i].GetX(), points[i].GetY() });
		}

		m_window.draw(triangle);
	}
}