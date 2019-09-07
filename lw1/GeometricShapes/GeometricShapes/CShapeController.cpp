#include "CShapeController.h"

CShapeController::CShapeController(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

std::shared_ptr<CRectangle> CShapeController::CreateRectangle(std::istream& iss)
{
	float x, y, width, height;

	iss >> x >> y >> width >> height;

	CPoint leftTop(x, y);

	return std::make_shared<CRectangle>(leftTop, width, height);
}

std::shared_ptr<CTriangle> CShapeController::CreateTriangle(std::istream& iss)
{
	float x1, y1, x2, y2, x3, y3;

	iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	CPoint vertex1(x1, y1);
	CPoint vertex2(x2, y2);
	CPoint vertex3(x3, y3);

	return std::make_shared<CTriangle>(vertex1, vertex2, vertex3);
}

std::shared_ptr<CCircle> CShapeController::CreateCircle(std::istream& iss)
{
	float x, y, radius;

	iss >> x >> y >> radius;

	CPoint center(x, y);

	return std::make_shared<CCircle>(center, radius);
}

void CShapeController::ProcessingCommand()
{
	std::string str;

	while (std::getline(m_input, str))
	{
		std::istringstream iss(str);

		std::string figure;
		iss >> figure;
		std::shared_ptr<IShape> shape;

		if (figure == FIGURE_RECTANGLE)
		{
			shape = CreateRectangle(iss);
			m_shape.push_back(shape);
		}
		else if (figure == FIGURE_TRIANGLE)
		{
			shape = CreateTriangle(iss);
			m_shape.push_back(shape);
		}
		else if (figure == FIGURE_CIRCLE)
		{
			shape = CreateCircle(iss);
			m_shape.push_back(shape);
		}
		else
		{
			m_output << FIGURE_UNKNOWN;
		}
	}
}

void CShapeController::PrintShapeInfo()
{
	if (m_shape.empty())
	{
		m_output << ERROR_EMPTY_INPUT << std::endl;
	}
	else
	{
		for (auto shape : m_shape)
		{
			shape->PrintInfo(m_output);
		}
	}
}

void CShapeController::ShapeDisplay()
{
	if (!m_shape.empty())
	{
		CCanvas canvas(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
		canvas.DrawingShapes(m_shape);
	}
}
