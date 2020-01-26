#pragma once
#include "CShapeDecorator.h"

class CRectangle : public CShapeDecorator
{
public:
	CRectangle(sf::RectangleShape& shape, const sf::Vector2f& leftTop, const sf::Vector2f& rightBottom);
	~CRectangle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;

	float GetWidth() const;
	float GetHeight() const;

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
	sf::RectangleShape m_rectangle;

	sf::Vector2f m_prevPosition;

	sf::Vector2f m_leftTop, m_leftTopDraw;
	sf::Vector2f m_rightBottom;
};
