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

    class BucketProperties : public IProperties
    {
    public:
        BucketProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::Bucket& tool);

    private:
        ImageEditor::MainWindow& MainWindow;
        ImageEditor::Bucket& Tool;
        
        ViewLib::TextView TextViewToolName;
        
        ViewLib::ColorPicker ColorPicker;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///