#pragma once

#include <ViewLib/View/EditText.h>

#include "IProperties.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class PencilProperties : public IProperties
    {
    public:
        PencilProperties(ImageEditor::MainWindow& mainWindow);

    private:
        void RadiusChanged();

    private:
        ImageEditor::MainWindow& MainWindow;

        ViewLib::TextView EnterRadius;
        ViewLib::EditText Radius;

        ViewLib::TextView EnterColor;

        ViewLib::TextView EnterRed;
        ViewLib::EditText Red;
        ViewLib::TextView EnterGreen;
        ViewLib::EditText Green;
        ViewLib::TextView EnterBlue;
        ViewLib::EditText Blue;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///