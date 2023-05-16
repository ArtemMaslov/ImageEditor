#pragma once

#include <ViewLib/View/EditText.h>

#include "../ColorPicker.h"

#include "Tool.h"
#include "IProperties.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class RectangleProperties : public IProperties
    {
    public:
        RectangleProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::Rectangle& tool);

    private:
        ImageEditor::MainWindow& MainWindow;
        ImageEditor::Rectangle& Tool;

        ViewLib::TextView TextViewToolName;
        ViewLib::TextView TextViewWidth;
        ViewLib::EditText EditTextWidth;
        ViewLib::TextView TextViewHeight;
        ViewLib::EditText EditTextHeight;

        ViewLib::ColorPicker ColorPicker;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///