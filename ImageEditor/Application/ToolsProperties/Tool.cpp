#include "Tool.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void Pencil::Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point)
{
    canvas.DrawCircle(point, Radius, Color);
}

void Eraser::Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point)
{
    canvas.DrawCircle(point, Radius, Color);
}

void Bucket::Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point)
{
    canvas.DrawRectangle(ViewLib::CoordType(0, 0), canvas.GetSize().Hor, canvas.GetSize().Ver, Color);
}

void Text::Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point)
{

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