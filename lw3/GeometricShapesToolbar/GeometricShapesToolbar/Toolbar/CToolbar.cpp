#include "CToolbar.h"

CToolbar::CToolbar(sf::RenderWindow& window)
	: m_window(window)
{
	m_invoker = std::make_shared<CInvoker>();
}

void CToolbar::WindowDraw(const sf::Drawable& drawable)
{
	m_window.draw(drawable);
}

void CToolbar::Draw()
{
	m_frame.setSize({ (float)m_window.getSize().x, GetFrameHeight() });
	m_frame.setFillColor(GRAY_COLOR);
	WindowDraw(m_frame);

	m_addSprite = GetSprite(GetSpritePackageName() + "add.png", 10.f);
	m_circleSprite = GetSprite(GetSpritePackageName() + "circle.png", 60.f);
	m_triangleSprite = GetSprite(GetSpritePackageName() + "triangle.png", 90.f);
	m_rectangleSprite = GetSprite(GetSpritePackageName() + "rectangle.png", 120.f);

	m_dragSprite = GetSprite(GetSpritePackageName() + "drag.png", 270.f);

	m_fillSprite = GetSprite(GetSpritePackageName() + "fill.png", 400.f);
	DrawColoredRectangle(m_fillGreen, GREEN_COLOR, 440.f);
	DrawColoredRectangle(m_fillRed, RED_COLOR, 470.f);
	DrawColoredRectangle(m_fillYellow, YELLOW_COLOR, 500.f);

	m_outline1Sprite = GetSprite(GetSpritePackageName() + "outline1.png", 700.f);
	m_outline2Sprite = GetSprite(GetSpritePackageName() + "outline2.png", 730.f);
	DrawColoredRectangle(m_outlineBlue, BLUE_COLOR, 770.f);
	DrawColoredRectangle(m_outlineCyan, CYAN_COLOR, 800.f);
	DrawColoredRectangle(m_outlineMagenta, MAGENTA_COLOR, 830.f);
}

bool CToolbar::IsSelectedCommandOutline(ShapePtr& shape, const sf::Vector2f& position)
{
	if (IsCheckSideSprite(m_outline1Sprite, position))
	{
		m_invoker->SetCommand(std::make_shared<COutlineThicknessOneCommand>(shape));
	}
	else if (IsCheckSideSprite(m_outline2Sprite, position))
	{
		m_invoker->SetCommand(std::make_shared<COutlineThicknessTwoCommand>(shape));
	}
	else if (IsCheckSideShape(m_outlineBlue, position))
	{
		m_invoker->SetCommand(std::make_shared<COutlineColorBlueCommand>(shape));
	}
	else if (IsCheckSideShape(m_outlineCyan, position))
	{
		m_invoker->SetCommand(std::make_shared<COutlineColorCyanCommand>(shape));
	}
	else if (IsCheckSideShape(m_outlineMagenta, position))
	{
		m_invoker->SetCommand(std::make_shared<COutlineColorMagentaCommand>(shape));
	}
	else
	{
		return false;
	}

	m_invoker->ExecuteCommand();
	return true;
}

bool CToolbar::IsSelectedCommandFill(ShapePtr& shape, const sf::Vector2f& position)
{
	if (IsCheckSideShape(m_fillGreen, position))
	{
		m_invoker->SetCommand(std::make_shared<CFillGreenCommand>(shape));
	}
	else if (IsCheckSideShape(m_fillRed, position))
	{
		m_invoker->SetCommand(std::make_shared<CFillRedCommand>(shape));
	}
	else if (IsCheckSideShape(m_fillYellow, position))
	{
		m_invoker->SetCommand(std::make_shared<CFillYellowCommand>(shape));
	}
	else
	{
		return false;
	}

	m_invoker->ExecuteCommand();
	return true;
}

sf::Sprite CToolbar::GetSprite(const std::string filename, const float positionX)
{
	sf::Texture texture;
	if (!texture.loadFromFile(filename))
	{
		throw std::exception("Error opening file");
	}

	sf::Sprite sprite(texture);
	sprite.setPosition(positionX, GetSpritePositionY());
	WindowDraw(sprite);

	return sprite;
}

void CToolbar::DrawColoredRectangle(sf::RectangleShape& rectangle, const sf::Color& color, const float positionX)
{
	rectangle.setFillColor(color);
	rectangle.setPosition(positionX, GetMiniRectanglePositionY());
	rectangle.setSize(GetMiniRectangleSize());
	WindowDraw(rectangle);
}

sf::Sprite CToolbar::GetTriangleSprite() const
{
	return m_triangleSprite;
}

sf::Sprite CToolbar::GetRectangleSprite() const
{
	return m_rectangleSprite;
}

sf::Sprite CToolbar::GetCircleSprite() const
{
	return m_circleSprite;
}

sf::Sprite CToolbar::GetAddSprite() const
{
	return m_addSprite;
}

sf::Sprite CToolbar::GetDragSprite() const
{
	return m_dragSprite;
}

sf::Sprite CToolbar::GetFillSprite() const
{
	return m_fillSprite;
}

float CToolbar::GetFrameHeight() const
{
	return 50.f;
}

std::string CToolbar::GetSpritePackageName() const
{
	return "Toolbar/Icons/";
}

float CToolbar::GetSpritePositionY() const
{
	return 10.f;
}

float CToolbar::GetMiniRectanglePositionY() const
{
	return 15.f;
}

sf::Vector2f CToolbar::GetMiniRectangleSize() const
{
	return sf::Vector2f(25.f, 25.f);
}
