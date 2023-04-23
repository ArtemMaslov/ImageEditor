#pragma once

#include <ViewLib/View/View.h>

#include "ToolsProperties/Tool.h"
#include "ToolsProperties/ToolsController.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    class CanvasView : public View
    {
    public:
        CanvasView(SimpleWindow& hostWindow, ImageEditor::ToolsController& toolsController);

		virtual SizeType OnMeasure(const MeasureStruct& meas) override;

		virtual void OnDraw(IRenderTarget& target) override;

		virtual bool OnMouseEvent(const MouseEvent& event) override;

    private:
        template <Direction direction>
        dim_t MeasureDirection(const MeasureStruct& meas);

        void DrawWithTool(CoordType& drawingPoint);

    private:
        bool IsDrawing = false;
        ImageEditor::ToolsController& ToolsController;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///