#include <functional>

#include "ColorPicker.h"

using namespace ViewLib;
using UtilLib::Utf8String;
using ConversionError = UtilLib::Utf8String::ConversionError;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ColorPicker::ColorPicker(ViewLib::SimpleWindow* const hostWindow, ViewLib::Color& outColor) :
    Layout(hostWindow, ViewLib::Direction::Vertical),
    TextViewColor(hostWindow),

    TextViewRed(hostWindow),
    EditTextRed(hostWindow),
    TextViewGreen(hostWindow),
    EditTextGreen(hostWindow),
    TextViewBlue(hostWindow),
    EditTextBlue(hostWindow)
{
    TextViewColor.Text.Value = "Цвет";
    TextViewRed.Text.Value   = "Красный [0-255]:";
    EditTextRed.Text.Value   = UtilLib::Utf8String(std::to_string(outColor.R));
    TextViewGreen.Text.Value = "Зелёный [0-255]:";
    EditTextGreen.Text.Value = UtilLib::Utf8String(std::to_string(outColor.G));
    TextViewBlue.Text.Value  = "Синий [0-255]:";
    EditTextBlue.Text.Value  = UtilLib::Utf8String(std::to_string(outColor.B));

    Layout.AddChild(&TextViewColor);
    Layout.AddChild(&TextViewRed);
    Layout.AddChild(&EditTextRed);
    Layout.AddChild(&TextViewGreen);
    Layout.AddChild(&EditTextGreen);
    Layout.AddChild(&TextViewBlue);
    Layout.AddChild(&EditTextBlue);

    EditTextRed.OnTextChanged   += std::bind(&ColorPicker::ColorChanged, this, std::ref(EditTextRed),   std::ref(outColor.R));
    EditTextGreen.OnTextChanged += std::bind(&ColorPicker::ColorChanged, this, std::ref(EditTextGreen), std::ref(outColor.G));
    EditTextBlue.OnTextChanged  += std::bind(&ColorPicker::ColorChanged, this, std::ref(EditTextBlue),  std::ref(outColor.B));
}

void ColorPicker::ColorChanged(ViewLib::EditText& colorEditText, ViewLib::color_t& colorComponent)
{
    int64_t newColor = 0;
    if (colorEditText.Text.Value.ToInt(newColor) == ConversionError::NoErrors)
        colorComponent = newColor;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///