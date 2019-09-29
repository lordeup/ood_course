#pragma once
#include <sstream>

class IShape
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual void PrintInfo(std::ostream& iss) const = 0;
};
