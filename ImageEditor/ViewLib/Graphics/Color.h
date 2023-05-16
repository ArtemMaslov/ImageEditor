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
		enum Index
		{
			RedIndex   = 0,
			GreenIndex = 1,
			BlueIndex  = 2
		};

		constexpr Color() noexcept;

		constexpr Color(color_t r, color_t g, color_t b) noexcept;

		constexpr Color(const sf::Color& color) noexcept;

		union
		{
			struct 
			{
				color_t R;
				color_t G;
				color_t B;
			};
			color_t Primary[3];
		};

		void SetColor(color_t r, color_t g, color_t b) noexcept;

		operator sf::Color() const noexcept;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	constexpr Color::Color() noexcept:
		Color(0, 0, 0)
	{
	}

	constexpr Color::Color(const sf::Color& color) noexcept:
		Color(color.r, color.g, color.b)
	{
	}

	constexpr Color::Color(color_t r, color_t g, color_t b) noexcept: 
		R(r), G(g), B(b) 
	{
	}
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///