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

    public:
        ViewLib::LinearLayout Layout;

    private:
        ImageEditor::MainWindow& MainWindow;

        ViewLib::Button ButtonOpenFile;
        ViewLib::Button ButtonSaveFile;
        ViewLib::Button ButtonBrightnessFilter;
        ViewLib::Button ButtonBlurFilter;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///