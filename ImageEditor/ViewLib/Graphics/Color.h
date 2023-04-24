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

		Color() noexcept;

		Color(color_t r, color_t g, color_t b) noexcept;

		Color(const sf::Color& color) noexcept;

		union
		{
			struct 
			{
				color_t R;
				color_t G;
				color_t B;
			};
			color_t Colors[3];
		};

		void SetColor(color_t r, color_t g, color_t b) noexcept;

		operator sf::Color() const noexcept;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///