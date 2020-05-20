#include "CFillGreenCommand.h"

CFillGreenCommand::CFillGreenCommand(ShapePtr shape)
	: ICommand(shape)
{
}

void CFillGreenCommand::Execute()
{
	m_shape->SetFillColor(GREEN_COLOR);
}
