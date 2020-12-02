#pragma once
#include "raylib-cpp.hpp"
class Player
{
public:
	Player();
	~Player();

	void Update();
	void Draw();

	void SetBounds(int left, int right);
	void SetHeight(int h);

private:

	int m_position;
	int m_height;

	int m_leftBound;
	int m_rightBound;
};

