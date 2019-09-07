#pragma once
#include "CPoint.h"
#include "Const.h"
#include "IShape.h"

class CRectangle : public IShape
{
public:
	CRectangle(CPoint& leftTop, const float width, const float height);
	~CRectangle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;
	void PrintInfo(std::ostream& iss) const override;
	void Draw(ICanvas& canvas) const override;

	CPoint GetRightBottom() const;

private:
	float m_width;
	float m_height;

	CPoint m_leftTop;
};
