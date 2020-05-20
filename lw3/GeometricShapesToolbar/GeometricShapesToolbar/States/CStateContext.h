#pragma once
#include "IState.h"

class CStateContext
{
public:
	CStateContext();
	void SetState(const std::shared_ptr<IState>& state);

	void MouseButtonPressedEvent(CToolbar& toolbar, std::unordered_set<ShapePtr>& shapes, ShapePtr& shapeClicked, ShapePtr& shapeSelected, const sf::Vector2f& position);
	void MouseButtonReleasedEvent(std::vector<ShapePtr>& shapes, const sf::Vector2f& position);
	void ShowFrame(sf::RenderWindow& window, std::unordered_set<ShapePtr>& selectedShapes, ShapePtr& shapeSelected);

	void SelectingMultipleShapes(ShapePtr& shapeSelected, std::unordered_set<ShapePtr>& selectedShapes);
	void MoveShape(ShapePtr& shapeSelected, const sf::Vector2f& position);
	bool IsUpdateState(CToolbar& toolbar, const sf::Vector2f& position);

	void GroupingShapes(std::vector<ShapePtr>& shapes, std::unordered_set<ShapePtr>& selectedShapes);
	void UngroupingShapes(std::vector<ShapePtr>& shapes, ShapePtr& shapeSelected);

private:
	std::shared_ptr<IState> m_state;
};