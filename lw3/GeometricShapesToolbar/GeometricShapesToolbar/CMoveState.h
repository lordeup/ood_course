#pragma once
#include "IContext.h"
#include "IState.h"

class CMoveState : public IState
{
public:
	CMoveState(IContext& context);

	void MoveShape() override;
	void AddShape() override;
	void FillShape() override;

	std::string ToString() const;

private:
	IContext& m_context;
};