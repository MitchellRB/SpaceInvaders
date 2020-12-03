#include "Player.h"
#include <sstream>

Player::Player()
{
	m_height = 0;
	m_leftBound = 0;
	m_rightBound = 0;
	m_position = 0;
	m_lives = 3;
}

Player::~Player()
{
	if (m_bullet)
	delete m_bullet;
	if (m_sprite)
	delete m_sprite;
}

void Player::Init()
{
	m_position = GetScreenWidth() / 2;
	m_bullet = new Bullet(-8);
}

void Player::Update()
{
	// Player input
	if (IsKeyDown(KEY_A) && m_position > m_leftBound)
	{
		m_position -= moveSpeed;
	}

	if (IsKeyDown(KEY_D) && m_position < GetScreenWidth() - m_rightBound)
	{
		m_position += moveSpeed;
	}

	if (IsKeyPressed(KEY_SPACE) && m_bullet->GetActive() == false)
	{
		m_bullet->SetActive(true);
		m_bullet->SetPosition(rl::Vector2(m_position, GetScreenHeight() - m_height - 15));

	}

	// Offset rectangle for drawing
	m_offsetRect = m_rect;
	m_offsetRect.x += m_position;
	m_offsetRect.y += GetScreenHeight() - m_height;

	// Update bullet
	m_bullet->Update();

	// Enemy bullet collisions
	for (auto& bullet : *m_enemyBullets)
	{
		if (bullet->GetActive() == true && m_offsetRect.CheckCollision(bullet->GetPosition()))
		{
			Kill();
			bullet->SetActive(false);
		}
	}
}

void Player::Draw()
{
	m_sprite->Draw(m_offsetRect.x, m_offsetRect.y, Colour::GetColour(GetScreenHeight() - m_height));
	m_bullet->Draw();
	std::stringstream ss;
	ss << m_lives;
	DrawText(ss.str().c_str(), 15, GetScreenHeight() - 20, 14, WHITE);
	for (int i = 1; i < m_lives; i++)
	{
		m_sprite->Draw(25 + 25 * i, GetScreenHeight() - 20, GREEN);
	}
}

void Player::SetBounds(int left, int right)
{
	m_leftBound = left;
	m_rightBound = right;
}

void Player::SetHeight(int height)
{
	m_height = height;
}

void Player::SetRect(rl::Rectangle rect)
{
	m_rect = rect;
}

Bullet* Player::getBullet()
{
	return m_bullet;
}

void Player::SetSprite(const char* filename)
{
	m_sprite = new rl::Texture2D(filename);
}
