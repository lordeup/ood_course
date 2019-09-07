#pragma once
#include "IShape.h"

class CShapeDecorator : public IShape
{
public:
	CShapeDecorator();

private:
	std::shared_ptr<IShape> m_component;
};