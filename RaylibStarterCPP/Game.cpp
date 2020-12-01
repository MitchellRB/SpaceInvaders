#include "Game.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

namespace rl = raylib;

Game::Game()
{

}

Game::~Game()
{

}

void Game::Initalise()
{
	window = new rl::Window(screenWidth, screenHeight, "Raylib C++");

	window->SetTargetFPS(60);
}

void Game::Run()
{
	while (!window->ShouldClose())
	{
		Update(GetFrameTime());

		Draw();
	}
}

void Game::Update(float deltaTime)
{

}

void Game::Draw()
{
	window->BeginDrawing();

	bgColour.ClearBackground();

	window->EndDrawing();
}

void Game::Close()
{
	delete window;
}
