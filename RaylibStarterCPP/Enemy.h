#pragma once
#include "raylib-cpp.hpp"
namespace rl = raylib;
class Enemy
{
public:
	Enemy();
	~Enemy();

	void Update();
	bool Move(int speed);
	void Draw();

	rl::Rectangle& GetRect();
	void SetRect(rl::Rectangle rect);

private:

	rl::Rectangle m_rect;

	const int leftBound = 60;
	const int rightBound = 60;
};

