#include "CanvasView.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

CanvasView::CanvasView() :
    View()
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
    View::OnDraw(target);
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
        
        DrawWithTool(drawingPoint);
    }

    return true;
}

void CanvasView::DrawWithTool(CoordType& drawingPoint)
{
    switch (ActiveTool)
    {
        case ImageEditor::ToolType::Pencil:
            Canvas.DrawCircle(CoordType(drawingPoint.Hor, drawingPoint.Ver), 5, Color(0, 0, 0));
            break;

        case ImageEditor::ToolType::Bucket:
            Canvas.DrawRectangle(CoordType(0, 0), GetSize().Hor, GetSize().Ver, Color(0, 0, 0));
            break;

        case ImageEditor::ToolType::Eraser:
            Canvas.DrawCircle(CoordType(drawingPoint.Hor, drawingPoint.Ver), 5, Color(255, 255, 255));
            break;

        case ImageEditor::ToolType::Text:
            break;

        case ImageEditor::ToolType::Rectangle:
            Canvas.DrawRectangle(CoordType(drawingPoint.Hor, drawingPoint.Ver), 40, 30, Color(200, 60, 100));
            break;

        case ImageEditor::ToolType::Circle:
            Canvas.DrawCircle(CoordType(drawingPoint.Hor, drawingPoint.Ver), 15, Color(40, 150, 70));
            break;

        default:
            assert(!"Not implemented");
            break;
    }
}
        
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///