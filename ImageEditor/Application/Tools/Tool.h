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

    // Карандаш или ластик
    class SplineTool : public ITool
    {
    public:
        SplineTool(size_t defaultRadius, const ViewLib::Color& defaultColor);

        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        size_t         Radius;
        ViewLib::Color Color;
    };
    
    class Bucket : public ITool
    {
    public:
        Bucket(const ViewLib::Color& defaultColor);

        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        ViewLib::Color Color;
    };
    
    class Text : public ITool
    {
    public:
        Text(const ViewLib::Color& defaultColor);

        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        ViewLib::Text  Value;
        ViewLib::Color Color;
    };
    
    class Rectangle : public ITool
    {
    public:
        Rectangle(const ViewLib::SizeType& defaultSize, const ViewLib::Color& defaultColor);

        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        ViewLib::SizeType Size;
        ViewLib::Color    Color;
    };
    
    class Circle : public ITool
    {
    public:
        Circle(size_t defaultRadius, const ViewLib::Color& defaultColor);

        void Draw(ViewLib::CanvasType& canvas, ViewLib::CoordType& point) override;

        size_t         Radius;
        ViewLib::Color Color;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///