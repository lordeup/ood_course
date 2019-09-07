#pragma once
#include "CPoint.h"
#include "Const.h"
#include "IShape.h"

class CTriangle : public IShape
{
public:
	CTriangle(CPoint& vertex1, CPoint& vertex2, CPoint& vertex3);
	~CTriangle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;
	void PrintInfo(std::ostream& iss) const override;
	void Draw(ICanvas& canvas) const override;

private:
	float GetSideCounting(const CPoint& firstPoint, const CPoint& secondPoint) const;

	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
