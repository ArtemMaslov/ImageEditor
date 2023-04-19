#include "PencilProperties.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

PencilProperties::PencilProperties(ViewLib::CanvasView& canvasView) :
    CanvasView(canvasView),
    Layout(ViewLib::Direction::Vertical)
{
    EnterRadius.Text.Value = "Радиус";
    EnterColor.Text.Value  = "Цвет";
    EnterRed.Text.Value    = "Красный";
    EnterBlue.Text.Value   = "Синий";
    EnterGreen.Text.Value  = "Зелёный";

    Layout.AddChild(&EnterRadius);
    Layout.AddChild(&Radius);
    Layout.AddChild(&EnterColor);
    Layout.AddChild(&EnterRed);
    Layout.AddChild(&Red);
    Layout.AddChild(&EnterGreen);
    Layout.AddChild(&Green);
    Layout.AddChild(&EnterBlue);
    Layout.AddChild(&Blue);
}

void PencilProperties::InflateProperties(ViewLib::LinearLayout& parent)
{
    parent.AddChild(&Layout);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///