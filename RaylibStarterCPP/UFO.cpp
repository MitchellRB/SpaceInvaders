#include "UFO.h"
#include "Colour.h"

UFO::UFO()
{
}

UFO::~UFO()
{
}

void UFO::Update(Player* player)
{
	if (!m_isActive) { return; }

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
		m_isActive = false;
		bullet->SetActive(false);
	}

}

void UFO::Draw()
{
	if (!m_isActive) { return; }

	m_rect.Draw(Colour::GetColour(m_rect.y));
}
