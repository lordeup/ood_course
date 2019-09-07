#include "CCircle.h"

CCircle::CCircle(CPoint& center, const float radius)
	: m_center(center)
	, m_radius(radius)
{
}

float CCircle::GetArea() const
{
	return float(M_PI * m_radius * m_radius);
}

float CCircle::GetPerimeter() const
{
	return float(M_PI * MULTIPLICATION_FACTOR * m_radius);
}

void CCircle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_CIRCLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
}

void CCircle::Draw(ICanvas& canvas) const
{
	canvas.DrawCircle(m_center, m_radius);
}