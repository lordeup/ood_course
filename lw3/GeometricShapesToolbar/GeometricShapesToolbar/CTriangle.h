#pragma once
#include "CShapeDecorator.h"

class CTriangle : public CShapeDecorator
{
public:
	CTriangle(sf::ConvexShape& shape, const std::vector<sf::Vector2f>& points);
	~CTriangle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;

	void PrintInfo(std::ostream& iss) const override;
	void Draw(ICanvas& canvas) override;
	void DrawFrame(ICanvas& canvas) override;
	void DeleteFrame(ICanvas& canvas) override;
	void Move(ICanvas& canvas, const sf::Vector2f& position) override;
	bool IsCheckSide(const sf::Vector2f& position) override;

	void MoveComposite(const sf::Vector2f& position) override;

	void SetOutlineThickness(const float thickness) override;
	void SetOutlineColor(sf::Color color) override;
	void SetFillColor(sf::Color color) override;

private:
	sf::ConvexShape m_triangle;

	sf::Vector2f m_prevPosition;

	float GetSideCounting(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const;
	float GetBelongSide(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::Vector2f& position) const;

	std::vector<sf::Vector2f> m_points;
};
