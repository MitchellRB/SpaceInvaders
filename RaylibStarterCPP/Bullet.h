#pragma once
#include "raylib-cpp.hpp"
namespace rl = raylib;
class Bullet
{
public:
	Bullet(int speed);
	~Bullet();

	void Update();
	void Draw();

	bool GetActive();
	void SetActive(bool value);

	void SetPosition(rl::Vector2 position);
	rl::Vector2 GetPosition();

private:

	bool m_isActive;
	rl::Vector2 m_position;
	int m_height;
	int m_speed;
};

