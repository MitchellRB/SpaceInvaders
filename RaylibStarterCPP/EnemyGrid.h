#pragma once
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Enemy;

class EnemyGrid
{
public:
	EnemyGrid();
	~EnemyGrid();

	void Init();
	void Update();
	void Draw();

	void MoveDown();

	void SetPlayer(Player* player);

	void EnemyDeath();

private:

	std::vector<Enemy*> m_grid;
	const int gridWidth = 11; // 11
	const int gridHeight = 5; // 5
	
	int m_activeEnemies;

	int m_updatePosition;

	int m_speed;

	bool m_moveDownStaged;

	Player* m_player;

	int m_lowestActive;
};