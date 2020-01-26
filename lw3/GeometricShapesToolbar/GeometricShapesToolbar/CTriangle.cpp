#include "CTriangle.h"

CTriangle::CTriangle(sf::ConvexShape& shape, const std::vector<sf::Vector2f>& points)
	: CShapeDecorator(shape)
	, m_points(points)
	, m_triangle(shape)
{
	m_prevPosition = { 0.f, 0.f };
}

float CTriangle::GetSideCounting(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const
{
	return sqrt(pow(secondPoint.x - firstPoint.x, POWER_NUMBER) + pow(secondPoint.y - firstPoint.y, POWER_NUMBER));
}

float CTriangle::GetPerimeter() const
{
	float side1 = GetSideCounting(m_points[0], m_points[1]);
	float side2 = GetSideCounting(m_points[1], m_points[2]);
	float side3 = GetSideCounting(m_points[0], m_points[2]);

	return side1 + side2 + side3;
}

float CTriangle::GetArea() const
{
	float side1 = GetSideCounting(m_points[0], m_points[1]);
	float side2 = GetSideCounting(m_points[1], m_points[2]);
	float side3 = GetSideCounting(m_points[0], m_points[2]);

	float semiPerimeter = (side1 + side2 + side3) / MULTIPLICATION_FACTOR;
	return sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
}

void CTriangle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_TRIANGLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
}

void CTriangle::Draw(ICanvas& canvas)
{
	canvas.DrawTriangle(m_triangle, m_points);
}

void CTriangle::DrawFrame(ICanvas& canvas)
{
	SetOutlineThickness(OUTLINE_THICKNESS);
	SetOutlineColor(BACKGROUND_COLOR_DRAW);
}

void CTriangle::DeleteFrame(ICanvas& canvas)
{
	SetOutlineColor(BACKGROUND_COLOR_TRIANGLE);
}

void CTriangle::Move(ICanvas& canvas, const sf::Vector2f& position)
{
	MoveComposite(position);
}

float CTriangle::GetBelongSide(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::Vector2f& position) const
{
	return ((firstPoint.x - position.x) * (secondPoint.y - firstPoint.y) - (secondPoint.x - firstPoint.x) * (firstPoint.y - position.y));
}

bool CTriangle::IsCheckSide(const sf::Vector2f& position)
{
	sf::Vector2f resultPosition = { position - m_triangle.getPosition() };

	float firstPoint = GetBelongSide(m_points[0], m_points[1], resultPosition);
	float secondPoint = GetBelongSide(m_points[1], m_points[2], resultPosition);
	float thirdPoint = GetBelongSide(m_points[2], m_points[0], resultPosition);

	if ((firstPoint >= 0 && secondPoint >= 0 && thirdPoint >= 0) || (firstPoint <= 0 && secondPoint <= 0 && thirdPoint <= 0))
	{
		return true;
	}
	return false;
}

void CTriangle::MoveComposite(const sf::Vector2f& position)
{
	sf::Vector2f result = position - m_prevPosition;
	m_prevPosition = position;
	m_triangle.move(result);
}

void CTriangle::SetOutlineThickness(const float thickness)
{
	m_triangle.setOutlineThickness(thickness);
}

void CTriangle::SetOutlineColor(sf::Color color)
{
	m_triangle.setOutlineColor(color);
}

void CTriangle::SetFillColor(sf::Color color)
{
	m_triangle.setFillColor(color);
}
