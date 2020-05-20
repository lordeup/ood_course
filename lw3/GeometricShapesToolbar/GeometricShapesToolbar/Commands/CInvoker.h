#pragma once
#include "ICommand.h"

class CInvoker
{
public:
	void SetCommand(std::shared_ptr<ICommand> command);
	void ExecuteCommand();

private:
	std::shared_ptr<ICommand> m_command;
};
