#include "CTriangle.h"

CTriangle::CTriangle(sf::ConvexShape& shape, const std::vector<sf::Vector2f>& points)
	: CShapeDecorator(shape)
	, m_points(points)
	, m_triangle(shape)
{
	m_position = GetMidpoint();

	m_sides = GetSides();
	m_triangle.setFillColor(YELLOW_COLOR);

	for (size_t i = 0; i < m_points.size(); ++i)
	{
		m_triangle.setPoint(i, { m_points[i].x, m_points[i].y });
	}

	m_frame.setFillColor(SILVER_COLOR);
}

float CTriangle::GetArea() const
{
	float semiPerimeter = GetPerimeter() / MULTIPLICATION_FACTOR;
	return sqrt(semiPerimeter * (semiPerimeter - m_sides[0]) * (semiPerimeter - m_sides[1]) * (semiPerimeter - m_sides[2]));
}

float CTriangle::GetPerimeter() const
{
	return std::accumulate(m_sides.begin(), m_sides.end(), 0.f);
}

void CTriangle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_TRIANGLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
}

void CTriangle::DrawShape(sf::RenderWindow& window)
{
	m_triangle.setPosition(m_position);
	window.draw(m_triangle);
}

void CTriangle::DrawFrame(sf::RenderWindow& window)
{
	auto minMaxPointsX = GetMinMaxPointsX();
	auto minMaxPointsY = GetMinMaxPointsY();

	SetFramePosition();
	m_frame.setSize({ (*minMaxPointsX.second).x - (*minMaxPointsX.first).x, (*minMaxPointsY.second).y - (*minMaxPointsY.first).y });
	window.draw(m_frame);
}

bool CTriangle::IsCheckSide(const sf::Vector2f& position)
{
	return IsCheckSideShape(m_triangle, position);
}

void CTriangle::UpdatePosition(const sf::Vector2f& position)
{
	m_position = position - m_differentPosition;
	SetFramePosition();
}

void CTriangle::UpdatingDifferentPosition(const sf::Vector2f& position)
{
	m_differentPosition = position - m_position;
}

std::unordered_set<ShapePtr> CTriangle::GetShapes()
{
	return std::unordered_set<ShapePtr>();
}

std::pair<std::vector<sf::Vector2f>::iterator, std::vector<sf::Vector2f>::iterator> CTriangle::GetMinMaxPointsX()
{
	return std::minmax_element(m_points.begin(), m_points.end(), [](const sf::Vector2f& a, const sf::Vector2f& b) { return a.x < b.x; });
}

std::pair<std::vector<sf::Vector2f>::iterator, std::vector<sf::Vector2f>::iterator> CTriangle::GetMinMaxPointsY()
{
	return std::minmax_element(m_points.begin(), m_points.end(), [](const sf::Vector2f& a, const sf::Vector2f& b) { return a.y < b.y; });
}

float CTriangle::GetSideCounting(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const
{
	return sqrt(pow(secondPoint.x - firstPoint.x, POWER_NUMBER) + pow(secondPoint.y - firstPoint.y, POWER_NUMBER));
}

std::vector<float> CTriangle::GetSides() const
{
	std::vector<float> sides;
	sides.push_back(GetSideCounting(m_points[0], m_points[1]));
	sides.push_back(GetSideCounting(m_points[1], m_points[2]));
	sides.push_back(GetSideCounting(m_points[0], m_points[2]));

	return sides;
}

sf::Vector2f CTriangle::GetMidpoint() const
{
	sf::Vector2f midpoint;

	for (const auto& point : m_points)
	{
		midpoint += point;
	}

	return midpoint / (float)m_points.size();
}

void CTriangle::SetFramePosition()
{
	m_frame.setPosition({ m_position.x + (*GetMinMaxPointsX().first).x, m_position.y + (*GetMinMaxPointsY().first).y });
}
