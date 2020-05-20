#pragma once
#include "../Toolbar/CToolbar.h"

class IState
{
public:
	virtual ~IState() = default;

	virtual void MouseButtonPressedEvent(CToolbar& toolbar, std::unordered_set<ShapePtr>& shapes, ShapePtr& shapeClicked, ShapePtr& shapeSelected, const sf::Vector2f& position) = 0;
	virtual void MouseButtonReleasedEvent(std::vector<ShapePtr>& shapes, const sf::Vector2f& position) = 0;
	virtual void ShowFrame(sf::RenderWindow& window, std::unordered_set<ShapePtr>& selectedShapes, ShapePtr& shapeSelected) = 0;

	virtual void SelectingMultipleShapes(ShapePtr& shapeSelected, std::unordered_set<ShapePtr>& selectedShapes) = 0;
	virtual void MoveShape(ShapePtr& shapeSelected, const sf::Vector2f& position) = 0;
	virtual bool IsUpdateState(CToolbar& toolbar, const sf::Vector2f& position) = 0;

	virtual void GroupingShapes(std::vector<ShapePtr>& shapes, std::unordered_set<ShapePtr>& selectedShapes) = 0;
	virtual void UngroupingShapes(std::vector<ShapePtr>& shapes, ShapePtr& shapeSelected) = 0;
};