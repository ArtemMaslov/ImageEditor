#pragma once

#include <UtilLib/General.h>

#include "Tool.h"
#include "PencilProperties.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class ToolsController
    {
    public:
        ToolsController(ImageEditor::MainWindow& mainWindow);

        void ActivateNewTool(ToolType newTool);

        constexpr cptr GetImagePath(ToolType toolType);

        ITool* ActiveTool;
        IProperties* ActiveProperties;
    
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

    private:
        struct ImageInfo
        {
            cptr Path;
            ImageEditor::ToolType ToolType;
        };

        static constexpr size_t ImagesCount = 6;
        static_assert(ImagesCount == ToolsCount);

        static constexpr ImageInfo Images[ImagesCount] = 
        {
            {
                "./Images/Pencil.jpg",
                ToolType::Pencil,
            },
            {
                "./Images/Bucket.jpg",
                ToolType::Bucket,
            },
            {
                "./Images/Eraser.png",
                ToolType::Eraser,
            },
            {
                "./Images/Text.jpg",
                ToolType::Text,
            },
            {
                "./Images/Rectangle.jpeg",
                ToolType::Rectangle,
            },
            {
                "./Images/Circle.png",
                ToolType::Circle,
            }
        };

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

        ImageEditor::MainWindow& MainWindow;

        ImageEditor::Pencil Pencil;
        ImageEditor::PencilProperties PencilProperties;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    constexpr cptr ToolsController::GetImagePath(ToolType toolType)
    {
        for (size_t st = 0; st < ToolsCount; st++)
        {
            if (Images[st].ToolType == toolType)
                return Images[st].Path;
        }

        assert(!"ToolType not found");
        return nullptr;
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///