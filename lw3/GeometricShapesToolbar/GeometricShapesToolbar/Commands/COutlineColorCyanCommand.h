#pragma once
#include "ICommand.h"

class COutlineColorCyanCommand : public ICommand
{
public:
	COutlineColorCyanCommand(ShapePtr shape);

	void Execute() override;
};
