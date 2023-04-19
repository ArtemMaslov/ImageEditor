#pragma once

#include <ViewLib/ViewGroup/LinearLayout.h>
#include <ViewLib/View/EditText.h>

#include "../CanvasView.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
    class PencilProperties
    {
    public:
        PencilProperties(ViewLib::CanvasView& canvasView);

        void InflateProperties(ViewLib::LinearLayout& parent);

    private:
        ViewLib::CanvasView& CanvasView;

        ViewLib::LinearLayout Layout;

        ViewLib::TextView EnterRadius;
        ViewLib::EditText Radius;

        ViewLib::TextView EnterColor;

        ViewLib::TextView EnterRed;
        ViewLib::EditText Red;
        ViewLib::TextView EnterGreen;
        ViewLib::EditText Green;
        ViewLib::TextView EnterBlue;
        ViewLib::EditText Blue;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///