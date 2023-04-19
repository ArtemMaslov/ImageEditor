#include "PropertiesMenu.h"

#include "MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

PropertiesMenu::PropertiesMenu(ImageEditor::MainWindow* const mainWindow) :
    Layout(ViewLib::Direction::Vertical),
    MainWindow(mainWindow),
    PencilProperties(mainWindow->CanvasView)
{
}

void PropertiesMenu::InflatePencilLayout()
{
    Layout.RemoveAllChildren();
    PencilProperties.InflateProperties(Layout);
}

void PropertiesMenu::ClearLayout()
{
    Layout.RemoveAllChildren();
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///