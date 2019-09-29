#include "CShapeController.h"

CShapeController::CShapeController(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

std::shared_ptr<CRectangle> CShapeController::CreateRectangle(std::istream& iss)
{
	float x1, y1, x2, y2;

	iss >> x1 >> y1 >> x2 >> y2;

	CPoint leftTop(x1, y1);
	CPoint rightBottom(x2, y2);

	sf::RectangleShape rectangle;

	return std::make_shared<CRectangle>(rectangle, leftTop, rightBottom);
}

std::shared_ptr<CTriangle> CShapeController::CreateTriangle(std::istream& iss)
{
	float x1, y1, x2, y2, x3, y3;

	iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	CPoint vertex1(x1, y1);
	CPoint vertex2(x2, y2);
	CPoint vertex3(x3, y3);

	std::vector<CPoint> points = { vertex1, vertex2, vertex3 };

	sf::ConvexShape triangle(points.size());

	return std::make_shared<CTriangle>(triangle, points);
}

std::shared_ptr<CCircle> CShapeController::CreateCircle(std::istream& iss)
{
	float x, y, radius;

	iss >> x >> y >> radius;

	CPoint center(x, y);
	sf::CircleShape circle(radius);

	return std::make_shared<CCircle>(circle, center);
}

void CShapeController::ProcessingCommand()
{
	std::string str;

	while (std::getline(m_input, str))
	{
		std::istringstream iss(str);

		std::string figure;
		iss >> figure;
		ShapePtr shapeDecorator;

		if (figure == FIGURE_RECTANGLE)
		{
			shapeDecorator = CreateRectangle(iss);
			m_shape.push_back(shapeDecorator);
		}
		else if (figure == FIGURE_TRIANGLE)
		{
			shapeDecorator = CreateTriangle(iss);
			m_shape.push_back(shapeDecorator);
		}
		else if (figure == FIGURE_CIRCLE)
		{
			shapeDecorator = CreateCircle(iss);
			m_shape.push_back(shapeDecorator);
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
