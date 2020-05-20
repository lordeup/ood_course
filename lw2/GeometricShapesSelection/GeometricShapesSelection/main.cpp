#include "./Handler/CShapeHandler.h"
#include <fstream>
#include <iostream>

int main()
{
	try
	{
		std::ifstream fileInput(INPUT_FILE_NAME);

		if (!fileInput.is_open())
		{
			std::cerr << ERROR_FILE_NOT_EXIST << std::endl;
			return 1;
		}

		CShapeHandler shapeHandler(fileInput, std::cout);
		shapeHandler.ProcessingCommand();
		shapeHandler.ShapeDisplay();
		shapeHandler.PrintShapeInfo();
	}
	catch (const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
	}

	return 0;
}
