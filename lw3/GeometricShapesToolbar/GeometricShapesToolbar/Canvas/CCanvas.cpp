#include "CCanvas.h"

CCanvas::CCanvas(const unsigned int windowWidth, const unsigned int windowHeight, const std::string name, std::vector<ShapePtr>& shapes)
	: m_windowWidth(windowWidth)
	, m_windowHeight(windowHeight)
	, m_windowName(name)
	, m_shapes(shapes)
{
	m_shapeClicked = nullptr;
	m_shapeSelected = nullptr;
}

void CCanvas::DrawingShapes()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = ANTIALIASING_LEVEL;
	m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), m_windowName, sf::Style::Default, settings);
	m_window.setKeyRepeatEnabled(false);
	sf::Event event;

	CToolbar toolbar(m_window);
	CStateContext stateContext;

	while (m_window.isOpen())
	{
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}

			EventHandler(event, toolbar, stateContext);
		}

		m_window.clear();

		toolbar.Draw();

		for (auto& shape : m_shapes)
		{
			shape->DrawShape(m_window);
		}

		stateContext.ShowFrame(m_window, m_selectedShapes, m_shapeSelected);

		m_window.display();
	}
}

void CCanvas::EventHandler(sf::Event& event, CToolbar& toolbar, CStateContext& stateContext)
{
	sf::Vector2f position = (sf::Vector2f)sf::Mouse::getPosition(m_window);

	bool isKeyReleased = event.type == sf::Event::KeyReleased;
	bool isKeyG = event.key.code == sf::Keyboard::G;
	bool isKeyU = event.key.code == sf::Keyboard::U;
	bool isKeyShift = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
	bool isKeyControl = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);

	bool isKeyLeft = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	bool iMouseMoveds = event.type == sf::Event::MouseMoved;

	bool isMouseButtonPressed = event.type == sf::Event::MouseButtonPressed;
	bool isMouseButtonReleased = event.type == sf::Event::MouseButtonReleased;

	if (isMouseButtonPressed)
	{
		m_shapeClicked = GetSelectedShape(position);
		stateContext.MouseButtonPressedEvent(toolbar, m_selectedShapes, m_shapeClicked, m_shapeSelected, position);
	}

	if (isMouseButtonReleased && !stateContext.IsUpdateState(toolbar, position))
	{
		stateContext.MouseButtonReleasedEvent(m_shapes, position);
	}

	if (iMouseMoveds && isKeyLeft)
	{
		stateContext.MoveShape(m_shapeSelected, position);
	}

	if (isKeyShift && isMouseButtonReleased)
	{
		stateContext.SelectingMultipleShapes(m_shapeSelected, m_selectedShapes);
	}

	if (isKeyControl && isKeyReleased && isKeyG)
	{
		stateContext.GroupingShapes(m_shapes, m_selectedShapes);
	}

	if (isKeyControl && isKeyReleased && isKeyU)
	{
		stateContext.UngroupingShapes(m_shapes, m_shapeSelected);
	}
}

ShapePtr CCanvas::GetSelectedShape(const sf::Vector2f& position)
{
	auto it = std::find_if(m_shapes.begin(), m_shapes.end(), [&](const ShapePtr& ptr) { return ptr->IsCheckSide(position); });

	if (it != m_shapes.end())
	{
		return *it;
	}

	return nullptr;
}