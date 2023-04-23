#include <cassert>

#include "PropertiesMenu.h"

#include "MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

PropertiesMenu::PropertiesMenu(ImageEditor::MainWindow& mainWindow) :
    Layout(&mainWindow.Window, ViewLib::Direction::Vertical),
    MainWindow(mainWindow)
{
}

void PropertiesMenu::InflateProperties()
{
    Layout.RemoveAllChildren();
    if (MainWindow.ToolsController.ActiveProperties)
        MainWindow.ToolsController.ActiveProperties->InflateProperties(Layout);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///