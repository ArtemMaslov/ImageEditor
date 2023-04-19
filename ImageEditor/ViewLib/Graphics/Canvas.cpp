#include <cassert>
#include <cmath>

#include "Canvas.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

CanvasType::CanvasType() : 
	Texture()
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///


void CanvasType::DrawLine(const CoordType& p1, const CoordType& p2, const Color& color)
{
	sf::Vertex line[] =
	{
		sf::Vertex(p1),
		sf::Vertex(p2)
	};
	line[0].color = color;
	line[1].color = color;

	Texture.draw(line, 2, sf::Lines);
	Texture.display();
}

void CanvasType::DrawCircle(CoordType center, cuint_t radius, const Color& color, 
						  cuint_t pointsCount)
{
	sf::CircleShape circle(radius, pointsCount);
	circle.setFillColor(color);
	center.Hor -= radius;
	center.Ver -= radius;
	circle.setPosition(center);

	Texture.draw(circle);
	Texture.display();
}

void CanvasType::DrawRectangle(const CoordType& leftTop, cint_t width, cint_t height, const Color& color)
{
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setFillColor(color);
	rectangle.setPosition(leftTop);

	Texture.draw(rectangle);
	Texture.display();
}

void CanvasType::DrawPoint(const CoordType& point, const Color& color)
{
	sf::Vertex drawingPoint(point, color);
	Texture.draw(&drawingPoint, 1, sf::Points);
	Texture.display();
}

void CanvasType::Clear()
{
	Texture.clear(sf::Color(255, 255, 255));
}

void CanvasType::Render(sf::RenderTarget& target)
{
	sf::Sprite sprite(Texture.getTexture());
	sprite.setPosition(Pos.Hor, Pos.Ver);
	target.draw(sprite);
}

void CanvasType::Render(IRender& drawable)
{
	drawable.Render(Texture);
	Texture.display();
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///