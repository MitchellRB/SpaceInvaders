#pragma once
#include "raylib-cpp.hpp"
class Colour
{
public:
	static raylib::Color GetColour(int height)
	{
		if (height < 80)
		{
			return RED;
		}
		else if (height < 300)
		{
			return WHITE;
		}
		else
		{
			return GREEN;
		}
	}
};

