#include <functional>

#include <ViewLib/ViewGroup/LinearLayout.h>

#include "ToolsController.h"
#include "../MainWindow.h"
#include "ToolsMenu.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ToolsMenu::ToolsMenu(ImageEditor::MainWindow& mainWindow) :
    Layout(&mainWindow.Window, ViewLib::Direction::Horizontal),
    ToolsIcons(ToolsCount, ViewLib::ImageView(&mainWindow.Window)),
    MainWindow(mainWindow)
{
    for (size_t st = 0; st < ToolsCount; st++)
    {
        ToolsIcons[st].Image.LoadFromFile(MainWindow.ToolsController.GetImagePath(ToolTypes[st]));
        ToolsIcons[st].OnMouseLeftClick += std::bind(&ImageEditor::ToolsController::ActivateNewTool, 
                                                     &MainWindow.ToolsController, ToolTypes[st]);
        ToolsIcons[st].Weight.Hor = 1;
        Layout.AddChild(&ToolsIcons[st]);
    }

    Layout.SumWeight.Hor = ToolsCount;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///