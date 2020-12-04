#include "Enemy.h"
Enemy::Enemy(EnemyGrid* grid, int ID)
{
	m_parentGrid = grid;
	m_isActive = true;
	m_lowest = false;
	m_bulletTimer = GetRandomValue(minTime, maxTime);
	m_ID = ID;
}

Enemy::~Enemy()
{
}

void Enemy::Update(Player* player)
{
	if (!m_isActive)
	{
		if (m_deathTime > 0)
			m_deathTime--;
		return;
	}

	// Check collisions
	auto bullet = player->getBullet();
	if (bullet->GetActive() == true && m_rect.CheckCollision(bullet->GetPosition()))
	{
		m_score->AddScore(m_value);
		bullet->SetActive(false);
		m_isActive = false;
		m_parentGrid->EnemyDeath(this);
		m_deathTime = 15;
		m_usedSprite = m_deathSprite;
	}

	// Bullets
	if (m_lowest)
	{
		m_bulletTimer--;
	}
	if (m_bulletTimer <= 0)
	{
		m_bulletTimer = GetRandomValue(minTime, maxTime);
		m_parentGrid->SpawnBullet(this);
	}
}

bool Enemy::Move(int speed)
{
	if (!m_isActive) { return false; }

	m_rect.x += speed;
	
	if (m_usedSprite == m_sprites.first)
	{
		m_usedSprite = m_sprites.second;
	}
	else
	{
		m_usedSprite = m_sprites.first;
	}

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
	if (!m_isActive && m_deathTime == 0) { return; }

	rl::Color col = Colour::GetColour(m_rect.y);
	//if (m_lowest)
	//{
	//	col = RED;
	//}
	m_usedSprite->Draw(m_rect.x, m_rect.y, col);
}

rl::Rectangle& Enemy::GetRect()
{
	return m_rect;
}

void Enemy::SetRect(rl::Rectangle rect)
{
	m_rect = rect;
}

void Enemy::SetSprites(rl::Texture2D* spriteA, rl::Texture2D* spriteB, rl::Texture2D* death)
{
	m_sprites.first = spriteA;
	m_sprites.second = spriteB;
	m_deathSprite = death;
	m_usedSprite = m_sprites.first;
}

bool Enemy::TooLow()
{
	if (m_isActive && m_rect.y > 400)
	{
		return true;
	}
	return false;
}
