#pragma once

class IShape
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
};
