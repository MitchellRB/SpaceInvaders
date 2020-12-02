#include "EnemyGrid.h"
EnemyGrid::EnemyGrid()
{
	m_updatePosition = -1;
	m_speed = 5;
	m_moveDownStaged = false;
	m_player = nullptr;
	m_secret = nullptr;
	m_activeEnemies = 0;
	m_lowestActive = 0;
}

EnemyGrid::~EnemyGrid()
{
	for (auto& e : m_grid)
	{
		delete e;
	}
}

void EnemyGrid::Init()
{	// Create enemies
	Enemy* newEnemy;
	for (int i = 0; i < gridHeight; i++)
	{
		for (int k = 0; k < gridWidth; k++)
		{
			newEnemy = new Enemy(this);
			newEnemy->SetRect(rl::Rectangle{ (float)(k * 40) + 100, (float)(i * 30) + 120, 20, 10 });
			m_grid.push_back(newEnemy);
			m_activeEnemies++;
		}
	}
	m_secret = new UFO();
	m_secret->SetRect(secretSpawn);
	m_secret->SetActive(false);
	m_secretTimer = GetRandomValue(60, 600);
}

void EnemyGrid::Update()
{
	// Stop if no enemies remain
	if (m_activeEnemies == 0)
	{
		return;
	}

	// Move down
	if (m_moveDownStaged && m_updatePosition <= m_lowestActive)
	{
		MoveDown();
		return;
	}

	// Go to the next active enemy
	do
	{
		if (m_updatePosition <= m_lowestActive)
		{
			m_updatePosition = m_grid.size();
		}
		m_updatePosition--;
	} while (m_grid[m_updatePosition]->GetActive() == false);

	// Move sideways
	bool reverse = m_grid[m_updatePosition]->Move(m_speed);
	if (reverse)
	{
		m_moveDownStaged = true;
	}
	for (auto& e : m_grid)
	{
		e->Update(m_player);
	}

	// Spawn UFO
	if (m_secretTimer > 0 && m_secret->GetActive() == false)
	{
		m_secretTimer--;
	}
	else if (m_secretTimer == 0 && m_secret->GetActive() == false)
	{
		m_secret->SetActive(true);
		m_secret->SetRect(secretSpawn);
		m_secretTimer = GetRandomValue(60, 600);
	}

	// Move UFO
	m_secret->Update(m_player);
}
void EnemyGrid::MoveDown()
{
	for (auto& e : m_grid)
	{
		e->GetRect().y += 40;
	}
	m_moveDownStaged = false;
	m_speed *= -1;
}

void EnemyGrid::SetPlayer(Player* player)
{
	m_player = player;
}

void EnemyGrid::EnemyDeath()
{
	m_activeEnemies--;

	if (m_activeEnemies == 0) { return; }

	while (m_grid[m_lowestActive]->GetActive() == false)
	{
		m_lowestActive++;
	}
}

void EnemyGrid::Draw()
{
	for (auto& e : m_grid)
	{
		e->Draw();
	}
	m_secret->Draw();
}
