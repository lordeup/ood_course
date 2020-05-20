#include "CInvoker.h"

void CInvoker::SetCommand(std::shared_ptr<ICommand> command)
{
	m_command = command;
}

void CInvoker::ExecuteCommand()
{
	if (m_command)
	{
		m_command->Execute();
	}
}
