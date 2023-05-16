#pragma once

#include <ViewLib/View/View.h>
#include <ViewLib/Graphics/Image.h>

#include "Tools/Tool.h"
#include "Tools/ToolsController.h"

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

        void LoadImage(ViewLib::Image& image);

        const sf::Texture& GetTexture();

    private:
        template <Direction direction>
        dim_t MeasureDirection(const MeasureStruct& meas);

        void DrawWithTool(CoordType& drawingPoint);

    public:
        CanvasType DrawingCanvas;
        
    private:
        bool IsDrawing = false;
        ImageEditor::ToolsController& ToolsController;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///