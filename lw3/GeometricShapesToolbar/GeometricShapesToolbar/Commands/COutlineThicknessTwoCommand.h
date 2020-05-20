#pragma once
#include "ICommand.h"

class COutlineThicknessTwoCommand : public ICommand
{
public:
	COutlineThicknessTwoCommand(ShapePtr shape);

	void Execute() override;
};
