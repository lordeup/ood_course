#pragma once
#include "ICommand.h"

class COutlineColorBlueCommand : public ICommand
{
public:
	COutlineColorBlueCommand(ShapePtr shape);

	void Execute() override;
};
