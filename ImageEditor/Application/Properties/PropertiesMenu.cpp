#include <cassert>

#include "PropertiesMenu.h"

#include "../MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

PropertiesMenu::PropertiesMenu(ImageEditor::MainWindow& mainWindow) :
    Layout(&mainWindow.Window, ViewLib::Direction::Vertical),
    MainWindow(mainWindow)
{
}

void PropertiesMenu::ChangeProperties(IProperties* const newProperties)
{
    assert(newProperties);

    Layout.RemoveAllChildren();
    newProperties->InflateProperties(Layout);

    PreviousProperties = CurrentProperties;
    CurrentProperties  = newProperties;
}

void PropertiesMenu::RestorePreviousProperties()
{
    CurrentProperties = nullptr;
    ChangeProperties(PreviousProperties);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///