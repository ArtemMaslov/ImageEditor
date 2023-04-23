#include <functional>

#include "PencilProperties.h"
#include "../MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

PencilProperties::PencilProperties(ImageEditor::MainWindow& mainWindow) :
    IProperties(&mainWindow.Window),
    MainWindow(mainWindow),

    EnterRadius(&mainWindow.Window),
    Radius(&mainWindow.Window),

    EnterColor(&mainWindow.Window),

    EnterRed(&mainWindow.Window),
    Red(&mainWindow.Window),
    EnterGreen(&mainWindow.Window),
    Green(&mainWindow.Window),
    EnterBlue(&mainWindow.Window),
    Blue(&mainWindow.Window)
{
    EnterRadius.Text.Value = "Радиус:";
    EnterColor.Text.Value  = "Цвет";
    EnterRed.Text.Value    = "Красный [0-255]:";
    EnterBlue.Text.Value   = "Синий [0-255]:";
    EnterGreen.Text.Value  = "Зелёный [0-255]:";

    Layout.AddChild(&EnterRadius);
    Layout.AddChild(&Radius);
    Layout.AddChild(&EnterColor);
    Layout.AddChild(&EnterRed);
    Layout.AddChild(&Red);
    Layout.AddChild(&EnterGreen);
    Layout.AddChild(&Green);
    Layout.AddChild(&EnterBlue);
    Layout.AddChild(&Blue);

    Radius.OnTextChanged += std::bind(&PencilProperties::RadiusChanged, this);
}

void PencilProperties::RadiusChanged()
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///