#pragma once

#include <SFML/Graphics.hpp>

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	typedef unsigned char color_t;

	struct Color
	{
	public:
		Color() noexcept;

		Color(color_t r, color_t g, color_t b) noexcept;

		Color(const sf::Color& color) noexcept;

		color_t R;
		color_t G;
		color_t B;

		void SetColor(color_t r, color_t g, color_t b) noexcept;

		operator sf::Color() const noexcept;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///