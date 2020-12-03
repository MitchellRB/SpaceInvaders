#include "Score.h"
#include <sstream>
#include "Colour.h"

Score::Score()
{
	m_playerScore = 0;
	m_highScore = 0;
}

Score::~Score()
{

}

void Score::AddScore(int value)
{
	m_playerScore += value;
	if (m_playerScore > m_highScore)
	{
		m_highScore = m_playerScore;
	}
}

void Score::Draw()
{
	std::stringstream ss;
	ss << m_playerScore;
	DrawText("SCORE", 100, 10, 20, Colour::GetColour(20));
	DrawText(ss.str().c_str(), 120, 30, 20, Colour::GetColour(30));
	ss.str(std::string());
	ss << m_highScore;
	DrawText("HISCORE", 300, 10, 20, Colour::GetColour(20));
	DrawText(ss.str().c_str(), 320, 30, 20, Colour::GetColour(30));
}