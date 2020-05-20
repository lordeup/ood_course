#include "CFillState.h"

CFillState::CFillState(CStateContext* context)
	: m_context(context)
{
}

void CFillState::MouseButtonPressedEvent(CToolbar& toolbar, std::unordered_set<ShapePtr>& shapes, ShapePtr& shapeClicked, ShapePtr& shapeSelected, const sf::Vector2f& position)
{
	if (!shapeSelected || !toolbar.IsSelectedCommandFill(shapeSelected, position))
	{
		shapeSelected = shapeClicked;
	}
}

void CFillState::ShowFrame(sf::RenderWindow& window, std::unordered_set<ShapePtr>& selectedShapes, ShapePtr& shapeSelected)
{
	if (shapeSelected)
	{
		shapeSelected->DrawFrame(window);
	}
}

bool CFillState::IsUpdateState(CToolbar& toolbar, const sf::Vector2f& position)
{
	if (IsCheckSideSprite(toolbar.GetDragSprite(), position))
	{
		m_context->SetState(std::make_shared<CDragState>(m_context));
		return true;
	}

	if (IsCheckSideSprite(toolbar.GetAddSprite(), position))
	{
		m_context->SetState(std::make_shared<CAddState>(m_context));
		return true;
	}

	return false;
}
