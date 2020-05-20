#include "COutlineThicknessTwoCommand.h"

COutlineThicknessTwoCommand::COutlineThicknessTwoCommand(ShapePtr shape)
	: ICommand(shape)
{
}

void COutlineThicknessTwoCommand::Execute()
{
	m_shape->SetOutlineThickness(3.f);
}
