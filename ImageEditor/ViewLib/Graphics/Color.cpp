#include <UtilLib/General.h>

#include "Color.h"

using namespace ViewLib;

static_assert(MAX_COLOR_VALUE == 255);

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

const Color& Color::operator += (int delta) noexcept
{
	int newR = static_cast<int>(R) + delta;
	int newG = static_cast<int>(G) + delta;
	int newB = static_cast<int>(B) + delta;
	
	if (newR < 0)
		newR = 0;
	if (newG < 0)
		newG = 0;
	if (newB < 0)
		newB = 0;

	if (newR > MAX_COLOR_VALUE)
		newR = MAX_COLOR_VALUE;
	if (newG > MAX_COLOR_VALUE)
		newG = MAX_COLOR_VALUE;
	if (newB > MAX_COLOR_VALUE)
		newB = MAX_COLOR_VALUE;

	R = static_cast<color_t>(newR);
	G = static_cast<color_t>(newG);
	B = static_cast<color_t>(newB);

	return *this;
}

void Color::SetColor(color_t r, color_t g, color_t b) noexcept
{
	R = r;
	G = g;
	B = b;
}

Color::operator sf::Color() const noexcept
{
	return sf::Color(R, G, B);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///