#include "RectangleProperties.h"

#include "../MainWindow.h"

using namespace ImageEditor;
using ConversionError = UtilLib::Utf8String::ConversionError;

static void RectangleSizeChanged(ViewLib::EditText& editText, ViewLib::dim_t& outValue);

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

RectangleProperties::RectangleProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::Rectangle& tool) :
    IProperties(mainWindow.Window),
    MainWindow(mainWindow),

    Tool(tool),

    TextViewToolName(&mainWindow.Window),
    TextViewWidth(&mainWindow.Window),
    EditTextWidth(&mainWindow.Window),
    TextViewHeight(&mainWindow.Window),
    EditTextHeight(&mainWindow.Window),

    ColorPicker(&mainWindow.Window, tool.Color)
{
    TextViewToolName.Text.Value = "Прямоугольник";
    TextViewWidth.Text.Value    = "Высота";
    EditTextWidth.Text.Value    = UtilLib::Utf8String(std::to_string(tool.Size.Hor));
    TextViewHeight.Text.Value   = "Ширина";
    EditTextHeight.Text.Value   = UtilLib::Utf8String(std::to_string(tool.Size.Ver));

    Layout.AddChild(&TextViewToolName);
    Layout.AddChild(&TextViewWidth);
    Layout.AddChild(&EditTextWidth);
    Layout.AddChild(&TextViewHeight);
    Layout.AddChild(&EditTextHeight);
    Layout.AddChild(&ColorPicker.Layout);
    
    EditTextWidth.OnTextChanged  += std::bind(RectangleSizeChanged,
                                              std::ref(EditTextWidth), std::ref(Tool.Size.Hor));
    EditTextHeight.OnTextChanged += std::bind(RectangleSizeChanged,
                                              std::ref(EditTextHeight), std::ref(Tool.Size.Ver));
}

static void RectangleSizeChanged(ViewLib::EditText& editText, ViewLib::dim_t& outValue)
{
    int64_t newValue = 0;
    if (editText.Text.Value.ToNumber(newValue) == ConversionError::NoErrors && newValue > 0)
        outValue = newValue;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///