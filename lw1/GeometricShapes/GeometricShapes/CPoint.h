#pragma once

class CPoint
{
public:
	CPoint(const float x, const float y);

	float GetX() const;
	float GetY() const;

private:
	float m_x;
	float m_y;
};
