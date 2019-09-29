#pragma once
#include "CShapeDecorator.h"

class CTriangle : public CShapeDecorator
{
public:
	CTriangle(sf::ConvexShape shape, CPoint& vertex1, CPoint& vertex2, CPoint& vertex3);
	~CTriangle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;

	void PrintInfo(std::ostream& iss) const override;
	void Draw(ICanvas& canvas) const override;

private:
	sf::ConvexShape m_triangle;

	float GetSideCounting(const CPoint& firstPoint, const CPoint& secondPoint) const;

	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
