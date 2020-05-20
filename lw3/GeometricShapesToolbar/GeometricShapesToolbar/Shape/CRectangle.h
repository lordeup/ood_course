#pragma once
#include "../Decorator/CShapeDecorator.h"
#include "../Shape/IShape.h"
#include "../Utils/Utils.h"

class CRectangle : public CShapeDecorator
	, public IShape
{
public:
	CRectangle(sf::RectangleShape& shape, const sf::Vector2f& position);
	CRectangle(sf::RectangleShape& shape, const sf::Vector2f& leftTop, const sf::Vector2f& rightBottom);

	float GetArea() const override;
	float GetPerimeter() const override;
	void PrintInfo(std::ostream& iss) const override;

	void DrawShape(sf::RenderWindow& window) override;
	void DrawFrame(sf::RenderWindow& window) override;

	bool IsCheckSide(const sf::Vector2f& position) override;

	void UpdatePosition(const sf::Vector2f& position) override;
	void UpdatingDifferentPosition(const sf::Vector2f& position) override;

	std::unordered_set<ShapePtr> GetShapes() override;

	void SetOutlineThickness(const float thickness) override;
	void SetOutlineColor(const sf::Color& color) override;
	void SetFillColor(const sf::Color& color) override;

	float GetWidth() const;
	float GetHeight() const;

private:
	sf::RectangleShape m_rectangle;

	sf::Vector2f m_position, m_differentPosition;
	sf::Vector2f m_leftTop, m_rightBottom;

	void Initialization(const sf::Vector2f& position);

	sf::Vector2f GetSize() const;

	void SetFramePosition();

	float GetDifferenceFrame() const;
	float GetDifferenceShape() const;
};
