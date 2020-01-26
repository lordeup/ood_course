#pragma once
#include "CCanvas.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"

class CShapeHandler
{
public:
	static CShapeHandler& GetInstanceHandler(std::istream& input, std::ostream& output);

	void ProcessingCommand();
	void PrintShapeInfo();
	void ShapeDisplay();

private:
	CShapeHandler(std::istream& input, std::ostream& output);
	CShapeHandler(const CShapeHandler& root) = delete;
	CShapeHandler& operator=(const CShapeHandler&) = delete;

	std::shared_ptr<CRectangle> CreateRectangle(std::istream& iss);
	std::shared_ptr<CTriangle> CreateTriangle(std::istream& iss);
	std::shared_ptr<CCircle> CreateCircle(std::istream& iss);

	std::istream& m_input;
	std::ostream& m_output;

	std::vector<ShapePtr> m_shape;
};
