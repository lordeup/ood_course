#include "CFillYellowCommand.h"

CFillYellowCommand::CFillYellowCommand(ShapePtr shape)
	: ICommand(shape)
{
}

void CFillYellowCommand::Execute()
{
	m_shape->SetFillColor(YELLOW_COLOR);
}
