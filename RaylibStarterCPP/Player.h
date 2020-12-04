#pragma once
#include <vector>
#include <list>
#include <raylib-cpp.hpp>
#include "Bullet.h"
#include "Colour.h"
#include "EnemyGrid.h"
namespace rl = raylib;

class EnemyGrid;

class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	void SetBounds(int left, int right);
	void SetHeight(int height);

	void SetRect(rl::Rectangle rect);

	Bullet* getBullet();

	void SetSprites(const char* normal, const char* death);

	int GetLives() { return m_lives; }
	void Kill();

	void SetEnemyBullets(std::list<Bullet*>* bulletPool) { m_enemyBullets = bulletPool; }

	void SetGrid(EnemyGrid* grid) { m_grid = grid; }

private:

	int m_position;
	int m_height;

	int m_leftBound;
	int m_rightBound;

	rl::Rectangle m_rect;
	rl::Rectangle m_offsetRect;

	rl::Texture2D* m_sprite;
	rl::Texture2D* m_deathSprite;
	rl::Texture2D* m_activeSprite;
	
	Bullet* m_bullet;

	std::list<Bullet*>* m_enemyBullets;

	EnemyGrid* m_grid;

	int m_lives;

	int m_deathTimer;

	const int moveSpeed = 5;
};

