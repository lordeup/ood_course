#pragma once

class ICanvasShape
{
public:
	ICanvasShape() = default;
	virtual ~ICanvasShape() = default;

	virtual void DrawShape() const = 0;
};
