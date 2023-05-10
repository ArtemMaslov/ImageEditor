#pragma once 

#include <ViewLib/ViewGroup/LinearLayout.h>
#include <ViewLib/View/Button.h>

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class MainMenu
    {
    public:
        MainMenu(ImageEditor::MainWindow& mainWindow);

    private:
        void ButtonOpenFileClicked();
        
        void ButtonSaveFileClicked();

        void ButtonFiltersClicked();

    public:
        ViewLib::LinearLayout Layout;

    private:
        ImageEditor::MainWindow& MainWindow;

        ViewLib::Button ButtonOpenFile;
        ViewLib::Button ButtonSaveFile;
        ViewLib::Button ButtonFilters;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///