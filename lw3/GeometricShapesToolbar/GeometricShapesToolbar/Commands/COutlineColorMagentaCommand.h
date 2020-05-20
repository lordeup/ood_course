#pragma once
#include "ICommand.h"

class COutlineColorMagentaCommand : public ICommand
{
public:
	COutlineColorMagentaCommand(ShapePtr shape);

	void Execute() override;
};
