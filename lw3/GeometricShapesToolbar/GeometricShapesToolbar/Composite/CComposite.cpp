#include "CComposite.h"

CComposite::CComposite(std::unordered_set<ShapePtr>& shapes)
	: CShapeDecorator(*new sf::RectangleShape)
	, m_shapes(shapes)
{
	m_frame.setFillColor(SILVER_COLOR);
	SetFrameSize();
	SetFramePosition();
}

void CComposite::DrawShape(sf::RenderWindow& window)
{
	for (const auto& shape : m_shapes)
	{
		shape->DrawShape(window);
	}
}

void CComposite::DrawFrame(sf::RenderWindow& window)
{
	window.draw(m_frame);
}

bool CComposite::IsCheckSide(const sf::Vector2f& position)
{
	return IsCheckSideShape(m_frame, position);
}

void CComposite::UpdatePosition(const sf::Vector2f& position)
{
	for (const auto& shape : m_shapes)
	{
		shape->UpdatePosition(position);
	}
	SetFramePosition();
}

void CComposite::UpdatingDifferentPosition(const sf::Vector2f& position)
{
	for (const auto& shape : m_shapes)
	{
		shape->UpdatingDifferentPosition(position);
	}
}

std::unordered_set<ShapePtr> CComposite::GetShapes()
{
	return m_shapes;
}

void CComposite::SetOutlineThickness(const float thickness)
{
	for (const auto& shape : m_shapes)
	{
		shape->SetOutlineThickness(thickness);
	}
}

void CComposite::SetOutlineColor(const sf::Color& color)
{
	for (const auto& shape : m_shapes)
	{
		shape->SetOutlineColor(color);
	}
}

void CComposite::SetFillColor(const sf::Color& color)
{
	for (const auto& shape : m_shapes)
	{
		shape->SetFillColor(color);
	}
}

bool ComparePositionX(const ShapePtr& a, const ShapePtr& b)
{
	return a->GetFramePosition().x < b->GetFramePosition().x;
}

bool ComparePositionY(const ShapePtr& a, const ShapePtr& b)
{
	return a->GetFramePosition().y < b->GetFramePosition().y;
}

void CComposite::SetFramePosition()
{
	auto minX = std::min_element(m_shapes.begin(), m_shapes.end(), ComparePositionX);
	auto minY = std::min_element(m_shapes.begin(), m_shapes.end(), ComparePositionY);

	m_frame.setPosition({ (*minX)->GetFramePosition().x, (*minY)->GetFramePosition().y });
}

void CComposite::SetFrameSize()
{
	auto minMaxPositionX = std::minmax_element(m_shapes.begin(), m_shapes.end(), ComparePositionX);
	auto minMaxPositionY = std::minmax_element(m_shapes.begin(), m_shapes.end(), ComparePositionY);

	auto maxSizeX = std::max_element(m_shapes.begin(), m_shapes.end(), [](const ShapePtr& a, const ShapePtr& b) { return a->GetFrameSize().x < b->GetFrameSize().x; });
	auto maxSizeY = std::max_element(m_shapes.begin(), m_shapes.end(), [](const ShapePtr& a, const ShapePtr& b) { return a->GetFrameSize().y < b->GetFrameSize().y; });

	float differenceWidth = (*minMaxPositionX.second)->GetFramePosition().x - (*minMaxPositionX.first)->GetFramePosition().x + (*maxSizeX)->GetFrameSize().x;
	float differenceHeight = (*minMaxPositionY.second)->GetFramePosition().y - (*minMaxPositionY.first)->GetFramePosition().y + (*maxSizeY)->GetFrameSize().y;

	m_frame.setSize({ differenceWidth, differenceHeight });
}
