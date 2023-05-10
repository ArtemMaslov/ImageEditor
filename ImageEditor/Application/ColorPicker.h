#pragma once

#include <ViewLib/View/EditText.h>
#include <ViewLib/ViewGroup/LinearLayout.h>
#include <ViewLib/SimpleWindow.h>

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    class ColorPicker
    {
    public:
        ColorPicker(ViewLib::SimpleWindow* const hostWindow, ViewLib::Color& outColor);

    private:
        void ColorChanged(ViewLib::EditText& colorEditText, ViewLib::color_t& colorComponent);

    public:
        ViewLib::LinearLayout Layout;

    private:
        ViewLib::TextView TextViewColor;

        ViewLib::TextView TextViewRed;
        ViewLib::EditText EditTextRed;
        ViewLib::TextView TextViewGreen;
        ViewLib::EditText EditTextGreen;
        ViewLib::TextView TextViewBlue;
        ViewLib::EditText EditTextBlue;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///