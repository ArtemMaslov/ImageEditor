#include "Tool.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

SplineTool::SplineTool(uint_t defaultRadius, const ViewLib::Color& defaultColor) :
    Radius(defaultRadius),
    Color(defaultColor)
{
}

Bucket::Bucket(const ViewLib::Color& defaultColor) :
    Color(defaultColor)
{
}

Text::Text(const ViewLib::Color& defaultColor) :
    Color(defaultColor)
{
}

Rectangle::Rectangle(const ViewLib::SizeType& defaultSize, const ViewLib::Color& defaultColor) :
    Size(defaultSize),
    Color(defaultColor)
{
}

Circle::Circle(uint_t defaultRadius, const ViewLib::Color& defaultColor) :
    Radius(defaultRadius),
    Color(defaultColor)
{
}

void SplineTool::Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point)
{
    canvas.DrawCircle(point, Radius, Color);
}

void Bucket::Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point)
{
    canvas.DrawRectangle(ViewLib::CoordType(0, 0), canvas.GetSize().Hor, canvas.GetSize().Ver, Color);
}

void Text::Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point)
{
    Value.SetPosition(point);
    Value.SetColor(Color);
    canvas.Render(Value);
}

void Rectangle::Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point)
{
    canvas.DrawRectangle(point, Size.Hor, Size.Ver, Color);
}

void Circle::Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point)
{
    canvas.DrawCircle(point, Radius, Color);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///