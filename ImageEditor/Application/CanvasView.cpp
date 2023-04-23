#include "CanvasView.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

CanvasView::CanvasView(SimpleWindow& hostWindow, ImageEditor::ToolsController& toolsController) :
    View(&hostWindow),
    ToolsController(toolsController)
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

SizeType CanvasView::OnMeasure(const MeasureStruct& meas)
{
    SizeType newSize = {};

    newSize.Hor  = MeasureDirection<Direction::Horizontal>(meas);
    newSize.Ver = MeasureDirection<Direction::Vertical>(meas);

    SetSize(newSize);
    return newSize;
}

template <Direction direction>
dim_t CanvasView::MeasureDirection(const MeasureStruct& meas)
{
    switch (meas[direction].Type)
    {
        case MeasureType::Infty:
            // Не понятно, какой размер должен иметь View, если пользователь его не указал.
            assert(!"Not implemented");
            break;
            
        case MeasureType::LessThan:
            return meas[direction].Size;
            
        case MeasureType::Exactly:
            return meas[direction].Size;
        
        default:
            assert(!"Not implemented");
            break;
    }

    return 0;
}

void CanvasView::OnDraw(IRenderTarget& target)
{
}

bool CanvasView::OnMouseEvent(const MouseEvent& event)
{
    if (!CheckInBounds(event.Pos))
        return false;

    if (event.Type == MouseEventType::LeftPressed)
        IsDrawing = true;

    if (event.Type == MouseEventType::LeftReleased)
        IsDrawing = false;

    if (IsDrawing)
    {
        CoordType drawingPoint = event.Pos;
        drawingPoint -= Pos;
        
        if (ToolsController.ActiveTool)
            ToolsController.ActiveTool->Draw(Canvas, drawingPoint);
    }

    return true;
}
        
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///