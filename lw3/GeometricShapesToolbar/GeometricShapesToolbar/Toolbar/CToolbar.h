#pragma once
#include "../Commands/CFillGreenCommand.h"
#include "../Commands/CFillRedCommand.h"
#include "../Commands/CFillYellowCommand.h"
#include "../Commands/CInvoker.h"
#include "../Commands/COutlineColorBlueCommand.h"
#include "../Commands/COutlineColorCyanCommand.h"
#include "../Commands/COutlineColorMagentaCommand.h"
#include "../Commands/COutlineThicknessOneCommand.h"
#include "../Commands/COutlineThicknessTwoCommand.h"
#include "../Utils/Utils.h"

class CToolbar
{
public:
	CToolbar(sf::RenderWindow& window);

	void Draw();

	bool IsSelectedCommandOutline(ShapePtr& shape, const sf::Vector2f& position);
	bool IsSelectedCommandFill(ShapePtr& shape, const sf::Vector2f& position);

	sf::Sprite GetTriangleSprite() const;
	sf::Sprite GetRectangleSprite() const;
	sf::Sprite GetCircleSprite() const;
	sf::Sprite GetAddSprite() const;
	sf::Sprite GetDragSprite() const;
	sf::Sprite GetFillSprite() const;

private:
	sf::RenderWindow& m_window;
	sf::RectangleShape m_frame, m_fillGreen, m_fillRed, m_fillYellow, m_outlineBlue, m_outlineCyan, m_outlineMagenta;

	sf::Sprite m_addSprite, m_triangleSprite, m_rectangleSprite, m_circleSprite, m_outline1Sprite, m_outline2Sprite, m_dragSprite, m_fillSprite;

	std::shared_ptr<CInvoker> m_invoker;

	void WindowDraw(const sf::Drawable& drawable);
	sf::Sprite GetSprite(const std::string filename, const float positionX);
	void DrawColoredRectangle(sf::RectangleShape& rectangle, const sf::Color& color, const float positionX);

	float GetFrameHeight() const;
	std::string GetSpritePackageName() const;
	float GetSpritePositionY() const;

	float GetMiniRectanglePositionY() const;
	sf::Vector2f GetMiniRectangleSize() const;
};
