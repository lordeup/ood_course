#pragma once
#include "CComposite.h"
#include "Const.h"
#include "ICanvasDrawable.h"
#include "IShape.h"

const sf::Color BACKGROUND_COLOR_RECTANGLE = sf::Color::Red;
const sf::Color BACKGROUND_COLOR_TRIANGLE = sf::Color::Yellow;
const sf::Color BACKGROUND_COLOR_CIRCLE = sf::Color::Green;
const sf::Color BACKGROUND_COLOR_DRAW = sf::Color::Blue;

class CShapeDecorator : public sf::Shape
	, public ICanvasDrawable
	, public IShape
	, public CComposite
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
	virtual void SetOutlineThickness(const float thickness) = 0;
	virtual void SetOutlineColor(sf::Color color) = 0;
	virtual void SetFillColor(sf::Color color) = 0;

protected:
	sf::Shape& m_shape;
};

using ShapePtr = std::shared_ptr<CShapeDecorator>;
