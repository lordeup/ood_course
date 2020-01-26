#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CRectangleMini : public ICommand
{
public:
	CRectangleMini(CToolbar& toolbar);

	void Execute() override;

private:
	CToolbar& m_toolbar;
};