#pragma once

#include <UtilLib/Text/Utf8String.h>

#include <ViewLib/SizePair.h>
#include <ViewLib/Graphics/Color.h>
#include <ViewLib/Graphics/Canvas.h>

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    enum class ToolType
    {
        Pencil,
        Eraser,
        Bucket,
        Text,
        Rectangle,
        Circle,
        /// Общее количество инструментов.
        ToolsCount
    };

    constexpr size_t ToolsCount = static_cast<size_t>(ToolType::ToolsCount);
    constexpr ToolType ToolTypes[] = 
    {
        ToolType::Pencil,
        ToolType::Eraser,
        ToolType::Bucket,
        ToolType::Text,
        ToolType::Rectangle,
        ToolType::Circle,
    };

    class ITool
    {
    public:
        virtual void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) = 0;
    };

    class Pencil : public ITool
    {
    public:
        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        size_t Radius = 5;
        ViewLib::Color Color = {0, 0, 0};
    };
    
    class Eraser : public ITool
    {
    public:
        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        size_t Radius = 40;
        ViewLib::Color Color = {255, 255, 255};
    };
    
    class Bucket : public ITool
    {
    public:
        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        ViewLib::Color Color;
    };
    
    class Text : public ITool
    {
    public:
        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        UtilLib::Utf8String Value;
        ViewLib::Color Color;
    };
    
    class Rectangle : public ITool
    {
    public:
        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        ViewLib::CoordType LeftTop;
        ViewLib::SizeType  Size;
        ViewLib::Color Color;
    };
    
    class Circle : public ITool
    {
    public:
        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        size_t Radius = 0;
        ViewLib::Color Color;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///