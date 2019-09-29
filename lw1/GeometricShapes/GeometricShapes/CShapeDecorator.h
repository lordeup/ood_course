#pragma once

#include "CPoint.h"
#include "Const.h"
#include "SFML/Graphics.hpp"
#include "ICanvas.h"
#include <sstream>
#include "ICanvasDrawable.h"

class CShapeDecorator : public sf::Shape
	, public ICanvasDrawable
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
	virtual void PrintInfo(std::ostream& iss) const = 0;

protected:
	sf::Shape& m_shape;
};

typedef std::shared_ptr<CShapeDecorator> ShapePtrDecorator;
