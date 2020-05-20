#pragma once
#include "../Canvas/CCanvas.h"
#include "../Shape/CCircle.h"
#include "../Shape/CRectangle.h"
#include "../Shape/CTriangle.h"

class CShapeHandler
{
public:
	CShapeHandler(std::istream& input, std::ostream& output);

	void ProcessingCommand();
	void PrintShapeInfo();
	void ShapeDisplay();

private:
	std::shared_ptr<CRectangle> CreateRectangle(std::istream& iss);
	std::shared_ptr<CTriangle> CreateTriangle(std::istream& iss);
	std::shared_ptr<CCircle> CreateCircle(std::istream& iss);

	std::istream& m_input;
	std::ostream& m_output;

	std::vector<ShapePtr> m_shapes;
};
