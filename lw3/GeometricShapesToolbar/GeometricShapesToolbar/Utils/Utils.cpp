#include "Utils.h"

bool IsCheckSideShape(const sf::Shape& shape, const sf::Vector2f& position)
{
	return shape.getGlobalBounds().contains(position);
}

bool IsCheckSideSprite(const sf::Sprite& sprite, const sf::Vector2f& position)
{
	return sprite.getGlobalBounds().contains(position);
}