#include "COutlineColorBlueCommand.h"

COutlineColorBlueCommand::COutlineColorBlueCommand(ShapePtr shape)
	: ICommand(shape)
{
}

void COutlineColorBlueCommand::Execute()
{
	m_shape->SetOutlineColor(BLUE_COLOR);
}
