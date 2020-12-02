#include "Enemy.h"
Enemy::Enemy(EnemyGrid* grid)
{
	m_parentGrid = grid;
	isActive = true;
}

Enemy::~Enemy()
{
	
}

void Enemy::Update(Player* player)
{
	if (!isActive) { return; }

	auto bullet = player->getBullet();
	if (bullet->GetActive() == true && m_rect.CheckCollision(bullet->GetPosition()))
	{
		isActive = false;
		bullet->SetActive(false);
		m_parentGrid->EnemyDeath();
	}
}

bool Enemy::Move(int speed)
{
	if (!isActive) { return false; }

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
	if (!isActive) { return; }
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
