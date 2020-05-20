#include "COutlineThicknessOneCommand.h"

COutlineThicknessOneCommand::COutlineThicknessOneCommand(ShapePtr shape)
	: ICommand(shape)
{
}

void COutlineThicknessOneCommand::Execute()
{
	m_shape->SetOutlineThickness(2.f);
}
