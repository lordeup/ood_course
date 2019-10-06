#pragma once
#define _USE_MATH_DEFINES

#include "CShapeDecorator.h"
#include <cmath>

class CCircle : public CShapeDecorator
{
public:
	CCircle(sf::CircleShape& shape, const CPoint& center);
	~CCircle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;

	void PrintInfo(std::ostream& iss) const override;
	void Draw(ICanvas& canvas) const override;

private:
	sf::CircleShape m_circle;

	CPoint m_center;
};
