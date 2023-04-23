#pragma once

#include <array>
#include <string>

#include <UtilLib/General.h>

#include <ViewLib/ViewGroup/LinearLayout.h>
#include <ViewLib/View/ImageView.h>

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class ToolsMenu
    {
    public:
        ToolsMenu(ImageEditor::MainWindow* const mainWindow);

    public:
        ViewLib::LinearLayout Layout;

    private:
        std::vector<ViewLib::ImageView> ToolsIcons;
        ImageEditor::MainWindow* const MainWindow;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///