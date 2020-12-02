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
	window = new rl::Window(screenWidth, screenHeight, "Space Invaders");

	window->SetTargetFPS(60);

	player = new Player();
	player->Init();
	player->SetHeight(40);
	player->SetBounds(20, 20);
	player->SetRect({ -10,-5,20,10 });
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
	player->Update();
}

void Game::Draw()
{
	window->BeginDrawing();

	bgColour.ClearBackground();

	player->Draw();

	window->EndDrawing();
}

void Game::Close()
{
	delete player;
	delete window;
}
