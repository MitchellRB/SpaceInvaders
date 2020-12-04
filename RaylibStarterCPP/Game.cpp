#include "Game.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

#include <sstream>

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

	gameState = State::Menu;

	splashImage.Load("../Resources/Splash.png");

	score = new Score();
}

void Game::StartGame()
{
	player = new Player();
	player->Init();
	player->SetHeight(40);
	player->SetBounds(60, 60);
	player->SetRect({ -10,-5,20,10 });
	player->SetSprite("../Resources/Player.png");

	grid = new EnemyGrid();
	grid->SetScore(score);
	grid->Init();
	grid->SetPlayer(player);
	
	for (int i = 0; i < 4; i++)
	{
		Barrier* newBarrier = new Barrier(i * 120 + 100);
		newBarrier->SetBullets(player->getBullet(), grid->GetBullets());
		newBarrier->SetGrid(grid->GetGrid());
		barriers.push_back(newBarrier);
	}
}

void Game::StopGame()
{
	if (player)
	{
		delete player;
		player = nullptr;
	}
	if (grid)
	{
		delete grid;
		grid = nullptr;
	}
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
	if (gameState == State::Menu)
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			StartGame();
			gameState = State::Play;
			return;
		}
	}
	else if (gameState == State::Play)
	{
		if (player)
		player->Update();

		if (grid)
		grid->Update();

		for (auto& b : barriers)
		{
			b->Update();
		}

		if (grid->AliveEnemies() == 0)
		{
			// Reset enemies
			delete grid;
			grid = new EnemyGrid();
			grid->SetScore(score);
			grid->Init();
			grid->SetPlayer(player);
		}
		else if (player->GetLives() == 0)
		{
			gameState = State::GameOver;
			StopGame();
			return;
		}
	}
	else if (gameState == State::GameOver)
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			gameState = State::Menu;
			return;
		}
	}
}

void Game::Draw()
{
	window->BeginDrawing();

	bgColour.ClearBackground();

	if (gameState == State::Menu)
	{
		splashImage.Draw(0, 0);
	}
	else if (gameState == State::Play)
	{
		if (player)
		player->Draw();

		if (grid)
		grid->Draw();

		score->Draw();

		for (auto& b : barriers)
		{
			b->Draw();
		}
	}
	else if (gameState == State::GameOver)
	{
		score->Draw();
		DrawText("Game over", 290, 100, 20, RED);
	}

	/*for (int i = 0; i < GetScreenHeight(); i += 20)
	{
		DrawLine(0, i, GetScreenWidth(), i, RED);
		std::stringstream ss;
		ss << i;
		DrawText(ss.str().c_str(), 0, i + 2, 10, RED);
	}*/

	window->EndDrawing();
}

void Game::Close()
{
	if (window)
	delete window;
	if (player)
	delete player;
	if (grid)
	delete grid;
	if (score)
	delete score;
	for (auto& b : barriers)
	{
		delete b;
	}
	splashImage.Unload();
}
