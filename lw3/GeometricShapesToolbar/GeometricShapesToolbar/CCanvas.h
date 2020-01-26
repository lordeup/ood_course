#pragma once
#include "CContextState.h"
#include "CInvoker.h"
#include "CRectangleMini.h"
#include "CShapeDecorator.h"
#include "CToolbar.h"
#include "Const.h"
#include <algorithm>

class CCanvas : public ICanvas
{
public:
	CCanvas(const unsigned int windowWidth, const unsigned int windowHeight, const std::string name, const std::vector<ShapePtr>& shapes);
	~CCanvas() = default;

	void DrawingShapes();
	void DrawCircle(sf::CircleShape circle) override;
	void DrawRectangle(sf::RectangleShape rectangle, float width, float height) override;
	void DrawTriangle(sf::ConvexShape triangle, const std::vector<sf::Vector2f>& points) override;

private:
	sf::RenderWindow m_window;

	bool m_isPressed = false;
	bool m_isGrouping = false;

	unsigned int m_windowWidth, m_windowHeight;
	std::vector<ShapePtr> m_shapes;
	std::vector<ShapePtr> m_shapeSelected;

	std::string m_windowName;

	void ToolbarDraw(CToolbar& toolbar, CInvoker& invoker);

	void EventHandler(sf::Event& event, CComposite& composite, CContextState& state);
	void Frame(const sf::Vector2f& position);
	void FrameSelected(const sf::Vector2f& position);
	void DeleteFrame(const sf::Vector2f& position);
	void MoveShape(const sf::Vector2f& position);
	bool IsFrameCheck(const sf::Vector2f& position);
};