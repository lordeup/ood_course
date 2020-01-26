#include "CShapeHandler.h"
#include <fstream>
#include <iostream>

int main()
{
	std::ifstream fileInput(INPUT_FILE_NAME);

	if (!fileInput.is_open())
	{
		std::cerr << ERROR_FILE_NOT_EXIST << std::endl;
		return 1;
	}

	CShapeHandler& shapeHandler = CShapeHandler::GetInstanceHandler(fileInput, std::cout);
	shapeHandler.ProcessingCommand();
	shapeHandler.PrintShapeInfo();
	shapeHandler.ShapeDisplay();

	return 0;
}
