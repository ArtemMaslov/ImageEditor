#include <cassert>

#include "FiltersController.h"

#include "../MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

FiltersController::FiltersController(ImageEditor::MainWindow& mainWindow) :
    MainWindow(mainWindow),

    BrightnessFilter(10),
    BrightnessFilterProperties(mainWindow, BrightnessFilter),

    BlurFilter(5),
    BlurFilterProperties(mainWindow, BlurFilter)
{
}

void FiltersController::ActivateFilterDialog(FilterType newFilter)
{
    IProperties* newProperties = nullptr;
    switch (newFilter)
    {
        case FilterType::Brightness:
            newProperties = &BrightnessFilterProperties;
            break;

        case FilterType::Blur:
            newProperties = &BlurFilterProperties;
            break;

        default:
            assert(!"Not implemented");
            break;
    }
    
    MainWindow.PropertiesMenu.ChangeProperties(newProperties);

	MainWindow.Window.MeasureChildren();
	MainWindow.Window.LayoutChildren();
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///