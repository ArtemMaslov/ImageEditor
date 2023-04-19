#pragma once

#include <ViewLib/View/View.h>

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    enum class ToolType
    {
        Pencil    = 0,
        Bucket    = 1,
        Eraser    = 2,
        Text      = 3,
        Rectangle = 4,
        Circle    = 5
    };
}

namespace ViewLib
{
    class CanvasView : public View
    {
    public:
        CanvasView();

		virtual SizeType OnMeasure(const MeasureStruct& meas) override;

		virtual void OnDraw(IRenderTarget& target) override;

		virtual bool OnMouseEvent(const MouseEvent& event) override;

    private:
        template <Direction direction>
        dim_t MeasureDirection(const MeasureStruct& meas);

        void DrawWithTool(CoordType& drawingPoint);

    public:
        ImageEditor::ToolType ActiveTool;

    private:
        bool IsDrawing = false;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///