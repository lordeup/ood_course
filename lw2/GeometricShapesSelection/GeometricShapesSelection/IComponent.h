#pragma once
#include "ICanvas.h"
#include <memory>

class IComponent
{
public:
	IComponent() = default;
	~IComponent() = default;

	virtual void MoveComposite(const sf::Vector2f& position) = 0;

private:
};