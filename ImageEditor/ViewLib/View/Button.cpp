#include <cassert>

#include "Button.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

Button::Button() :
    IMouseClick()
{
}


Button::Button(dim_t width, dim_t height, Color background) :
    Button()
{
    SetSize(SizeType(width, height));
    BackgroundColor = background;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

SizeType Button::OnMeasure(const MeasureStruct& meas)
{
	SizeType newSize = {};

    assert(meas.Ver.Type != MeasureType::Infty);

    newSize.Hor = MeasureDirection<Direction::Horizontal>(meas);
    newSize.Ver = MeasureDirection<Direction::Vertical>(meas);

    SetSize(newSize);
	return newSize;
}

template <Direction direction>
dim_t Button::MeasureDirection(const MeasureStruct& meas)
{
    switch (meas[direction].Type)
    {
        case MeasureType::Infty:
        {
            SizeType textSize = Text.MeasureSize();
            return textSize[direction];
        }
        case MeasureType::LessThan:
        {
            SizeType textSize = Text.MeasureSize();
            return std::min(textSize[direction], meas[direction].Size);
        }
        case MeasureType::Exactly:
            return meas[direction].Size;
    }

    return 0;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void Button::OnDraw(IRenderTarget& target)
{
    Canvas.Render(Text);

    View::OnDraw(target);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

bool Button::OnMouseEvent(const MouseEvent& event)
{
    if (!CheckInBounds(event.Pos))
        return false;

    return ProcessMouseClick(event);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///