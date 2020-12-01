#pragma once

#include "raylib-cpp.hpp"

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

	rl::Window* window;

	rl::Color bgColour = RAYWHITE;

	unsigned int screenWidth = 640;
	unsigned int screenHeight = 480;
};
