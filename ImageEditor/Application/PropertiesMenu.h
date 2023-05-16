#pragma once

#include <ViewLib/ViewGroup/LinearLayout.h>
#include "Tools/IProperties.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;
    class SplineToolProperties;
    
    class PropertiesMenu
    {
    public:
        PropertiesMenu(ImageEditor::MainWindow& mainWindow);

        void InflateProperties();

    public:
        ViewLib::LinearLayout Layout;

    private:
        ImageEditor::MainWindow& MainWindow;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///