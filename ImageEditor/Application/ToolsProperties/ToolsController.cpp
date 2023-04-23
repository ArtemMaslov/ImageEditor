#include "ToolsController.h"

#include "../MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ToolsController::ToolsController(ImageEditor::MainWindow& mainWindow) :
    MainWindow(mainWindow),
    Pencil(),
    PencilProperties(mainWindow)
{
}

void ToolsController::ActivateNewTool(ToolType newTool)
{
    switch (newTool)
    {
        case ToolType::Pencil:
            ActiveTool = &Pencil;
            ActiveProperties = &PencilProperties;
            break;
            
        case ToolType::Eraser:
            break;
            
        case ToolType::Bucket:
            break;
            
        case ToolType::Text:
            ActiveTool = nullptr;
            ActiveProperties = nullptr;
            break;
            
        case ToolType::Rectangle:
            break;
            
        case ToolType::Circle:
            break;
    
        default:
            assert(!"Not implemented");
            break;
    }

    MainWindow.PropertiesMenu.InflateProperties();

	MainWindow.Window.MeasureChildren();
	MainWindow.Window.LayoutChildren();
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///