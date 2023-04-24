#include "ToolsController.h"

#include "../MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ToolsController::ToolsController(ImageEditor::MainWindow& mainWindow) :
    MainWindow(mainWindow),
    Pencil(10, ViewLib::Color{0, 0, 0}),
    PencilProperties(mainWindow, Pencil, "Карандаш"),
    Eraser(50, ViewLib::Color{255, 255, 255}),
    EraserProperties(mainWindow, Eraser, "Ластик"),
    Bucket(ViewLib::Color{255, 255, 255}),
    BucketProperties(mainWindow, Bucket)
{
}

void ToolsController::ActivateNewTool(ToolType newTool)
{
    switch (newTool)
    {
        case ToolType::Pencil:
            ActiveTool       = &Pencil;
            ActiveProperties = &PencilProperties;
            break;
            
        case ToolType::Eraser:
            ActiveTool       = &Eraser;
            ActiveProperties = &EraserProperties;
            break;
            
        case ToolType::Bucket:
            ActiveTool       = &Bucket;
            ActiveProperties = &BucketProperties;
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