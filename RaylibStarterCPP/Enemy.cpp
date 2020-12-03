#include "Enemy.h"
Enemy::Enemy(EnemyGrid* grid, int ID)
{
	m_parentGrid = grid;
	m_isActive = true;
	m_usedSprite = true;
	m_lowest = false;
	m_bulletTimer = GetRandomValue(300, 1200);
	m_ID = ID;
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
		m_parentGrid->EnemyDeath(this);
	}

	// Bullets
	if (m_lowest)
	{
		m_bulletTimer--;
	}
	if (m_bulletTimer <= 0)
	{
		m_bulletTimer = GetRandomValue(300, 1200);
		m_parentGrid->SpawnBullet(this);
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

	rl::Color col = Colour::GetColour(m_rect.y);
	//if (m_lowest)
	//{
	//	col = RED;
	//}

	switch (m_usedSprite)
	{
	case true:
		m_sprites.first->Draw(m_rect.x, m_rect.y, col);
		break;
	case false:
		m_sprites.second->Draw(m_rect.x, m_rect.y, col);
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

bool Enemy::TooLow()
{
	if (m_isActive && m_rect.y > 400)
	{
		return true;
	}
	return false;
}
