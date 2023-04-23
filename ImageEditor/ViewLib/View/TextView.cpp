#include "TextView.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

TextView::TextView() :
    View()
{
}

TextView::TextView(SimpleWindow* const hostWindow) :
    View(hostWindow)
{
}

SizeType TextView::OnMeasure(const MeasureStruct& meas)
{
	SizeType newSize = Text.MeasureSize();

    switch (meas.Ver.Type)
    {
        case MeasureType::Exactly:
            newSize.Ver = meas.Ver.Size;
            break;
        case MeasureType::LessThan:
            newSize.Ver = std::min(newSize.Ver, meas.Ver.Size);
            break;
        case MeasureType::Infty:
            break;
    }

    switch (meas.Hor.Type)
    {
        case MeasureType::Exactly:
            newSize.Hor = meas.Hor.Size;
            break;
        case MeasureType::LessThan:
            newSize.Hor = std::min(newSize.Hor, meas.Hor.Size);
            break;
        case MeasureType::Infty:
            break;
    }

    SetSize(newSize);
	return newSize;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void TextView::OnDraw(IRenderTarget& target)
{
    Canvas.Render(Text);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///