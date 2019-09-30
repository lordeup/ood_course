#pragma once
#include "Const.h"
#include "ICanvasDrawable.h"
#include "IShape.h"

class CShapeDecorator : public sf::Shape
	, public ICanvasDrawable
	, public IShape
{
public:
	CShapeDecorator(sf::Shape& shape)
		: m_shape(shape)
	{
	}

	std::size_t sf::Shape::getPointCount() const
	{
		return m_shape.getPointCount();
	}

	sf::Vector2f sf::Shape::getPoint(std::size_t index) const
	{
		return m_shape.getPoint(index);
	}

	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;

protected:
	sf::Shape& m_shape;
};

using ShapePtr = std::shared_ptr<CShapeDecorator>;
