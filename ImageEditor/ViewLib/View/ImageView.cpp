#include <cassert>

#include "ImageView.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ImageView::ImageView() :
    IMouseClick()
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

SizeType ImageView::OnMeasure(const MeasureStruct& meas)
{
	SizeType newSize = {};

    assert(meas.Ver.Type != MeasureType::Infty);

    newSize.Hor = MeasureDirection<Direction::Horizontal>(meas);
    newSize.Ver = MeasureDirection<Direction::Vertical>(meas);

    Image.SetStretchSize(newSize);
    SetSize(newSize);
	return newSize;
}

template <Direction direction>
dim_t ImageView::MeasureDirection(const MeasureStruct& meas)
{
    switch (meas[direction].Type)
    {
        case MeasureType::Infty:
        {
            assert(!"Not implemented");
        }
        case MeasureType::LessThan:
        {
            SizeType imageSize = Image.GetSize();
            return std::min(imageSize[direction], meas[direction].Size);
        }
        case MeasureType::Exactly:
            return meas[direction].Size;
    }

    return 0;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void ImageView::OnDraw(IRenderTarget& target)
{
    Canvas.Render(Image);

    View::OnDraw(target);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

bool ImageView::OnMouseEvent(const MouseEvent& event)
{
    if (!CheckInBounds(event.Pos))
        return false;

    return ProcessMouseClick(event);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///