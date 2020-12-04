#pragma once
#include <raylib-cpp.hpp>
#include <vector>
#include <list>

#include "Bullet.h"
#include "Enemy.h"

class Barrier
{
public:
	Barrier(rl::Vector2 pos);
	~Barrier();

	void Update();
	void Draw();

	void SetBullets(Bullet* player, std::list<Bullet*>* enemy);
	void SetGrid(std::vector<Enemy*>* grid);
private:

	bool CheckCollision(rl::Rectangle& block, Bullet* bullet);

	std::vector<rl::Rectangle> m_barrierBlocks;

	Bullet* m_playerBullet;
	std::list<Bullet*>* m_enemyBullets;
	std::vector<Enemy*>* m_grid;
};

