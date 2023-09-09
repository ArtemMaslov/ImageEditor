#pragma once

#include <ViewLib/ViewGroup/LinearLayout.h>

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class IProperties
    {
    public:
        IProperties(ViewLib::SimpleWindow& window);

        inline void InflateProperties(ViewLib::LinearLayout& parent)
        {
            parent.AddChild(&Layout);
        }

    protected:
        ViewLib::LinearLayout Layout;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///