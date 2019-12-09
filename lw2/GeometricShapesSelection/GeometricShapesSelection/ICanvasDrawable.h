#pragma once
#include "ICanvas.h"
#include <iostream>

class ICanvasDrawable
{
public:
	ICanvasDrawable() = default;
	virtual ~ICanvasDrawable() = default;

	virtual void Draw(ICanvas& canvas) = 0;
	virtual void DrawFrame(ICanvas& canvas) = 0;
	virtual void DeleteFrame(ICanvas& canvas) = 0;
	virtual void Move(ICanvas& canvas, const sf::Vector2f& position) = 0;
	virtual bool IsCheckSide(const sf::Vector2f& position) = 0;
};