#pragma once

#include <cassert>

#include <SFML/Graphics.hpp>

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	typedef int       dim_t;
	typedef const int cdim_t;

	enum class Direction
	{
		Horizontal,
		Vertical
	};

	inline Direction operator ! (const Direction direction);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	Direction operator ! (const Direction direction)
	{
		switch (direction)
		{
			case Direction::Horizontal:
				return Direction::Vertical;

			case Direction::Vertical:
				return Direction::Horizontal;

			default:
				assert(!"Not implemented");
		}
	}
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///