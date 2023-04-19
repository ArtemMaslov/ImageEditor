#include <functional>

#include <ViewLib/ViewGroup/LinearLayout.h>

#include "ToolsMenu.h"

#include "MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ToolsMenu::ToolsMenu(ImageEditor::MainWindow* const mainWindow) :
    Layout(ViewLib::Direction::Horizontal),
    Tools(),
    MainWindow(mainWindow)
{
    for (size_t st = 0; st < ToolsCount; st++)
    {
        Tools[st].Image.LoadFromFile(Images[st]);

        Tools[st].OnMouseLeftClick += std::bind(&ToolsMenu::OnImageViewLeftClick, this, ToolTypes[st]);

        Tools[st].Weight.Hor = 1;
        Layout.AddChild(&Tools[st]);
    }

    Layout.SumWeight.Hor = ToolsCount;
}

void ToolsMenu::OnImageViewLeftClick(ToolType toolType)
{
    printf("Tool %zd is activated\n", static_cast<size_t>(toolType));
    MainWindow->SetActiveTool(toolType);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///