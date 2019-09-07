#pragma once
#define _USE_MATH_DEFINES

#include "CPoint.h"
#include "Const.h"
#include "IShape.h"
#include <cmath>

class CCircle : public IShape
{
public:
	CCircle(CPoint& center, const float radius);
	~CCircle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;
	void PrintInfo(std::ostream& iss) const override;
	void Draw(ICanvas& canvas) const override;

private:
	float m_radius;

	CPoint m_center;
};
