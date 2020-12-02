#pragma once
#include "raylib-cpp.hpp"
class Colour
{
public:
	static raylib::Color GetColour(int height)
	{
		if (height < 50)
		{
			return WHITE;
		}
		else if (height < 100)
		{
			return RED;
		}
		else if (height < 340)
		{
			return WHITE;
		}
		else
		{
			return GREEN;
		}
	}
};

