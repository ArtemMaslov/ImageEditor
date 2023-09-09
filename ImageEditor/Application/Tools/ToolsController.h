#pragma once

#include <UtilLib/General.h>

#include "Tool.h"
#include "SplineToolProperties.h"
#include "BucketProperties.h"
#include "TextProperties.h"
#include "RectangleProperties.h"
#include "CircleProperties.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class MainWindow;

    class ToolsController
    {
        friend class SplineToolProperties;
    public:
        ToolsController(ImageEditor::MainWindow& mainWindow);

        void ActivateNewTool(ToolType newTool);

        constexpr const char* GetImagePath(ToolType toolType);

        ITool* ActiveTool;
    
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
                "./Images/pen-color-c.png",
                ToolType::Pencil,
            },
            {
                "./Images/bucket-color-c.png",
                ToolType::Bucket,
            },
            {
                "./Images/eraser-color-c.png",
                ToolType::Eraser,
            },
            {
                "./Images/text-color-c.png",
                ToolType::Text,
            },
            {
                "./Images/rectangle-color-c.png",
                ToolType::Rectangle,
            },
            {
                "./Images/circle-color-c.png",
                ToolType::Circle,
            }
        };

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

        ImageEditor::MainWindow& MainWindow;

        ImageEditor::SplineTool Pencil;
        ImageEditor::SplineToolProperties PencilProperties;

        ImageEditor::SplineTool Eraser;
        ImageEditor::SplineToolProperties EraserProperties;

        ImageEditor::Bucket Bucket;
        ImageEditor::BucketProperties BucketProperties;
        
        ImageEditor::Text Text;
        ImageEditor::TextProperties TextProperties;

        ImageEditor::Rectangle Rectangle;
        ImageEditor::RectangleProperties RectangleProperties;

        ImageEditor::Circle Circle;
        ImageEditor::CircleProperties CircleProperties;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    constexpr const char* ToolsController::GetImagePath(ToolType toolType)
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