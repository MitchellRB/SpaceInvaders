#pragma once
#include "Enemy.h"
#include <vector>
class EnemyGrid
{
public:
	EnemyGrid();
	~EnemyGrid();

	void Init();
	void Update();
	void Draw();

	void MoveDown();

private:

	std::vector<Enemy*> m_grid;
	const int gridWidth = 11;
	const int gridHeight = 5;
	
	int m_updatePosition;

	int m_speed;

	bool m_moveDownStaged;
};

