#include "CShapeController.h"
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

	CShapeController shapeController(fileInput, std::cout);
	shapeController.ProcessingCommand();
	shapeController.PrintShapeInfo();
	shapeController.ShapeDisplay();

	return 0;
}
