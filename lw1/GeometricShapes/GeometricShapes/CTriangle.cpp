#include "CTriangle.h"

CTriangle::CTriangle(CPoint& vertex1, CPoint& vertex2, CPoint& vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

float CTriangle::GetSideCounting(const CPoint& firstPodouble, const CPoint& secondPodouble) const
{
	return sqrt(pow(secondPodouble.GetX() - firstPodouble.GetX(), POWER_NUMBER) + pow(secondPodouble.GetY() - firstPodouble.GetY(), POWER_NUMBER));
}

void CTriangle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_TRIANGLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
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

void CTriangle::Draw(ICanvas& canvas) const
{
	std::vector<CPoint> points = { m_vertex1, m_vertex2, m_vertex3 };
	canvas.DrawTriangle(points);
}
