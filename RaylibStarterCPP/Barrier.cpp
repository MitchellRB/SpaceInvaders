#include "Barrier.h"
#include "Colour.h"

Barrier::Barrier(rl::Vector2 pos)
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if ((i == 0 || i == 9) && k == 0) continue;
			if ((i > 2 && i < 7) && k > 2) continue;

			rl::Rectangle newRect;
			newRect.x = pos.x + i * 6;
			newRect.y = pos.y + k * 8 + 350;
			newRect.width = 6;
			newRect.height = 8;
			m_barrierBlocks.push_back(newRect);
		}
	}
}

Barrier::~Barrier()
{

}

void Barrier::Update()
{
	for (auto& block : m_barrierBlocks)
	{
		if (CheckCollision(block, m_playerBullet))
		{
			m_playerBullet->SetActive(false);
			block.x = -100;
			continue;
		}
		for (auto& bullet : *m_enemyBullets)
		{
			if (CheckCollision(block, bullet))
			{
				block.x = -100;
				bullet->SetActive(false);
				continue;
			}
		}
		for (auto& alien : *m_grid)
		{
			if (alien->GetActive() == true && block.y < alien->GetRect().y + alien->GetRect().height + 2)
			{
				block.x = -100;
				continue;
			}
		}
	}
}

void Barrier::Draw()
{
	for (auto& block : m_barrierBlocks)
	{
		block.Draw(Colour::GetColour(block.y));
	}
}

void Barrier::SetBullets(Bullet* player, std::list<Bullet*>* enemy)
{
	m_playerBullet = player;
	m_enemyBullets = enemy;
}

void Barrier::SetGrid(std::vector<Enemy*>* grid)
{
	m_grid = grid;
}

bool Barrier::CheckCollision(rl::Rectangle& block, Bullet* bullet)
{
	if (bullet->GetActive() == true && block.CheckCollision(bullet->GetPosition()))
	{
		return true;
	}
	return false;
}
