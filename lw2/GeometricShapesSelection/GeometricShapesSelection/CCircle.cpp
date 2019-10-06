#include "CCircle.h"

CCircle::CCircle(sf::CircleShape& shape, const CPoint& center)
	: CShapeDecorator(shape)
	, m_center(center)
{
	m_circle = shape;
}

float CCircle::GetArea() const
{
	return float(M_PI * m_circle.getRadius() * m_circle.getRadius());
}

float CCircle::GetPerimeter() const
{
	return float(M_PI * MULTIPLICATION_FACTOR * m_circle.getRadius());
}

void CCircle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_CIRCLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
}

void CCircle::Draw(ICanvas& canvas) const
{
	canvas.DrawCircle(m_circle, m_center);
}