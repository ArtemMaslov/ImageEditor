#include <UtilLib/FileSystem/FileDialog.h>
#include <UtilLib/FileSystem/Files.h>

#include "MainMenu.h"
#include "Filters/FiltersController.h"
#include "MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

MainMenu::MainMenu(ImageEditor::MainWindow& mainWindow) :
    Layout(&mainWindow.Window, ViewLib::Direction::Horizontal),
    MainWindow(mainWindow),

    ButtonOpenFile(&mainWindow.Window),
    ButtonSaveFile(&mainWindow.Window),
    ButtonBrightnessFilter(&mainWindow.Window),
    ButtonBlurFilter(&mainWindow.Window)
{
    ButtonOpenFile.Text.Value         = "Открыть файл";
    ButtonSaveFile.Text.Value         = "Сохранить файл";
    ButtonBrightnessFilter.Text.Value = "Фильтр яркости";
    ButtonBlurFilter.Text.Value       = "Фильтр размытия";

    Layout.AddChild(&ButtonOpenFile);
    Layout.AddChild(&ButtonSaveFile);
    Layout.AddChild(&ButtonBrightnessFilter);
    Layout.AddChild(&ButtonBlurFilter);

    ButtonOpenFile.OnMouseLeftClick += std::bind(&MainMenu::ButtonOpenFileClicked, this);
    ButtonSaveFile.OnMouseLeftClick += std::bind(&MainMenu::ButtonSaveFileClicked, this);

    ButtonBrightnessFilter.OnMouseLeftClick += std::bind(&FiltersController::ActivateFilterDialog, 
        &MainWindow.FiltersController, FilterType::Brightness);

    ButtonBlurFilter.OnMouseLeftClick       += std::bind(&FiltersController::ActivateFilterDialog, 
        &MainWindow.FiltersController, FilterType::Blur);
}

void MainMenu::ButtonOpenFileClicked()
{
    const size_t bufferSize = 1024;
    char filePath[bufferSize] = "";
    UtilLib::OpenFileDialog(filePath, bufferSize);
    
    if (filePath[0] != '\0')
    {
        ViewLib::Image image;
        image.LoadFromFile(filePath);
        MainWindow.CanvasView.LoadImage(image);
    }
}

void MainMenu::ButtonSaveFileClicked()
{
    const size_t bufferSize = 1024;
    char filePath[bufferSize] = "";
    UtilLib::SaveFileDialog(filePath, bufferSize);

    if (filePath[0] != '\0')
    {
        const sf::Texture& texture = MainWindow.CanvasView.GetTexture();
        sf::Image image = texture.copyToImage();
        image.saveToFile(filePath);
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///