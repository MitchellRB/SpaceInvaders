#pragma once

#include "raylib-cpp.hpp"

#include "Player.h"
#include "EnemyGrid.h"

namespace rl = raylib;

class Game
{
public:
	Game();
	~Game();

	void Initalise();

	void Run();

	void Update(float deltaTime);

	void Draw();

	void Close();

private:

	Player* player;

	EnemyGrid* grid;

	rl::Window* window;

	rl::Color bgColour = BLACK;

	unsigned int screenWidth = 640;
	unsigned int screenHeight = 480;
};
