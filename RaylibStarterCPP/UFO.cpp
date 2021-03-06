#include "UFO.h"
#include "Colour.h"

UFO::UFO()
{

}

UFO::~UFO()
{
	m_sprite.Unload();
	m_deathSprite.Unload();
}

void UFO::Update(Player* player)
{
	if (!m_isActive)
	{
		if (m_deathTimer > 0)
			m_deathTimer--;
		return;
	}

	if (m_rect.x < GetScreenWidth() + 20)
	{
		m_rect.x += 1;
	}
	else
	{
		m_isActive = false;
		return;
	}

	if (!player) { return; }

	auto bullet = player->getBullet();
	if (bullet->GetActive() == true && m_rect.CheckCollision(bullet->GetPosition()))
	{
		m_score->AddScore(m_value);
		m_isActive = false;
		bullet->SetActive(false);
		m_deathTimer = 20;
	}

}

void UFO::Draw()
{
	if (!m_isActive && m_deathTimer > 0)
	{
		m_deathSprite.Draw(m_rect.x + 5, m_rect.y, Colour::GetColour(m_rect.y));
	}
	else if (m_isActive)
	{
		m_sprite.Draw(m_rect.x, m_rect.y, Colour::GetColour(m_rect.y));
	}
}

void UFO::SetSprites(const char* normal, const char* death)
{
	m_sprite.Load(normal);
	m_deathSprite.Load(death);
}
