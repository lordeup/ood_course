#include "CAddState.h"

CAddState::CAddState(CStateContext* context)
	: m_context(context)
{
	m_isCircleShape = false;
	m_isTriangleShape = false;
	m_isRectangleShape = false;
}

void CAddState::MouseButtonReleasedEvent(std::vector<ShapePtr>& shapes, const sf::Vector2f& position)
{
	ShapePtr shape = nullptr;

	if (m_isCircleShape)
	{
		sf::CircleShape circle;
		shape = std::make_shared<CCircle>(circle, position);
	}
	else if (m_isRectangleShape)
	{
		sf::RectangleShape rectangle;
		shape = std::make_shared<CRectangle>(rectangle, position);
	}
	else if (m_isTriangleShape)
	{
		sf::ConvexShape triangle;
		shape = std::make_shared<CTriangle>(triangle, position);
	}

	if (shape)
	{
		shapes.push_back(shape);
	}
}

bool CAddState::IsUpdateState(CToolbar& toolbar, const sf::Vector2f& position)
{
	if (IsCheckSideSprite(toolbar.GetDragSprite(), position))
	{
		m_context->SetState(std::make_shared<CDragState>(m_context));
		return true;
	}

	if (IsCheckSideSprite(toolbar.GetFillSprite(), position))
	{
		m_context->SetState(std::make_shared<CFillState>(m_context));
		return true;
	}

	if (IsCheckSideSprite(toolbar.GetCircleSprite(), position))
	{
		m_isCircleShape = true;
		m_isTriangleShape = false;
		m_isRectangleShape = false;
		return true;
	}

	if (IsCheckSideSprite(toolbar.GetTriangleSprite(), position))
	{
		m_isCircleShape = false;
		m_isTriangleShape = true;
		m_isRectangleShape = false;
		return true;
	}

	if (IsCheckSideSprite(toolbar.GetRectangleSprite(), position))
	{
		m_isCircleShape = false;
		m_isTriangleShape = false;
		m_isRectangleShape = true;
		return true;
	}

	return false;
}
