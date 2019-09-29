#pragma once
#include "CCanvas.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"

class CShapeController
{
public:
	CShapeController(std::istream& input, std::ostream& output);
	~CShapeController() = default;

	void ProcessingCommand();
	void PrintShapeInfo();
	void ShapeDisplay();

private:
	std::shared_ptr<CRectangle> CreateRectangle(std::istream& iss);
	std::shared_ptr<CTriangle> CreateTriangle(std::istream& iss);
	std::shared_ptr<CCircle> CreateCircle(std::istream& iss);

	std::istream& m_input;
	std::ostream& m_output;

	std::vector<ShapePtr> m_shape;
};
