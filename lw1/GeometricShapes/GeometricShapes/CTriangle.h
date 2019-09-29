#pragma once
#include "CShapeDecorator.h"

class CTriangle : public CShapeDecorator
{
public:
	CTriangle(sf::ConvexShape& shape, const std::vector<CPoint>& points);
	~CTriangle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;

	void PrintInfo(std::ostream& iss) const override;
	void Draw(ICanvas& canvas) const override;

private:
	sf::ConvexShape m_triangle;

	float GetSideCounting(const CPoint& firstPoint, const CPoint& secondPoint) const;

	std::vector<CPoint> m_points;
};
