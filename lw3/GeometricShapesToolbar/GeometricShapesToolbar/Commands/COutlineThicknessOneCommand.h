#pragma once
#include "ICommand.h"

class COutlineThicknessOneCommand : public ICommand
{
public:
	COutlineThicknessOneCommand(ShapePtr shape);

	void Execute() override;
};
