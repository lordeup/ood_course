#include "CTriangle.h"

CTriangle::CTriangle(sf::ConvexShape shape, CPoint& vertex1, CPoint& vertex2, CPoint& vertex3)
	: CShapeDecorator(shape)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
	m_triangle = shape;
}

float CTriangle::GetSideCounting(const CPoint& firstPodouble, const CPoint& secondPodouble) const
{
	return sqrt(pow(secondPodouble.GetX() - firstPodouble.GetX(), POWER_NUMBER) + pow(secondPodouble.GetY() - firstPodouble.GetY(), POWER_NUMBER));
}

float CTriangle::GetPerimeter() const
{
	float side1 = GetSideCounting(m_vertex1, m_vertex2);
	float side2 = GetSideCounting(m_vertex2, m_vertex3);
	float side3 = GetSideCounting(m_vertex1, m_vertex3);

	return side1 + side2 + side3;
}

float CTriangle::GetArea() const
{
	float side1 = GetSideCounting(m_vertex1, m_vertex2);
	float side2 = GetSideCounting(m_vertex2, m_vertex3);
	float side3 = GetSideCounting(m_vertex1, m_vertex3);

	float semiPerimeter = (side1 + side2 + side3) / MULTIPLICATION_FACTOR;
	return sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
}

void CTriangle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_TRIANGLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
}

void CTriangle::Draw(ICanvas& canvas) const
{
	std::vector<CPoint> points = { m_vertex1, m_vertex2, m_vertex3 };
	canvas.DrawTriangle(m_triangle, points);
}
