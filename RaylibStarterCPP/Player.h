#pragma once
#include "raylib-cpp.hpp"
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

private:

	int m_position;
	int m_height;

	int m_leftBound;
	int m_rightBound;

	rl::Rectangle m_rect;
	rl::Rectangle m_offsetRect;

	const int moveSpeed = 5;
};

