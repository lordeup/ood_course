#pragma once
#include "Const.h"
#include "ICanvas.h"
#include "ICanvasDrawable.h"
#include "ICanvasShape.h"
#include <sstream>

class IShape : public ICanvasShape
	, public ICanvasDrawable
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual void PrintInfo(std::ostream& iss) const = 0;
};

typedef std::shared_ptr<IShape> ShapePtr;
