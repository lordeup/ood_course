#include "CRectangle.h"

CRectangle::CRectangle(sf::RectangleShape& shape, const sf::Vector2f& leftTop, const sf::Vector2f& rightBottom)
	: CShapeDecorator(shape)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
	, m_rectangle(shape)
{
	m_leftTopDraw = { GetWidth() / MULTIPLICATION_FACTOR, GetHeight() / MULTIPLICATION_FACTOR };
	m_prevPosition = { 0.f, 0.f };
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
	return std::abs(m_leftTop.x - m_rightBottom.x);
}

float CRectangle::GetHeight() const
{
	return std::abs(m_leftTop.y - m_rightBottom.y);
}

void CRectangle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_RECTANGLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
}

void CRectangle::Draw(ICanvas& canvas)
{
	canvas.DrawRectangle(m_rectangle, GetWidth(), GetHeight());
}

void CRectangle::DrawFrame(ICanvas& canvas)
{
	SetOutlineThickness(OUTLINE_THICKNESS);
	SetOutlineColor(BACKGROUND_COLOR_DRAW);
}

void CRectangle::DeleteFrame(ICanvas& canvas)
{
	SetOutlineColor(BACKGROUND_COLOR_RECTANGLE);
}

void CRectangle::Move(ICanvas& canvas, const sf::Vector2f& position)
{
	MoveComposite(position);
}

bool CRectangle::IsCheckSide(const sf::Vector2f& position)
{
	sf::Vector2f rightBottom = { GetWidth() + m_rectangle.getPosition().x, GetHeight() + m_rectangle.getPosition().y };

	if (position.x >= m_rectangle.getPosition().x && position.x <= rightBottom.x && position.y >= m_rectangle.getPosition().y && position.y <= rightBottom.y)
	{
		return true;
	}

	return false;
}

void CRectangle::MoveComposite(const sf::Vector2f& position)
{
	sf::Vector2f result = position - m_prevPosition;
	m_prevPosition = position;
	m_rectangle.move(result);
}

void CRectangle::SetOutlineThickness(const float thickness)
{
	m_rectangle.setOutlineThickness(thickness);
}

void CRectangle::SetOutlineColor(sf::Color color)
{
	m_rectangle.setOutlineColor(color);
}

void CRectangle::SetFillColor(sf::Color color)
{
	m_rectangle.setFillColor(color);
}
