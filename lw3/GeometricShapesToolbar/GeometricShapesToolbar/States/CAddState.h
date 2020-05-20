#pragma once
#include "../Shape/CCircle.h"
#include "../Shape/CRectangle.h"
#include "../Shape/CTriangle.h"
#include "CDragState.h"
#include "CStateContext.h"

class CAddState : public IState
{
public:
	CAddState(CStateContext* context);

	void MouseButtonPressedEvent(CToolbar& toolbar, std::unordered_set<ShapePtr>& shapes, ShapePtr& shapeClicked, ShapePtr& shapeSelected, const sf::Vector2f& position) override{};
	void MouseButtonReleasedEvent(std::vector<ShapePtr>& shapes, const sf::Vector2f& position) override;
	void ShowFrame(sf::RenderWindow& window, std::unordered_set<ShapePtr>& selectedShapes, ShapePtr& shapeSelected) override{};

	void SelectingMultipleShapes(ShapePtr& shapeSelected, std::unordered_set<ShapePtr>& selectedShapes) override{};
	void MoveShape(ShapePtr& shapeSelected, const sf::Vector2f& position) override{};
	bool IsUpdateState(CToolbar& toolbar, const sf::Vector2f& position) override;

	void GroupingShapes(std::vector<ShapePtr>& shapes, std::unordered_set<ShapePtr>& selectedShapes) override{};
	void UngroupingShapes(std::vector<ShapePtr>& shapes, ShapePtr& shapeSelected) override{};

private:
	CStateContext* m_context;

	bool m_isCircleShape, m_isTriangleShape, m_isRectangleShape;
};