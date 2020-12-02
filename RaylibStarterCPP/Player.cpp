#include "Player.h"

Player::Player()
{
	m_height = 0;
	m_leftBound = 0;
	m_rightBound = 0;
	m_position = 0;
}

Player::~Player()
{
	delete m_bullet;
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
}

void Player::Draw()
{
	m_offsetRect.Draw(Colour::GetColour(GetScreenHeight() - m_height));
	m_bullet->Draw();
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
