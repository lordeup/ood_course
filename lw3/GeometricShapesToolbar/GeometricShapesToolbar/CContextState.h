#pragma once
#include "CAddState.h"
#include "CFillState.h"
#include "CMoveState.h"
#include "IContext.h"
#include "IState.h"

class CContextState : public IContext
{
public:
	CContextState();

	void MoveShape();
	void AddShape();
	void FillShape();

	std::string ToString() const;

	IState* GetState() const;

private:
	void SetMoveState() override;
	void SetAddState() override;
	void SetFillState() override;

	CMoveState m_moveState;
	CAddState m_addState;
	CFillState m_fillState;
	IState* m_state;
};