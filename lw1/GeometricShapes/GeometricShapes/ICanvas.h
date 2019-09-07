#pragma once
#include "CPoint.h"
#include <vector>

class ICanvas
{
public:
	ICanvas() = default;
	virtual ~ICanvas() = default;

	virtual void DrawCircle(const CPoint& center, float radius) = 0;
	virtual void DrawRectangle(const CPoint& leftTop, float width, float height) = 0;
	virtual void DrawTriangle(const std::vector<CPoint>& points) = 0;
};
