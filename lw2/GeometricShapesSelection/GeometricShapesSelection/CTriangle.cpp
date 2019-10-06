#include "CTriangle.h"

CTriangle::CTriangle(sf::ConvexShape& shape, const std::vector<CPoint>& points)
	: CShapeDecorator(shape)
	, m_points(points)
{
	m_triangle = shape;
}

float CTriangle::GetSideCounting(const CPoint& firstPodouble, const CPoint& secondPodouble) const
{
	return sqrt(pow(secondPodouble.GetX() - firstPodouble.GetX(), POWER_NUMBER) + pow(secondPodouble.GetY() - firstPodouble.GetY(), POWER_NUMBER));
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

void CTriangle::Draw(ICanvas& canvas) const
{
	canvas.DrawTriangle(m_triangle, m_points);
}
