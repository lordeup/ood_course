#include "CCanvas.h"

CCanvas::CCanvas(const unsigned int windowWidth, const unsigned int windowHeight, const std::string name)
	: m_windowWidth(windowWidth)
	, m_windowHeight(windowHeight)
	, m_windowName(name)
{
}

void CCanvas::DrawingShapes(std::vector<std::shared_ptr<IShape>>& shapes)
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

void CCanvas::DrawCircle(const CPoint& center, float radius)
{
	if (m_window.isOpen())
	{
		sf::CircleShape circle(radius);
		circle.setPosition(center.GetX() - radius, center.GetY() - radius);
		circle.setFillColor(BACKGROUND_COLOR_CIRCLE);
		m_window.draw(circle);
	}
}

void CCanvas::DrawRectangle(const CPoint& leftTop, float width, float height)
{
	if (m_window.isOpen())
	{
		sf::RectangleShape rectangle;
		rectangle.setSize({ width, height });
		rectangle.setPosition(leftTop.GetX(), leftTop.GetY());
		rectangle.setFillColor(BACKGROUND_COLOR_RECTANGLE);
		m_window.draw(rectangle);
	}
}

void CCanvas::DrawTriangle(const std::vector<CPoint>& points)
{
	if (m_window.isOpen())
	{
		sf::ConvexShape triangle;
		triangle.setFillColor(BACKGROUND_COLOR_TRIANGLE);
		triangle.setPointCount(points.size());

		for (size_t i = 0; i < points.size(); ++i)
		{
			triangle.setPoint(i, { points[i].GetX(), points[i].GetY() });
		}

		m_window.draw(triangle);
	}
}