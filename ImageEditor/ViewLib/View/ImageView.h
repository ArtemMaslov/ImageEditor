#pragma once

#include "../General.h"

#include "../Event/Event.h"
#include "../Graphics/Image.h"

#include "View.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    class ImageView : public View, public IMouseClick
    {
    public:
        ImageView();

		virtual SizeType OnMeasure(const MeasureStruct& meas) override;

		virtual void OnDraw(IRenderTarget& target) override;

		virtual bool OnMouseEvent(const MouseEvent& event) override;
        
    private:
        template <Direction direction>
        dim_t MeasureDirection(const MeasureStruct& meas);

    public:
        ViewLib::Image Image;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///