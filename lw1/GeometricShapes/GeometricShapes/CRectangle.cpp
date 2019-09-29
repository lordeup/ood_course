#include "CRectangle.h"

CRectangle::CRectangle(sf::RectangleShape& shape, const CPoint& leftTop, const CPoint& rightBottom)
	: CShapeDecorator(shape)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
	m_rectangle = shape;
}

float CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

float CRectangle::GetPerimeter() const
{
	return (GetWidth() + GetHeight()) * MULTIPLICATION_FACTOR;
}

float CRectangle::GetWidth() const
{
	return std::abs(m_leftTop.GetX() - m_rightBottom.GetX());
}

float CRectangle::GetHeight() const
{
	return std::abs(m_leftTop.GetY() - m_rightBottom.GetY());
}

void CRectangle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_RECTANGLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
}

void CRectangle::Draw(ICanvas& canvas) const
{
	canvas.DrawRectangle(m_rectangle, GetWidth(), GetHeight());
}