#pragma once
#include "ICanvas.h"
#include "ICanvasDrawable.h"
#include <sstream>
#include <string>

class IShape : public ICanvasDrawable
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual void PrintInfo(std::ostream& iss) const = 0;
};
