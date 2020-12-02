#pragma once
#include "raylib-cpp.hpp"

#include "Player.h"
#include "EnemyGrid.h"

class EnemyGrid;

namespace rl = raylib;
class Enemy
{
public:
	Enemy(EnemyGrid* grid);
	~Enemy();

	void Update(Player* player);
	bool Move(int speed);
	void Draw();

	rl::Rectangle& GetRect();
	void SetRect(rl::Rectangle rect);

	bool GetActive() { return isActive; }
	void SetActive(bool value) { isActive = value; }

private:

	EnemyGrid* m_parentGrid;

	bool isActive;

	rl::Rectangle m_rect;

	const int leftBound = 60;
	const int rightBound = 60;
};