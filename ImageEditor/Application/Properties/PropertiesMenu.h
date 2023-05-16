#pragma once

#include <ViewLib/ViewGroup/LinearLayout.h>
#include "IProperties.h"

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

        void ChangeProperties(IProperties* const newProperties);

        void RestorePreviousProperties();

    public:
        ViewLib::LinearLayout Layout;

    private:
        ImageEditor::MainWindow& MainWindow;
        IProperties* PreviousProperties = nullptr;
        IProperties* CurrentProperties  = nullptr;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///