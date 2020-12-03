#include "Enemy.h"
Enemy::Enemy(EnemyGrid* grid)
{
	m_parentGrid = grid;
	m_isActive = true;
	m_usedSprite = true;
}

Enemy::~Enemy()
{
}

void Enemy::Update(Player* player)
{
	if (!m_isActive) { return; }

	// Check collisions
	auto bullet = player->getBullet();
	if (bullet->GetActive() == true && m_rect.CheckCollision(bullet->GetPosition()))
	{
		m_score->AddScore(m_value);
		bullet->SetActive(false);
		m_isActive = false;
		m_parentGrid->EnemyDeath();
	}
}

bool Enemy::Move(int speed)
{
	if (!m_isActive) { return false; }

	m_rect.x += speed;
	m_usedSprite = !m_usedSprite;
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
	if (!m_isActive) { return; }
	switch (m_usedSprite)
	{
	case true:
		m_sprites.first->Draw(m_rect.x, m_rect.y, Colour::GetColour(m_rect.y));
		break;
	case false:
		m_sprites.second->Draw(m_rect.x, m_rect.y, Colour::GetColour(m_rect.y));
		break;
	default:
		break;
	}
}

rl::Rectangle& Enemy::GetRect()
{
	return m_rect;
}

void Enemy::SetRect(rl::Rectangle rect)
{
	m_rect = rect;
}

void Enemy::SetSprites(rl::Texture2D* spriteA, rl::Texture2D* spriteB)
{
	m_sprites.first = spriteA;
	m_sprites.second = spriteB;
}