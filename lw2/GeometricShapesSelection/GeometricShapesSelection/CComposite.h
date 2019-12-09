#pragma once
#include "IComponent.h"
#include <list>

using ComponentPtr = std::shared_ptr<IComponent>;

class CComposite : public IComponent
{
public:
	CComposite();
	~CComposite() = default;

	void MoveComposite(const sf::Vector2f& position) override;

	void Add(const ComponentPtr& component);
	void Remove(const ComponentPtr& component);

private:
	std::list<ComponentPtr> m_shapeList;
};