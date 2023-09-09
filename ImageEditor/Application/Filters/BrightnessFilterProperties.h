#pragma once

#include <ViewLib/View/EditText.h>

#include "../Properties/IProperties.h"
#include "ButtonsDialog.h"
#include "Filter.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class BrightnessFilterProperties : public IProperties
    {
    public:
        BrightnessFilterProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::BrightnessFilter& filter);

    private:
        void DeltaChanged();

    private:
        ImageEditor::MainWindow& MainWindow;
        ImageEditor::BrightnessFilter& Filter;
        
        ViewLib::TextView TextViewFilterName;
        
        ViewLib::TextView TextViewDelta;
        ViewLib::EditText EditTextDelta;

        ImageEditor::ButtonsDialog ButtonsDialog;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///