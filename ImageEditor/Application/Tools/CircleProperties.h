#pragma once

#include <ViewLib/View/EditText.h>

#include "../ColorPicker.h"

#include "Tool.h"
#include "../Properties/IProperties.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class CircleProperties : public IProperties
    {
    public:
        CircleProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::Circle& tool);

    private:
        void RadiusChanged();

    private:
        ImageEditor::MainWindow& MainWindow;
        ImageEditor::Circle& Tool;
        
        ViewLib::TextView TextViewToolName;
        ViewLib::TextView TextViewRadius;
        ViewLib::EditText EditTextRadius;

        ViewLib::ColorPicker ColorPicker;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///