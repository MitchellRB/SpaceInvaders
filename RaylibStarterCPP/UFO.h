#pragma once
#include <raylib-cpp.hpp>
#include "Player.h"
#include "Score.h"
namespace rl = raylib;

class Player;

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

	void SetScore(Score* score) { m_score = score; }
	void SetValue(int value) { m_value = value; }

private:

	bool m_isActive;

	int m_value;
	Score* m_score;

	rl::Rectangle m_rect;

	rl::Texture2D m_sprite;
};

