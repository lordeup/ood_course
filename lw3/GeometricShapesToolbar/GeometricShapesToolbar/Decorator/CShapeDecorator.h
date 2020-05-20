#pragma once
#include "../Canvas/ICanvasDrawable.h"
#include "../Colors.h"
#include "../Const.h"
#include <unordered_set>

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

	sf::Vector2f GetFramePosition() const
	{
		return m_frame.getPosition();
	}

	sf::Vector2f GetFrameSize() const
	{
		return m_frame.getSize();
	}

	virtual void PrintInfo(std::ostream& iss) const = 0;

	virtual void SetOutlineThickness(const float thickness) = 0;
	virtual void SetOutlineColor(const sf::Color& color) = 0;
	virtual void SetFillColor(const sf::Color& color) = 0;

	virtual std::unordered_set<std::shared_ptr<CShapeDecorator>> GetShapes() = 0;

protected:
	sf::RectangleShape m_frame;

private:
	sf::Shape& m_shape;
};

using ShapePtr = std::shared_ptr<CShapeDecorator>;
