#pragma once

class IContext
{
public:
	virtual ~IContext() = default;

	virtual void SetMoveState() = 0;
	virtual void SetAddState() = 0;
	virtual void SetFillState() = 0;
};