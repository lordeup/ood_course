#include "COutlineColorCyanCommand.h"

COutlineColorCyanCommand::COutlineColorCyanCommand(ShapePtr shape)
	: ICommand(shape)
{
}

void COutlineColorCyanCommand::Execute()
{
	m_shape->SetOutlineColor(CYAN_COLOR);
}
