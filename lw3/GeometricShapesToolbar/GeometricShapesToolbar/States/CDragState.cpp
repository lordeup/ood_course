#include "CDragState.h"

CDragState::CDragState(CStateContext* context)
	: m_context(context)
{
}

void CDragState::MouseButtonPressedEvent(CToolbar& toolbar, std::unordered_set<ShapePtr>& shapes, ShapePtr& shapeClicked, ShapePtr& shapeSelected, const sf::Vector2f& position)
{
	if (!shapeClicked && !shapes.empty())
	{
		shapes.clear();
	}

	if (!shapeSelected || !toolbar.IsSelectedCommandOutline(shapeSelected, position))
	{
		shapeSelected = shapeClicked;
	}

	if (shapeSelected)
	{
		shapeSelected->UpdatingDifferentPosition(position);
	}
}

void CDragState::ShowFrame(sf::RenderWindow& window, std::unordered_set<ShapePtr>& selectedShapes, ShapePtr& shapeSelected)
{
	if (!selectedShapes.empty())
	{
		for (const auto& shape : selectedShapes)
		{
			shape->DrawFrame(window);
		}
	}
	else if (shapeSelected)
	{
		shapeSelected->DrawFrame(window);
	}
}

void CDragState::SelectingMultipleShapes(ShapePtr& shapeSelected, std::unordered_set<ShapePtr>& selectedShapes)
{
	if (shapeSelected)
	{
		selectedShapes.insert(shapeSelected);
		shapeSelected = nullptr;
	}
}

void CDragState::MoveShape(ShapePtr& shapeSelected, const sf::Vector2f& position)
{
	if (shapeSelected)
	{
		shapeSelected->UpdatePosition(position);
	}
}

bool CDragState::IsUpdateState(CToolbar& toolbar, const sf::Vector2f& position)
{
	if (IsCheckSideSprite(toolbar.GetFillSprite(), position))
	{
		m_context->SetState(std::make_shared<CFillState>(m_context));
		return true;
	}

	if (IsCheckSideSprite(toolbar.GetAddSprite(), position))
	{
		m_context->SetState(std::make_shared<CAddState>(m_context));
		return true;
	}

	return false;
}

void CDragState::GroupingShapes(std::vector<ShapePtr>& shapes, std::unordered_set<ShapePtr>& selectedShapes)
{
	if (!selectedShapes.empty())
	{
		shapes.push_back(std::make_shared<CComposite>(selectedShapes));

		for (auto& shapeGroup : selectedShapes)
		{
			auto it = std::find_if(shapes.begin(), shapes.end(), [&](const ShapePtr& ptr) { return ptr == shapeGroup; });

			if (it != shapes.end())
			{
				shapes.erase(it);
			}
		}
		selectedShapes.clear();
	}
}

void CDragState::UngroupingShapes(std::vector<ShapePtr>& shapes, ShapePtr& shapeSelected)
{
	for (auto& shape : shapes)
	{
		auto it = std::find_if(shapes.begin(), shapes.end(), [&](const ShapePtr& ptr) { return ptr == shapeSelected; });

		if (it != shapes.end())
		{
			auto groupShapes = shape->GetShapes();

			if (!groupShapes.empty())
			{
				std::for_each(groupShapes.begin(), groupShapes.end(), [&](const ShapePtr& ptr) { shapes.push_back(ptr); });
				shapes.erase(it);
			}
		}
	}

	shapeSelected = nullptr;
}
