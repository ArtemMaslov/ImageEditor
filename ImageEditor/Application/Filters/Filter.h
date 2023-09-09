#pragma once

#include <UtilLib/General.h>

#include <ViewLib/Graphics/Canvas.h>

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    enum class FilterType
    {
        Brightness,
        Blur,
        /// Общее количество инструментов.
        FiltersCount
    };

    constexpr size_t FiltersCount = static_cast<size_t>(FilterType::FiltersCount);

    class IFilter
    {
    public:
        virtual void Apply(ViewLib::CanvasType& canvas) = 0;
    };

    class BrightnessFilter : public IFilter
    {
    public:
        BrightnessFilter(int defaultDelta);

        virtual void Apply(ViewLib::CanvasType& canvas) override;

    public:
        int Delta;
    };

    class BlurFilter : public IFilter
    {
    public:
        BlurFilter(uint_t defaultSquareSize);

        virtual void Apply(ViewLib::CanvasType& canvas) override;

    public:
        uint_t SquareSize;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///