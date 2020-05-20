#pragma once
#include "ICommand.h"

class CFillRedCommand : public ICommand
{
public:
	CFillRedCommand(ShapePtr shape);

	void Execute() override;
};