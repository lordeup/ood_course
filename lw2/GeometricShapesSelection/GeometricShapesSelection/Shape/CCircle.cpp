#include "CCircle.h"

CCircle::CCircle(sf::CircleShape& shape, const sf::Vector2f& center, const float radius)
	: CShapeDecorator(shape)
	, m_circle(shape)
{
	m_circle.setRadius(radius);
	m_circle.setFillColor(GREEN_COLOR);

	m_position = center - sf::Vector2f(GetRadius(), GetRadius());

	m_frame.setSize({ MULTIPLICATION_FACTOR * GetRadius(), MULTIPLICATION_FACTOR * GetRadius() });
	m_frame.setFillColor(SILVER_COLOR);
	SetFramePosition();
}

float CCircle::GetArea() const
{
	return float(M_PI * pow(GetRadius(), POWER_NUMBER));
}

float CCircle::GetPerimeter() const
{
	return float(M_PI * MULTIPLICATION_FACTOR * GetRadius());
}

void CCircle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_CIRCLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
}

void CCircle::DrawShape(sf::RenderWindow& window)
{
	m_circle.setPosition(m_position);
	window.draw(m_circle);
}

void CCircle::DrawFrame(sf::RenderWindow& window)
{
	window.draw(m_frame);
}

bool CCircle::IsCheckSide(const sf::Vector2f& position)
{
	return IsCheckSideShape(m_circle, position);
}

void CCircle::UpdatePosition(const sf::Vector2f& position)
{
	m_position = position - m_differentPosition;
	SetFramePosition();
}

void CCircle::UpdatingDifferentPosition(const sf::Vector2f& position)
{
	m_differentPosition = position - m_position;
}

std::unordered_set<ShapePtr> CCircle::GetShapes()
{
	return std::unordered_set<ShapePtr>();
}

float CCircle::GetRadius() const
{
	return m_circle.getRadius();
}

void CCircle::SetFramePosition()
{
	m_frame.setPosition(m_position);
}