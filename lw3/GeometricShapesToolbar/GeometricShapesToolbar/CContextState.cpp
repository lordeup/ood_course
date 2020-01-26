#include "CContextState.h"

CContextState::CContextState()
	: m_moveState(*this)
	, m_addState(*this)
	, m_fillState(*this)
	, m_state(&m_moveState)
{
}

void CContextState::MoveShape()
{
	m_state->MoveShape();
}

void CContextState::AddShape()
{
	m_state->AddShape();
}

void CContextState::FillShape()
{
	m_state->FillShape();
}

std::string CContextState::ToString() const
{
	return m_state->ToString();
}

IState* CContextState::GetState() const
{
	return m_state;
}

void CContextState::SetMoveState()
{
	m_state = &m_moveState;
}

void CContextState::SetAddState()
{
	m_state = &m_addState;
}

void CContextState::SetFillState()
{
	m_state = &m_fillState;
}
