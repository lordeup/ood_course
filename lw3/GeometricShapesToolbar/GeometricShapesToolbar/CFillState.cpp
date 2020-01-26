#include "CFillState.h"

CFillState::CFillState(IContext& context)
	: m_context(context)
{
}

void CFillState::MoveShape()
{
	m_context.SetMoveState();
}

void CFillState::AddShape()
{
	m_context.SetAddState();
}

void CFillState::FillShape()
{
}

std::string CFillState::ToString() const
{
	return "Fill";
}
