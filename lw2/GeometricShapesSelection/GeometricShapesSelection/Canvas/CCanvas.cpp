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

	while (m_window.isOpen())
	{
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}

			EventHandler(event);
		}

		m_window.clear();

		for (auto& shape : m_shapes)
		{
			shape->DrawShape(m_window);
		}

		ShowFrame();

		m_window.display();
	}
}

void CCanvas::EventHandler(sf::Event& event)
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

		if (!m_shapeClicked && !m_selectedShapes.empty())
		{
			m_selectedShapes.clear();
		}

		m_shapeSelected = m_shapeClicked;

		if (m_shapeSelected)
		{
			m_shapeSelected->UpdatingDifferentPosition(position);
		}
	}

	if (iMouseMoveds && isKeyLeft && m_shapeSelected)
	{
		m_shapeSelected->UpdatePosition(position);
	}

	if (isKeyShift && isMouseButtonReleased && m_shapeSelected)
	{
		m_selectedShapes.insert(m_shapeSelected);
		m_shapeSelected = nullptr;
	}

	if (isKeyControl && isKeyReleased && isKeyG)
	{
		GroupingShapes(m_shapes, m_selectedShapes);
	}

	if (isKeyControl && isKeyReleased && isKeyU)
	{
		UngroupingShapes(m_shapes, m_shapeSelected);
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

void CCanvas::ShowFrame()
{
	if (!m_selectedShapes.empty())
	{
		for (const auto& shape : m_selectedShapes)
		{
			shape->DrawFrame(m_window);
		}
	}
	else if (m_shapeSelected)
	{
		m_shapeSelected->DrawFrame(m_window);
	}
}

void CCanvas::GroupingShapes(std::vector<ShapePtr>& shapes, std::unordered_set<ShapePtr>& selectedShapes)
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

void CCanvas::UngroupingShapes(std::vector<ShapePtr>& shapes, ShapePtr& shapeSelected)
{
	for (auto& shape : shapes)
	{
		auto it = std::find_if(shapes.begin(), shapes.end(), [&](const ShapePtr& ptr) { return ptr == shapeSelected; });

		if (it != shapes.end())
		{
			auto groupShapes = (*it)->GetShapes();

			if (!groupShapes.empty())
			{
				std::for_each(groupShapes.begin(), groupShapes.end(), [&](const ShapePtr& ptr) { shapes.push_back(ptr); });
				shapes.erase(it);
			}
		}
	}

	shapeSelected = nullptr;
}
