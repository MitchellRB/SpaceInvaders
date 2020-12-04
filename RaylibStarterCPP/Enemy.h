#pragma once
#include <raylib-cpp.hpp>

#include "Player.h"
#include "EnemyGrid.h"
#include "Score.h"

class EnemyGrid;
class Player;

namespace rl = raylib;
class Enemy
{
public:
	Enemy(EnemyGrid* grid, int ID);
	~Enemy();

	void Update(Player* player);
	bool Move(int speed);
	void Draw();

	rl::Rectangle& GetRect();
	void SetRect(rl::Rectangle rect);

	bool GetActive() { return m_isActive; }
	void SetActive(bool value) { m_isActive = value; }

	void SetSprites(rl::Texture2D* spriteA, rl::Texture2D* spriteB, rl::Texture2D* death);

	void SetScore(Score* score) { m_score = score; }
	void SetValue(int value) { m_value = value; }

	bool TooLow();

	bool GetLowest() { return m_lowest; }
	void SetLowest(bool value) { m_lowest = value; }

	int GetID() { return m_ID; }

private:
	
	int m_ID;

	bool m_lowest;

	int m_bulletTimer;

	EnemyGrid* m_parentGrid;

	int m_value;
	Score* m_score;

	bool m_isActive;

	rl::Rectangle m_rect;

	std::pair<rl::Texture2D*, rl::Texture2D*> m_sprites;
	rl::Texture2D* m_deathSprite;
	rl::Texture2D* m_usedSprite;
	int m_deathTime;

	const int leftBound = 60;
	const int rightBound = 60;

	const int minTime = 300;
	const int maxTime = 900;
};