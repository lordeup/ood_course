#include "CCircle.h"

CCircle::CCircle(sf::CircleShape& shape, const sf::Vector2f& center)
	: CShapeDecorator(shape)
	, m_center(center)
	, m_circle(shape)
{
	m_prevPosition = { 0.f, 0.f };
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

void CCircle::Draw(ICanvas& canvas)
{
	canvas.DrawCircle(m_circle);
}

void CCircle::DrawFrame(ICanvas& canvas)
{
	SetOutlineThickness(OUTLINE_THICKNESS);
	SetOutlineColor(BACKGROUND_COLOR_DRAW);
}

void CCircle::DeleteFrame(ICanvas& canvas)
{
	SetOutlineColor(BACKGROUND_COLOR_CIRCLE);
}

void CCircle::Move(ICanvas& canvas, const sf::Vector2f& position)
{
	MoveComposite(position);
}

bool CCircle::IsCheckSide(const sf::Vector2f& position)
{
	sf::Vector2f resultPosition = { position - m_circle.getPosition() };

	if (sqrt(pow(resultPosition.x - m_circle.getRadius(), POWER_NUMBER) + pow(resultPosition.y - m_circle.getRadius(), POWER_NUMBER)) <= m_circle.getRadius())
	{
		return true;
	}

	return false;
}

void CCircle::MoveComposite(const sf::Vector2f& position)
{
	sf::Vector2f result = position - m_prevPosition;
	m_prevPosition = position;
	m_circle.move(result);
}

void CCircle::SetOutlineThickness(const float thickness)
{
	m_circle.setOutlineThickness(thickness);
}

void CCircle::SetOutlineColor(sf::Color color)
{
	m_circle.setOutlineColor(color);
}

void CCircle::SetFillColor(sf::Color color)
{
	m_circle.setFillColor(color);
}
