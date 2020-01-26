#pragma once
#define _USE_MATH_DEFINES

#include "CShapeDecorator.h"
#include <cmath>

class CCircle : public CShapeDecorator
{
public:
	CCircle(sf::CircleShape& shape, const sf::Vector2f& center);
	~CCircle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;

	void PrintInfo(std::ostream& iss) const override;
	void Draw(ICanvas& canvas) override;
	void DrawFrame(ICanvas& canvas) override;
	void DeleteFrame(ICanvas& canvas) override;
	void Move(ICanvas& canvas, const sf::Vector2f& position) override;

	bool IsCheckSide(const sf::Vector2f& position) override;

	void MoveComposite(const sf::Vector2f& position) override;

	void SetOutlineThickness(const float thickness) override;
	void SetOutlineColor(sf::Color color) override;
	void SetFillColor(sf::Color color) override;

private:
	sf::CircleShape m_circle;

	sf::Vector2f m_prevPosition;
	sf::Vector2f m_center;
};
