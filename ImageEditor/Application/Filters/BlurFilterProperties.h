#pragma once

#include <ViewLib/View/EditText.h>
#include <ViewLib/View/Button.h>
#include <ViewLib/ViewGroup/LinearLayout.h>

#include "../Properties/IProperties.h"
#include "ButtonsDialog.h"
#include "Filter.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class BlurFilterProperties : public IProperties
    {
    public:
        BlurFilterProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::BlurFilter& filter);

    private:
        void SquareSizeChanged();

    private:
        ImageEditor::MainWindow& MainWindow;
        ImageEditor::BlurFilter& Filter;
        
        ViewLib::TextView TextViewFilterName;
        
        ViewLib::TextView TextViewSquareSize;
        ViewLib::EditText EditTextSquareSize;

        ImageEditor::ButtonsDialog ButtonsDialog;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///