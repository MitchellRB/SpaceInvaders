#pragma once

#include <raylib-cpp.hpp>

#include "Player.h"
#include "EnemyGrid.h"
#include "Barrier.h"

namespace rl = raylib;

enum class State
{
	Menu,
	Play,
	GameOver
};

class Game
{
public:
	Game();
	~Game();

	void Initalise();

	void StartGame();
	void StopGame();

	void Run();

	void Update(float deltaTime);

	void Draw();

	void Close();

private:

	State gameState;

	Player* player;

	EnemyGrid* grid;

	Score* score;

	rl::Window* window;

	rl::Color bgColour = BLACK;

	std::vector<Barrier*> barriers;

	unsigned int screenWidth = 640;
	unsigned int screenHeight = 480;
};
