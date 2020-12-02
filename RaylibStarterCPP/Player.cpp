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

}

void Player::Update()
{

}

void Player::Draw()
{

}

void Player::SetBounds(int left, int right)
{
	m_leftBound = left;
	m_rightBound = right;
}

void Player::SetHeight(int h)
{
	m_height = h;
}