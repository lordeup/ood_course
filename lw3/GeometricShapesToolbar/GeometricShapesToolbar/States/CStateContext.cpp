#include "CStateContext.h"
#include "CDragState.h"

CStateContext::CStateContext()
{
	m_state = std::make_shared<CDragState>(this);
}

void CStateContext::SetState(const std::shared_ptr<IState>& state)
{
	m_state = state;
}

void CStateContext::MouseButtonPressedEvent(CToolbar& toolbar, std::unordered_set<ShapePtr>& shapes, ShapePtr& shapeClicked, ShapePtr& shapeSelected, const sf::Vector2f& position)
{
	m_state->MouseButtonPressedEvent(toolbar, shapes, shapeClicked, shapeSelected, position);
}

void CStateContext::MouseButtonReleasedEvent(std::vector<ShapePtr>& shapes, const sf::Vector2f& position)
{
	m_state->MouseButtonReleasedEvent(shapes, position);
}

void CStateContext::ShowFrame(sf::RenderWindow& window, std::unordered_set<ShapePtr>& selectedShapes, ShapePtr& shapeSelected)
{
	m_state->ShowFrame(window, selectedShapes, shapeSelected);
}

void CStateContext::SelectingMultipleShapes(ShapePtr& shapeSelected, std::unordered_set<ShapePtr>& selectedShapes)
{
	m_state->SelectingMultipleShapes(shapeSelected, selectedShapes);
}

void CStateContext::MoveShape(ShapePtr& shapeSelected, const sf::Vector2f& position)
{
	m_state->MoveShape(shapeSelected, position);
}

bool CStateContext::IsUpdateState(CToolbar& toolbar, const sf::Vector2f& position)
{
	return m_state->IsUpdateState(toolbar, position);
}

void CStateContext::GroupingShapes(std::vector<ShapePtr>& shapes, std::unordered_set<ShapePtr>& selectedShapes)
{
	m_state->GroupingShapes(shapes, selectedShapes);
}

void CStateContext::UngroupingShapes(std::vector<ShapePtr>& shapes, ShapePtr& shapeSelected)
{
	m_state->UngroupingShapes(shapes, shapeSelected);
}
