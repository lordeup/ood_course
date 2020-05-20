#pragma once
#define _USE_MATH_DEFINES

#include "../Decorator/CShapeDecorator.h"
#include "../Shape/IShape.h"
#include "../Utils/Utils.h"
#include <cmath>

class CCircle : public CShapeDecorator
	, public IShape
{
public:
	CCircle(sf::CircleShape& shape, const sf::Vector2f& center, const float radius = 50.f);

	float GetArea() const override;
	float GetPerimeter() const override;
	void PrintInfo(std::ostream& iss) const override;

	void DrawShape(sf::RenderWindow& window) override;
	void DrawFrame(sf::RenderWindow& window) override;

	bool IsCheckSide(const sf::Vector2f& position) override;

	void UpdatePosition(const sf::Vector2f& position) override;
	void UpdatingDifferentPosition(const sf::Vector2f& position) override;

	std::unordered_set<ShapePtr> GetShapes() override;

	float GetRadius() const;

private:
	sf::CircleShape m_circle;

	sf::Vector2f m_position, m_differentPosition;

	void SetFramePosition();
};
