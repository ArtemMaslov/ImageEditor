#include <functional>

#include "SplineToolProperties.h"
#include "../MainWindow.h"

using namespace ImageEditor;
using ConversionError = UtilLib::Utf8String::ConversionError;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

SplineToolProperties::SplineToolProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::SplineTool& tool, cptr toolName) :
    IProperties(&mainWindow.Window),
    MainWindow(mainWindow),
    Tool(tool),

    TextViewToolName(&mainWindow.Window),
    TextViewRadius(&mainWindow.Window),
    EditTextRadius(&mainWindow.Window),
    
    ColorPicker(&mainWindow.Window, tool.Color)
{
    TextViewToolName.Text.Value = toolName;
    TextViewRadius.Text.Value   = "Радиус:";
    EditTextRadius.Text.Value   = UtilLib::Utf8String(std::to_string(Tool.Radius));

    Layout.AddChild(&TextViewToolName);
    Layout.AddChild(&TextViewRadius);
    Layout.AddChild(&EditTextRadius);
    Layout.AddChild(&ColorPicker.Layout);

    EditTextRadius.OnTextChanged += std::bind(&SplineToolProperties::RadiusChanged, this);
}

void SplineToolProperties::RadiusChanged()
{
    int64_t newRadius = 0;
    if (EditTextRadius.Text.Value.ToInt(newRadius) == ConversionError::NoErrors && newRadius > 0)
        Tool.Radius = newRadius;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///