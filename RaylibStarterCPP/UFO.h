#pragma once
#include "raylib-cpp.hpp"
#include "Player.h"
namespace rl = raylib;
class UFO
{
public:
	UFO();
	~UFO();

	void Update(Player* player);
	void Draw();

	bool GetActive() { return m_isActive; }
	void SetActive(bool value) {m_isActive = value; }

	rl::Rectangle& GetRect() { return m_rect; }
	void SetRect(rl::Rectangle rect) { m_rect = rect; }

	void SetSprite(const char* filename);

private:

	bool m_isActive;

	rl::Rectangle m_rect;

	rl::Texture2D m_sprite;
};

