#pragma once
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "UFO.h"

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
	int m_lowestActive;

	int m_speed;

	bool m_moveDownStaged;

	Player* m_player;

	UFO* m_secret;
	int m_secretTimer;
	const rl::Rectangle secretSpawn = rl::Rectangle{ -40,60,30,10 };
};