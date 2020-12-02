#include "Enemy.h"
Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Update()
{

}

bool Enemy::Move(int speed)
{
	m_rect.x += speed;
	if ((speed < 0 && m_rect.x < leftBound) ||
		(speed > 0 && m_rect.x > GetScreenWidth() - rightBound))
	{
		// Reverse direction
		return true;
	}
	return false;

}

void Enemy::Draw()
{
	m_rect.Draw(WHITE);
}

rl::Rectangle& Enemy::GetRect()
{
	return m_rect;
}

void Enemy::SetRect(rl::Rectangle rect)
{
	m_rect = rect;
}
