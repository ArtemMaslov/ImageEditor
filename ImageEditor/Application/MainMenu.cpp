#include <UtilLib/FileSystem/FileDialog.h>
#include <UtilLib/FileSystem/Files.h>

#include "MainMenu.h"

#include "MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

MainMenu::MainMenu(ImageEditor::MainWindow& mainWindow) :
    Layout(&mainWindow.Window, ViewLib::Direction::Horizontal),
    MainWindow(mainWindow),

    ButtonOpenFile(&mainWindow.Window),
    ButtonSaveFile(&mainWindow.Window),
    ButtonFilters(&mainWindow.Window)
{
    ButtonOpenFile.Text.Value = "Открыть файл";
    ButtonSaveFile.Text.Value = "Сохранить файл";
    ButtonFilters.Text.Value  = "Фильтры";

    Layout.AddChild(&ButtonOpenFile);
    Layout.AddChild(&ButtonSaveFile);
    Layout.AddChild(&ButtonFilters);

    ButtonOpenFile.OnMouseLeftClick += std::bind(&MainMenu::ButtonOpenFileClicked, this);
    ButtonSaveFile.OnMouseLeftClick += std::bind(&MainMenu::ButtonSaveFileClicked, this);
    ButtonFilters.OnMouseLeftClick  += std::bind(&MainMenu::ButtonFiltersClicked, this);
}

void MainMenu::ButtonOpenFileClicked()
{
    const size_t bufferSize = 1024;
    char filePath[bufferSize] = "";
    UtilLib::OpenFileDialog(filePath, bufferSize);
    
    ViewLib::Image image;
    image.LoadFromFile(filePath);
    MainWindow.CanvasView.LoadImage(image);
}

void MainMenu::ButtonSaveFileClicked()
{
    const size_t bufferSize = 1024;
    char filePath[bufferSize] = "";
    UtilLib::SaveFileDialog(filePath, bufferSize);

    const sf::Texture& texture = MainWindow.CanvasView.GetTexture();
    sf::Image image = texture.copyToImage();
    image.saveToFile(filePath);
}

void MainMenu::ButtonFiltersClicked()
{
    
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///