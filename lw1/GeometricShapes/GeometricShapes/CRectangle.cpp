#include "CRectangle.h"

CRectangle::CRectangle(CPoint& leftTop, const float width, const float height)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
}

void CRectangle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_RECTANGLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
}

float CRectangle::GetArea() const
{
	return m_width * m_height;
}

float CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * MULTIPLICATION_FACTOR;
}

CPoint CRectangle::GetRightBottom() const
{
	return CPoint(m_leftTop.GetX() + m_width, m_leftTop.GetY() + m_height);
}

void CRectangle::Draw(ICanvas& canvas) const
{
	canvas.DrawRectangle(m_leftTop, m_width, m_height);
}
