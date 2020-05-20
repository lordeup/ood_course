#pragma once
#include "../Decorator/CShapeDecorator.h"

class ICommand
{
public:
	ICommand(ShapePtr& shape)
		: m_shape(shape)
	{
	}
	virtual ~ICommand() = default;

	virtual void Execute() = 0;

protected:
	ShapePtr m_shape;
};