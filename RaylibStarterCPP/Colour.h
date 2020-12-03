#pragma once
#include <raylib-cpp.hpp>
class Colour
{
public:
	static raylib::Color GetColour(int y)
	{
		if (y < 40)
		{
			return WHITE;
		}
		else if (y < 100)
		{
			return RED;
		}
		else if (y < 340)
		{
			return WHITE;
		}
		else
		{
			return GREEN;
		}
	}
};

