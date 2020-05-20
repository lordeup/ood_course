#pragma once
#include "../Decorator/CShapeDecorator.h"
#include "../Shape/IShape.h"
#include "../Utils/Utils.h"
#include <numeric>

class CTriangle : public CShapeDecorator
	, public IShape
{
public:
	CTriangle(sf::ConvexShape& shape, const sf::Vector2f& position);
	CTriangle(sf::ConvexShape& shape, const std::vector<sf::Vector2f>& points);

	float GetArea() const override;
	float GetPerimeter() const override;
	void PrintInfo(std::ostream& iss) const override;

	void DrawShape(sf::RenderWindow& window) override;
	void DrawFrame(sf::RenderWindow& window) override;

	bool IsCheckSide(const sf::Vector2f& position) override;

	void UpdatePosition(const sf::Vector2f& position) override;
	void UpdatingDifferentPosition(const sf::Vector2f& position) override;

	std::unordered_set<ShapePtr> GetShapes() override;

	void SetOutlineThickness(const float thickness) override;
	void SetOutlineColor(const sf::Color& color) override;
	void SetFillColor(const sf::Color& color) override;

private:
	sf::ConvexShape m_triangle;

	sf::Vector2f m_position, m_differentPosition;
	std::vector<float> m_sides;
	std::vector<sf::Vector2f> m_points;

	void Initialization();

	std::pair<std::vector<sf::Vector2f>::iterator, std::vector<sf::Vector2f>::iterator> GetMinMaxPointsX();
	std::pair<std::vector<sf::Vector2f>::iterator, std::vector<sf::Vector2f>::iterator> GetMinMaxPointsY();

	std::vector<sf::Vector2f> GetPoints(const sf::Vector2f& position) const;
	float GetSideCounting(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const;
	std::vector<float> GetSides() const;
	sf::Vector2f GetMidpoint() const;

	void SetFramePosition();
};
