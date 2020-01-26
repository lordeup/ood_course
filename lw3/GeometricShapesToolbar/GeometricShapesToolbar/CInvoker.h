#pragma once
#include "ICommand.h"
#include <memory>
#include <vector>

using ICommandPtr = std::shared_ptr<ICommand>;

class CInvoker
{
public:
	CInvoker() = default;

	void SetCommand(ICommandPtr command);
	void Run();

private:
	std::vector<ICommandPtr> m_command;
};
