#include "Bullet.h"
#include "Colour.h"
Bullet::Bullet(int speed)
{
	m_isActive = false;
	m_position = rl::Vector2{ 0,0 };
	m_speed = speed;
	m_height = 5;
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	if (!m_isActive) { return; }

	m_position.y += m_speed;

	if (m_position.y < 40 || m_position.y > GetScreenHeight())
	{
		m_isActive = false;
	}
}

void Bullet::Draw()
{
	if (!m_isActive) { return; }

	DrawLine(m_position.x, m_position.y, m_position.x, m_position.y + m_height, Colour::GetColour(m_position.y));
}

bool Bullet::GetActive()
{
	return m_isActive;
}

void Bullet::SetActive(bool value)
{
	m_isActive = value;
}

void Bullet::SetPosition(rl::Vector2 position)
{
	m_position = position;
}

rl::Vector2 Bullet::GetPosition()
{
	return m_position;
}
