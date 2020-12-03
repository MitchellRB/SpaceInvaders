#include "EnemyGrid.h"
EnemyGrid::EnemyGrid()
{
	m_updatePosition = -1;
	m_speed = 5;
	m_moveDownStaged = false;
	m_player = nullptr;
	m_secret = nullptr;
	m_activeEnemies = 0;
	m_lowestActive = 0;
	m_waitTime = 0;
	m_secretTimer = 0;
}

EnemyGrid::~EnemyGrid()
{
	for (auto& e : m_grid)
	{
		delete e;
	}

	for (auto& s : m_enemySprites)
	{
		delete s;
	}

	delete m_secret;
}

void EnemyGrid::Init()
{	
	LoadSprites();

	SetupGrid();

	SetupUFO();
}

void EnemyGrid::SetupGrid()
{
	// Create enemies
	Enemy* newEnemy;
	for (int i = 0; i < gridHeight; i++)
	{
		for (int k = gridWidth; k > 0; k--)
		{
			newEnemy = new Enemy(this);
			newEnemy->SetRect(rl::Rectangle{ (float)(k * 30) + 50, (float)(i * 30) + 120, 20, 10 });
			newEnemy->SetScore(m_score);

			// Set sprite pair
			switch (i % 5)
			{
			case 0:
				newEnemy->SetSprites(m_enemySprites[4], m_enemySprites[5]);
				newEnemy->SetValue(50);
				break;
			case 1:
			case 2:
				newEnemy->SetSprites(m_enemySprites[2], m_enemySprites[3]);
				newEnemy->SetValue(30);
				break;
			case 3:
			case 4:
				newEnemy->SetSprites(m_enemySprites[0], m_enemySprites[1]);
				newEnemy->SetValue(10);
				break;
			default:
				break;
			}
			m_grid.push_back(newEnemy);
			m_activeEnemies++;
		}
	}

}

void EnemyGrid::SetupUFO()
{
	m_secret = new UFO();
	m_secret->SetRect(secretSpawn);
	m_secret->SetActive(false);
	m_secretTimer = GetRandomValue(60, 600);
	m_secret->SetSprite("../Resources/UFO.png");
	m_secret->SetScore(m_score);
	m_secret->SetValue(200);
}

void EnemyGrid::Update()
{
	// Stop if no enemies remain
	if (m_activeEnemies == 0)
	{
		return;
	}

	if (m_waitTime > 0)
	{
		m_waitTime--;
	}
	else
	{
		// Move down
		if (m_moveDownStaged && m_updatePosition <= m_lowestActive)
		{
			MoveDown();
			return;
		}

		// Go to the next active enemy
		do
		{
			if (m_updatePosition <= m_lowestActive)
			{
				m_updatePosition = m_grid.size();
			}
			m_updatePosition--;
		} while (m_grid[m_updatePosition]->GetActive() == false);

		// Move sideways
		bool reverse = m_grid[m_updatePosition]->Move(m_speed);
		if (reverse)
		{
			m_moveDownStaged = true;
		}
		if (m_updatePosition == m_lowestActive)
		{
			m_waitTime = 0;
		}
	}

	for (auto& e : m_grid)
	{
		e->Update(m_player);
		if (e->TooLow())
		{
			m_player->Kill();
			m_activeEnemies = 0;
			break;
		}
		if (m_activeEnemies == 0)
		{
			break;
		}
	}

	// Spawn UFO
	if (m_secretTimer > 0 && m_secret->GetActive() == false && m_activeEnemies > 8)
	{
		m_secretTimer--;
	}
	else if (m_secretTimer == 0 && m_secret->GetActive() == false && m_activeEnemies > 8)
	{
		m_secret->SetActive(true);
		m_secret->SetRect(secretSpawn);
		m_secretTimer = GetRandomValue(60, 600);
	}

	// Move UFO
	m_secret->Update(m_player);
}

void EnemyGrid::MoveDown()
{
	for (auto& e : m_grid)
	{
		e->GetRect().y += 20;
	}
	m_moveDownStaged = false;
	m_speed *= -1;
}

void EnemyGrid::SetPlayer(Player* player)
{
	m_player = player;
}

void EnemyGrid::EnemyDeath()
{
	m_activeEnemies--;

	if (m_activeEnemies == 0)
	{
		return;
	}

	while (m_grid[m_lowestActive]->GetActive() == false)
	{
		m_lowestActive++;
	}
}

void EnemyGrid::LoadSprites()
{	for (auto& s : filenames)
	{
		rl::Texture2D* sprite = new rl::Texture2D(s);
		m_enemySprites.push_back(sprite);
	}
}

void EnemyGrid::Draw()
{
	for (auto& e : m_grid)
	{
		e->Draw();
	}
	m_secret->Draw();
}
