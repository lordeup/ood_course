#pragma once
#include "ICommand.h"

class CFillGreenCommand : public ICommand
{
public:
	CFillGreenCommand(ShapePtr shape);

	void Execute() override;
};