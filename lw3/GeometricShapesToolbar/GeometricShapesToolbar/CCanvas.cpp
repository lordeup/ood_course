#include "CCanvas.h"

CCanvas::CCanvas(const unsigned int windowWidth, const unsigned int windowHeight, const std::string name, const std::vector<ShapePtr>& shapes)
	: m_windowWidth(windowWidth)
	, m_windowHeight(windowHeight)
	, m_windowName(name)
	, m_shapes(shapes)
{
}

void CCanvas::DrawingShapes()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = ANTIALIASING_LEVEL;
	m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), m_windowName, sf::Style::Default, settings);
	sf::Event event;

	CComposite composite;

	CContextState state;

	CToolbar toolbar;
	CInvoker invoker;

	while (m_window.isOpen())
	{
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}

			EventHandler(event, composite, state);
		}

		for (auto shape : m_shapes)
		{
			shape->Draw(*this);
		}

		ToolbarDraw(toolbar, invoker);

		m_window.display();
	}
}

void CCanvas::EventHandler(sf::Event& event, CComposite& composite, CContextState& state)
{
	sf::Vector2f position = (sf::Vector2f)sf::Mouse::getPosition(m_window);

	if (event.type == sf::Event::MouseButtonReleased)
	{
		m_isPressed = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_isGrouping)
	{
		state.AddShape();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			FrameSelected(position);
		}
		else if (!m_isPressed)
		{
			m_shapeSelected.empty() ? Frame(position) : DeleteFrame(position);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type == sf::Event::MouseMoved)
	{
		state.MoveShape();
		sf::Vector2i vec = { event.mouseMove.x, event.mouseMove.y };
		m_isPressed = true;

		sf::Vector2f positionMouse = (sf::Vector2f)vec;
		m_isGrouping ? composite.MoveComposite(positionMouse) : MoveShape(positionMouse);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::G) && !m_isGrouping)
	{
		state.FillShape();
		for (auto shape : m_shapeSelected)
		{
			composite.Add(shape);
		}
		m_isGrouping = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::U) && m_isGrouping)
	{
		for (auto shape : m_shapeSelected)
		{
			composite.Remove(shape);
		}

		m_isGrouping = false;
	}

	std::cout << state.ToString() << std::endl;

	m_window.clear();
}

void CCanvas::ToolbarDraw(CToolbar& toolbar, CInvoker& invoker)
{
	if (m_window.isOpen())
	{
		invoker.SetCommand(std::make_shared<CRectangleMini>(toolbar));
		//invoker.Run();

		sf::RectangleShape rectangle({ 550, 150 });
		rectangle.setPosition(0, WINDOW_HEIGHT - rectangle.getSize().y);
		m_window.draw(rectangle);

		sf::RectangleShape rectangleMini({ 50, 25 });
		rectangleMini.setPosition(5, WINDOW_HEIGHT - rectangle.getSize().y + 10);
		rectangleMini.setFillColor(BACKGROUND_COLOR_RECTANGLE);
		m_window.draw(rectangleMini);

		sf::CircleShape circleMini(20);
		circleMini.setPosition(rectangleMini.getPosition().x + 80, rectangleMini.getPosition().y);
		circleMini.setFillColor(BACKGROUND_COLOR_CIRCLE);
		m_window.draw(circleMini);

		//sf::ConvexShape triangleMini(3);
		//float size = 15;
		//triangleMini.setPoint(0, { size, size });
		//triangleMini.setPoint(1, { size, 30 });
		//triangleMini.setPoint(2, { size, size });
		//triangleMini.setPosition(500, 400);
		//triangleMini.setFillColor(BACKGROUND_COLOR_TRIANGLE);
		//m_window.draw(triangleMini);
	}
}

void CCanvas::Frame(const sf::Vector2f& position)
{
	for (auto shape : m_shapes)
	{
		if (shape->IsCheckSide(position))
		{
			shape->DrawFrame(*this);
			m_shapeSelected.push_back(shape);
		}
	}
}

bool CCanvas::IsFrameCheck(const sf::Vector2f& position)
{
	for (size_t i = 0; i < m_shapeSelected.size(); ++i)
	{
		if (m_shapeSelected[i]->IsCheckSide(position))
		{
			m_shapeSelected[i]->DeleteFrame(*this);
			m_shapeSelected.erase(m_shapeSelected.begin() + i);
			return false;
		}
	}

	return true;
}

void CCanvas::FrameSelected(const sf::Vector2f& position)
{
	for (auto shape : m_shapes)
	{
		if (shape->IsCheckSide(position) && IsFrameCheck(position))
		{
			shape->DrawFrame(*this);
			m_shapeSelected.push_back(shape);
		}
	}
}

void CCanvas::DeleteFrame(const sf::Vector2f& position)
{
	for (auto shape : m_shapeSelected)
	{
		if (!shape->IsCheckSide(position))
		{
			shape->DeleteFrame(*this);
			m_shapeSelected.clear();
		}
	}
}

void CCanvas::MoveShape(const sf::Vector2f& position)
{
	for (auto shape : m_shapeSelected)
	{
		shape->Move(*this, position);
	}
}

void CCanvas::DrawCircle(sf::CircleShape circle)
{
	if (m_window.isOpen())
	{
		circle.setFillColor(BACKGROUND_COLOR_CIRCLE);
		m_window.draw(circle);
	}
}

void CCanvas::DrawRectangle(sf::RectangleShape rectangle, float width, float height)
{
	if (m_window.isOpen())
	{
		rectangle.setSize({ width, height });
		rectangle.setFillColor(BACKGROUND_COLOR_RECTANGLE);
		m_window.draw(rectangle);
	}
}

void CCanvas::DrawTriangle(sf::ConvexShape triangle, const std::vector<sf::Vector2f>& points)
{
	if (m_window.isOpen())
	{
		triangle.setFillColor(BACKGROUND_COLOR_TRIANGLE);

		for (size_t i = 0; i < points.size(); ++i)
		{
			triangle.setPoint(i, { points[i].x, points[i].y });
		}

		m_window.draw(triangle);
	}
}