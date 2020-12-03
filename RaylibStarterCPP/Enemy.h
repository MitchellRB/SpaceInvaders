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

	bool GetActive() { return m_isActive; }
	void SetActive(bool value) { m_isActive = value; }

	void SetSprites(rl::Texture2D* spriteA, rl::Texture2D* spriteB);

private:

	EnemyGrid* m_parentGrid;

	bool m_isActive;

	rl::Rectangle m_rect;

	std::pair<rl::Texture2D*, rl::Texture2D*> m_sprites;
	bool m_usedSprite;

	const int leftBound = 60;
	const int rightBound = 60;
};