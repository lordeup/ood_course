#pragma once
#include "../Decorator/CShapeDecorator.h"
#include "../Utils/Utils.h"

class CComposite : public CShapeDecorator
{
public:
	CComposite(std::unordered_set<ShapePtr>& shapes);

	void PrintInfo(std::ostream& iss) const override{};

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
	std::unordered_set<ShapePtr> m_shapes;

	void SetFramePosition();
	void SetFrameSize();
};