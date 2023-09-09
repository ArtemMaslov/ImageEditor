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

    class TextProperties : public IProperties
    {
    public:
        TextProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::Text& tool);

    private:
        void StringChanged();

        void FontSizeChanged();

    private:
        ImageEditor::MainWindow& MainWindow;
        ImageEditor::Text& Tool;

        ViewLib::TextView TextViewToolName;
        ViewLib::TextView TextViewFontSize;
        ViewLib::EditText EditTextFontSize;
        ViewLib::TextView TextViewString;
        ViewLib::EditText EditTextString;

        ViewLib::ColorPicker ColorPicker;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///