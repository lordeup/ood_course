#include "CMoveState.h"

CMoveState::CMoveState(IContext& context)
	: m_context(context)
{
}

void CMoveState::MoveShape()
{
}

void CMoveState::AddShape()
{
	m_context.SetAddState();
}

void CMoveState::FillShape()
{
	m_context.SetFillState();
}

std::string CMoveState::ToString() const
{
	return "Move";
}
