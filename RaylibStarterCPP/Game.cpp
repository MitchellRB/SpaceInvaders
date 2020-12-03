#include "Game.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

namespace rl = raylib;

Game::Game()
{
	player = nullptr;
	grid = nullptr;
	window = nullptr;
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
	player->SetBounds(60, 60);
	player->SetRect({ -10,-5,20,10 });
	player->SetSprite("../Resources/Player.png");

	score = new Score();

	grid = new EnemyGrid();
	grid->SetScore(score);
	grid->Init();
	grid->SetPlayer(player);

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

	grid->Update();

	if (grid->AliveEnemies() == 0)
	{
		// Reset enemies
		delete grid;
		grid = new EnemyGrid();
		grid->SetScore(score);
		grid->Init();
		grid->SetPlayer(player);
	}
}

void Game::Draw()
{
	window->BeginDrawing();

	bgColour.ClearBackground();

	player->Draw();

	grid->Draw();

	score->Draw();

	window->EndDrawing();
}

void Game::Close()
{
	delete window;
	delete player;
	delete grid;
	delete score;
}
