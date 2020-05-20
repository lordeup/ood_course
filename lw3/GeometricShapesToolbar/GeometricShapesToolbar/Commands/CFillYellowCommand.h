#pragma once
#include "ICommand.h"

class CFillYellowCommand : public ICommand
{
public:
	CFillYellowCommand(ShapePtr shape);

	void Execute() override;
};