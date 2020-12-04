#pragma once
#include <vector>
#include <list>
#include <raylib-cpp.hpp>
#include "Bullet.h"
#include "Colour.h"
namespace rl = raylib;
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

	void SetSprite(const char* filename);

	int GetLives() { return m_lives; }
	void Kill() { m_lives--; }

	void SetEnemyBullets(std::list<Bullet*>* bulletPool) { m_enemyBullets = bulletPool; }

private:

	int m_position;
	int m_height;

	int m_leftBound;
	int m_rightBound;

	rl::Rectangle m_rect;
	rl::Rectangle m_offsetRect;

	rl::Texture2D* m_sprite;
	
	Bullet* m_bullet;

	std::list<Bullet*>* m_enemyBullets;

	int m_lives;

	const int moveSpeed = 5;
};

