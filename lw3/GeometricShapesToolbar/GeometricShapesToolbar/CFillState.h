#pragma once
#include "IContext.h"
#include "IState.h"

class CFillState : public IState
{
public:
	CFillState(IContext& context);

	void MoveShape() override;
	void AddShape() override;
	void FillShape() override;

	std::string ToString() const;

private:
	IContext& m_context;
};