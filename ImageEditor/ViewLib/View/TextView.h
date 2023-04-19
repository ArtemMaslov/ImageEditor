#pragma once

#include "View.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    class TextView : public View
    {
    public:
        TextView();

        virtual SizeType OnMeasure(const MeasureStruct& meas) override;

		virtual void OnDraw(IRenderTarget& target) override;

    private:
        template <Direction direction>
        dim_t MeasureDirection(const MeasureStruct& meas);

    public:
        ViewLib::Text Text;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///