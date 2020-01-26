#pragma once
#include <string>

class IState
{
public:
	virtual ~IState() = default;
	virtual std::string ToString() const = 0;

	virtual void MoveShape() = 0;
	virtual void AddShape() = 0;
	virtual void FillShape() = 0;
};