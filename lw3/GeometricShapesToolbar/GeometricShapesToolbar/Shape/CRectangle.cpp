#include "CRectangle.h"

CRectangle::CRectangle(sf::RectangleShape& shape, const sf::Vector2f& position)
	: CShapeDecorator(shape)
	, m_rectangle(shape)
{
	m_leftTop = { position.x - MULTIPLICATION_FACTOR * GetDifferenceShape(), position.y - GetDifferenceShape() };
	m_rightBottom = { position.x + MULTIPLICATION_FACTOR * GetDifferenceShape(), position.y + GetDifferenceShape() };

	Initialization(position);
}

CRectangle::CRectangle(sf::RectangleShape& shape, const sf::Vector2f& leftTop, const sf::Vector2f& rightBottom)
	: CShapeDecorator(shape)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
	, m_rectangle(shape)
{

	Initialization(GetSize());
}

void CRectangle::Initialization(const sf::Vector2f& position)
{
	m_rectangle.setSize(GetSize());
	SetFillColor(RED_COLOR);

	m_position = position - sf::Vector2f(GetSize().x / MULTIPLICATION_FACTOR, GetSize().y / MULTIPLICATION_FACTOR);

	m_frame.setFillColor(SILVER_COLOR);
	m_frame.setSize({ GetSize().x + MULTIPLICATION_FACTOR * GetDifferenceFrame(), GetSize().y + MULTIPLICATION_FACTOR * GetDifferenceFrame() });
	SetFramePosition();
}

float CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

float CRectangle::GetPerimeter() const
{
	return (GetWidth() + GetHeight()) * MULTIPLICATION_FACTOR;
}

void CRectangle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_RECTANGLE << COLON << PERIMETER_SHAPE << GetPerimeter() << SEMICOLON << AREA_SHAPE << GetArea() << std::endl;
}

void CRectangle::DrawShape(sf::RenderWindow& window)
{
	m_rectangle.setPosition(m_position);
	window.draw(m_rectangle);
}

void CRectangle::DrawFrame(sf::RenderWindow& window)
{
	window.draw(m_frame);
}

bool CRectangle::IsCheckSide(const sf::Vector2f& position)
{
	return IsCheckSideShape(m_rectangle, position);
}

void CRectangle::UpdatePosition(const sf::Vector2f& position)
{
	m_position = position - m_differentPosition;
	SetFramePosition();
}

void CRectangle::UpdatingDifferentPosition(const sf::Vector2f& position)
{
	m_differentPosition = position - m_position;
}

std::unordered_set<ShapePtr> CRectangle::GetShapes()
{
	return std::unordered_set<ShapePtr>();
}

void CRectangle::SetOutlineThickness(const float thickness)
{
	m_rectangle.setOutlineThickness(thickness);
}

void CRectangle::SetOutlineColor(const sf::Color& color)
{
	m_rectangle.setOutlineColor(color);
}

void CRectangle::SetFillColor(const sf::Color& color)
{
	m_rectangle.setFillColor(color);
}

float CRectangle::GetWidth() const
{
	return std::abs(m_leftTop.x - m_rightBottom.x);
}

float CRectangle::GetHeight() const
{
	return std::abs(m_leftTop.y - m_rightBottom.y);
}

sf::Vector2f CRectangle::GetSize() const
{
	return sf::Vector2f(GetWidth(), GetHeight());
}

void CRectangle::SetFramePosition()
{
	m_frame.setPosition({ m_position.x - GetDifferenceFrame(), m_position.y - GetDifferenceFrame() });
}

float CRectangle::GetDifferenceFrame() const
{
	return 10.f;
}

float CRectangle::GetDifferenceShape() const
{
	return 50.f;
}
