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
}

void Game::StopGame()
{
	delete player;
	delete grid;
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
		else if (player->GetLives() == 0)
		{
			gameState = State::GameOver;
			StopGame();
		}
	}
	else if (gameState == State::GameOver)
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			//StopGame();
			gameState = State::Menu;
			return;
		}
	}

	DrawFPS(0, 0);
}

void Game::Draw()
{
	window->BeginDrawing();

	bgColour.ClearBackground();

	if (gameState == State::Menu)
	{
		DrawText("Press ENTER to play", 130, 200, 30, Colour::GetColour(300));
	}
	else if (gameState == State::Play)
	{
		player->Draw();

		grid->Draw();

		score->Draw();
	}
	else if (gameState == State::GameOver)
	{
		DrawText("Game over", 200, 200, 10, RED);
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
}
