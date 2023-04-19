#include "TextView.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

TextView::TextView() :
    View()
{
}

SizeType TextView::OnMeasure(const MeasureStruct& meas)
{
	SizeType newSize = Text.MeasureSize();
    size_t   textHeight = Text.GetLineHeight();

    

    newSize.Hor = MeasureDirection<Direction::Horizontal>(meas);
    newSize.Ver = MeasureDirection<Direction::Vertical>(meas);

    SetSize(newSize);
	return newSize;
}

template <Direction direction>
dim_t TextView::MeasureDirection(const MeasureStruct& meas)
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

void TextView::OnDraw(IRenderTarget& target)
{
    Canvas.Render(Text);

    View::OnDraw(target);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///