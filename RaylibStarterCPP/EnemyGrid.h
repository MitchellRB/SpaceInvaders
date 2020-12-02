#pragma once
#include <vector>
#include "Enemy.h"
#include "Player.h"
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

private:

	std::vector<Enemy*> m_grid;
	const int gridWidth = 11;
	const int gridHeight = 5;
	
	int m_updatePosition;

	int m_speed;

	bool m_moveDownStaged;

	Player* m_player;
};

