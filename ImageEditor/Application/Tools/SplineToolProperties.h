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

    class SplineToolProperties : public IProperties
    {
    public:
        SplineToolProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::SplineTool& tool, cptr toolName);

    private:
        void RadiusChanged();

    private:
        ImageEditor::MainWindow& MainWindow;
        ImageEditor::SplineTool& Tool;

        ViewLib::TextView TextViewToolName;
        ViewLib::TextView TextViewRadius;
        ViewLib::EditText EditTextRadius;

        ViewLib::ColorPicker ColorPicker;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///