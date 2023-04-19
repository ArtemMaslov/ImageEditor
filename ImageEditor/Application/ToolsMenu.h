#pragma once

#include <array>
#include <string>

#include <UtilLib/General.h>

#include <ViewLib/ViewGroup/LinearLayout.h>
#include <ViewLib/View/ImageView.h>

#include "CanvasView.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class ToolsMenu
    {
    public:
        ToolsMenu(ImageEditor::MainWindow* const mainWindow);
    
    private:
        void OnImageViewLeftClick(ToolType toolType);

    public:
        ViewLib::LinearLayout Layout;

    private:
        static constexpr size_t ToolsCount = 6;
        static constexpr std::array<cptr, ToolsCount> Images = 
        {
            "./Images/Pencil.jpg",
            "./Images/Bucket.jpg",
            "./Images/Eraser.png",
            "./Images/Text.jpg",
            "./Images/Rectangle.jpeg",
            "./Images/Circle.png"
        };

        static constexpr std::array<ToolType, ToolsCount> ToolTypes =
        {
            ToolType::Pencil,
            ToolType::Bucket,
            ToolType::Eraser,
            ToolType::Text,
            ToolType::Rectangle,
            ToolType::Circle
        };

        std::array<ViewLib::ImageView, ToolsCount> Tools;
        ImageEditor::MainWindow* const MainWindow;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///