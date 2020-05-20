#include "CFillRedCommand.h"

CFillRedCommand::CFillRedCommand(ShapePtr shape)
	: ICommand(shape)
{
}

void CFillRedCommand::Execute()
{
	m_shape->SetFillColor(RED_COLOR);
}
