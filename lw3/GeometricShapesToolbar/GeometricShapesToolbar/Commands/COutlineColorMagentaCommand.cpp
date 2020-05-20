#include "COutlineColorMagentaCommand.h"

COutlineColorMagentaCommand::COutlineColorMagentaCommand(ShapePtr shape)
	: ICommand(shape)
{
}

void COutlineColorMagentaCommand::Execute()
{
	m_shape->SetOutlineColor(MAGENTA_COLOR);
}
