#pragma once

#include <ViewLib/View/Button.h>
#include <ViewLib/ViewGroup/LinearLayout.h>

#include "Filter.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class ButtonsDialog
    {
    public:
        ButtonsDialog(MainWindow& mainWindow, IFilter& filter);
    
    public:
        ViewLib::LinearLayout Layout;

        ViewLib::Button ButtonCancel;
        ViewLib::Button ButtonApply;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///