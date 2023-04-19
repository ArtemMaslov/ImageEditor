#pragma once

#include <ViewLib/ViewGroup/LinearLayout.h>
#include "./ToolsProperties/PencilProperties.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;
    
    class PropertiesMenu
    {
    public:
        PropertiesMenu(ImageEditor::MainWindow* const mainWindow);

        void InflatePencilLayout();

        void ClearLayout();

    public:
        ViewLib::LinearLayout Layout;

    private:
        ImageEditor::MainWindow* const MainWindow;
        ImageEditor::PencilProperties PencilProperties;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///