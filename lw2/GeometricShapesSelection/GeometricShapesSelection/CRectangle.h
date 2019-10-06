#pragma once
#include "CShapeDecorator.h"

class CRectangle : public CShapeDecorator
{
public:
	CRectangle(sf::RectangleShape& shape, const CPoint& leftTop, const CPoint& rightBottom);
	~CRectangle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;

	float GetWidth() const;
	float GetHeight() const;

	void PrintInfo(std::ostream& iss) const override;
	void Draw(ICanvas& canvas) const override;

private:
	sf::RectangleShape m_rectangle;

	CPoint m_leftTop;
	CPoint m_rightBottom;
};
