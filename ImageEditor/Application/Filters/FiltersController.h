#pragma once

#include "Filter.h"
#include "BrightnessFilterProperties.h"
#include "BlurFilterProperties.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class FiltersController
    {
    public:
        FiltersController(ImageEditor::MainWindow& mainWindow);

        void ActivateFilterDialog(FilterType newFilter);

    private:
        ImageEditor::MainWindow& MainWindow;

        ImageEditor::BrightnessFilter BrightnessFilter;
        ImageEditor::BrightnessFilterProperties BrightnessFilterProperties;

        ImageEditor::BlurFilter BlurFilter;
        ImageEditor::BlurFilterProperties BlurFilterProperties;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///