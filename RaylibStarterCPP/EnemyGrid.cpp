#include "EnemyGrid.h"
EnemyGrid::EnemyGrid()
{
	m_updatePosition = -1;
	m_speed = 10;
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
			newEnemy = new Enemy();
			newEnemy->SetRect(rl::Rectangle{ (float)(k * 40) + 100, (float)(i * 30) + 40, 20, 10 });
			m_grid.push_back(newEnemy);
		}
	}
}

void EnemyGrid::Update()
{
	// Move down
	if (m_moveDownStaged && m_updatePosition < 1)
	{
		MoveDown();
		return;
	}

	// Move across
	if (m_updatePosition < 1)
	{
		m_updatePosition = m_grid.size();
	}
	m_updatePosition--;
	bool reverse = m_grid[m_updatePosition]->Move(m_speed);
	if (reverse)
	{
		m_moveDownStaged = true;
	}
	for (auto& e : m_grid)
	{
		e->Update();
	}
}

void EnemyGrid::MoveDown()
{
	for (auto& e : m_grid)
	{
		e->GetRect().y += 10;
	}
	m_moveDownStaged = false;
	m_speed *= -1;
}

void EnemyGrid::Draw()
{
	for (auto& e : m_grid)
	{
		e->Draw();
	}
}
