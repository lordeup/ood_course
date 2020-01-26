#include "CAddState.h"

CAddState::CAddState(IContext& context)
	: m_context(context)
{
}

void CAddState::MoveShape()
{
	m_context.SetMoveState();
}

void CAddState::AddShape()
{
}

void CAddState::FillShape()
{
	m_context.SetFillState();
}

std::string CAddState::ToString() const
{
	return "Add";
}
