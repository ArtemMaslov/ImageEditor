#include "CircleProperties.h"

#include "../MainWindow.h"

using namespace ImageEditor;
using ConversionError = UtilLib::Utf8String::ConversionError;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

CircleProperties::CircleProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::Circle& tool) :
    IProperties(&mainWindow.Window),
    MainWindow(mainWindow),

    Tool(tool),

    ColorPicker(&mainWindow.Window, tool.Color)
{
    TextViewToolName.Text.Value = "Круг";
    TextViewRadius.Text.Value   = "Радиус";
    EditTextRadius.Text.Value   = UtilLib::Utf8String(std::to_string(tool.Radius));

    Layout.AddChild(&TextViewToolName);
    Layout.AddChild(&TextViewRadius);
    Layout.AddChild(&EditTextRadius);
    Layout.AddChild(&ColorPicker.GetLayout());

    EditTextRadius.OnTextChanged += std::bind(&CircleProperties::RadiusChanged, this);
}

void CircleProperties::RadiusChanged()
{
    int64_t newRadius = 0;
    if (EditTextRadius.Text.Value.ToInt(newRadius) == ConversionError::NoErrors && newRadius > 0)
        Tool.Radius = newRadius;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///