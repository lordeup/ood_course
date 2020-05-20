#pragma once
#include "../Const.h"
#include "../Decorator/CShapeDecorator.h"
#include "../States/CStateContext.h"
#include "../Toolbar/CToolbar.h"

class CCanvas
{
public:
	CCanvas(const unsigned int windowWidth, const unsigned int windowHeight, const std::string name, std::vector<ShapePtr>& shapes);

	void DrawingShapes();

private:
	sf::RenderWindow m_window;
	std::string m_windowName;
	unsigned int m_windowWidth, m_windowHeight;

	ShapePtr m_shapeClicked, m_shapeSelected;

	std::unordered_set<ShapePtr> m_selectedShapes;
	std::vector<ShapePtr>& m_shapes;

	void EventHandler(sf::Event& event, CToolbar& toolbar, CStateContext& stateContext);

	ShapePtr GetSelectedShape(const sf::Vector2f& position);
};