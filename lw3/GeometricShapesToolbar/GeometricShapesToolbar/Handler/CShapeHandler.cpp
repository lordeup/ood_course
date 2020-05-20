#include "CShapeHandler.h"

CShapeHandler::CShapeHandler(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

CShapeHandler& CShapeHandler::GetInstanceHandler(std::istream& input, std::ostream& output)
{
	static CShapeHandler instance(input, output);
	return instance;
}

std::shared_ptr<CRectangle> CShapeHandler::CreateRectangle(std::istream& iss)
{
	float x1, y1, x2, y2;

	iss >> x1 >> y1 >> x2 >> y2;

	sf::Vector2f leftTop(x1, y1);
	sf::Vector2f rightBottom(x2, y2);

	sf::RectangleShape rectangle;

	return std::make_shared<CRectangle>(rectangle, leftTop, rightBottom);
}

std::shared_ptr<CTriangle> CShapeHandler::CreateTriangle(std::istream& iss)
{
	float x1, y1, x2, y2, x3, y3;

	iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	sf::Vector2f vertex1(x1, y1);
	sf::Vector2f vertex2(x2, y2);
	sf::Vector2f vertex3(x3, y3);

	std::vector<sf::Vector2f> points = { vertex1, vertex2, vertex3 };

	sf::ConvexShape triangle(points.size());

	return std::make_shared<CTriangle>(triangle, points);
}

std::shared_ptr<CCircle> CShapeHandler::CreateCircle(std::istream& iss)
{
	float x, y, radius;

	iss >> x >> y >> radius;

	sf::Vector2f center(x, y);
	sf::CircleShape circle;

	return std::make_shared<CCircle>(circle, center, radius);
}

void CShapeHandler::ProcessingCommand()
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
			m_shapes.push_back(shapeDecorator);
		}
		else if (figure == FIGURE_TRIANGLE)
		{
			shapeDecorator = CreateTriangle(iss);
			m_shapes.push_back(shapeDecorator);
		}
		else if (figure == FIGURE_CIRCLE)
		{
			shapeDecorator = CreateCircle(iss);
			m_shapes.push_back(shapeDecorator);
		}
		else
		{
			m_output << FIGURE_UNKNOWN;
		}
	}
}

void CShapeHandler::PrintShapeInfo()
{
	if (m_shapes.empty())
	{
		m_output << ERROR_EMPTY_INPUT << std::endl;
	}
	else
	{
		for (const auto& shape : m_shapes)
		{
			shape->PrintInfo(m_output);
		}
	}
}

void CShapeHandler::ShapeDisplay()
{
	if (!m_shapes.empty())
	{
		CCanvas canvas(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, m_shapes);
		canvas.DrawingShapes();
	}
}
