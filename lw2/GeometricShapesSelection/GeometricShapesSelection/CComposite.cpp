#include "CComposite.h"

CComposite::CComposite()
{
}

void CComposite::MoveComposite(const sf::Vector2f& position)
{
	for (auto shape : m_shapeList)
	{
		shape->MoveComposite(position);
	}
}

void CComposite::Add(const ComponentPtr& component)
{
	m_shapeList.push_back(component);
}

void CComposite::Remove(const ComponentPtr& component)
{
	if (!m_shapeList.empty())
	{
		m_shapeList.remove(component);
	}
}
