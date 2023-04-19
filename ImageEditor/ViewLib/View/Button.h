#pragma once

#include "../General.h"

#include "../Event/Event.h"
#include "../Graphics/Text.h"

#include "View.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    class Button : public View, public IMouseClick
    {
    public:
        Button();

        Button(dim_t width, dim_t height, Color background);

		virtual SizeType OnMeasure(const MeasureStruct& meas) override;

		virtual void OnDraw(IRenderTarget& target) override;

		virtual bool OnMouseEvent(const MouseEvent& event) override;
        
    private:
        template <Direction direction>
        dim_t MeasureDirection(const MeasureStruct& meas);

    public:
        ViewLib::Text Text;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///