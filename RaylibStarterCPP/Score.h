#pragma once
#include "raylib-cpp.hpp"
class Score
{
public:
	Score();
	~Score();

	int GetScore() { return m_playerScore; }
	int GetHighScore() { return m_highScore; }

	void AddScore(int value);

	void Draw();

private:

	int m_playerScore;
	int m_highScore;
};

