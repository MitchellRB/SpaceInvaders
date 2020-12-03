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

	int AliveEnemies() { return m_activeEnemies; }

private:

	void LoadSprites();
	void SetupGrid();
	void SetupUFO();

	std::vector<Enemy*> m_grid;
	const int gridWidth = 11; // 11
	const int gridHeight = 5; // 5
	
	int m_activeEnemies;
	int m_updatePosition;
	int m_lowestActive;
	int m_waitTime;

	int m_speed;

	bool m_moveDownStaged;

	Player* m_player;

	UFO* m_secret;
	int m_secretTimer;

	std::vector<rl::Texture2D*> m_enemySprites;

	const std::string filenames[6] = { "../Resources/Alien11.png", "../Resources/Alien12.png",
									   "../Resources/Alien21.png", "../Resources/Alien22.png",
									   "../Resources/Alien31.png", "../Resources/Alien32.png" };

	const rl::Rectangle secretSpawn = rl::Rectangle{ -40,60,30,10 };
};