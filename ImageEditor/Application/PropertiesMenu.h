#pragma once

#include <ViewLib/ViewGroup/LinearLayout.h>
#include "ToolsProperties/IProperties.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;
    class PencilProperties;
    
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