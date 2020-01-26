#include "CInvoker.h"

void CInvoker::SetCommand(ICommandPtr command)
{
	m_command.push_back(command);
}

void CInvoker::Run()
{
	for (auto command : m_command)
	{
		command->Execute();
	}
}
