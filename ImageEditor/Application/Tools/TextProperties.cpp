#include <functional>

#include "TextProperties.h"
#include "../MainWindow.h"

using namespace ImageEditor;
using ConversionError = UtilLib::Utf8String::ConversionError;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

TextProperties::TextProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::Text& tool) :
    IProperties(mainWindow.Window),
    MainWindow(mainWindow),

    Tool(tool),
    TextViewToolName(&mainWindow.Window),
    TextViewFontSize(&mainWindow.Window),
    EditTextFontSize(&mainWindow.Window),
    TextViewString(&mainWindow.Window),
    EditTextString(&mainWindow.Window),

    ColorPicker(&mainWindow.Window, tool.Color)
{
    TextViewToolName.Text.Value = "Текст";
    TextViewFontSize.Text.Value = "Размер шрифта (в пикселях):";
    EditTextFontSize.Text.Value = UtilLib::Utf8String(std::to_string(tool.Value.GetFontSize()));
    TextViewString.Text.Value   = "Введите текст:";

    Layout.AddChild(&TextViewToolName);
    Layout.AddChild(&TextViewFontSize);
    Layout.AddChild(&EditTextFontSize);
    Layout.AddChild(&TextViewString);
    Layout.AddChild(&EditTextString);
    Layout.AddChild(&ColorPicker.Layout);

    EditTextFontSize.OnTextChanged += std::bind(&TextProperties::FontSizeChanged, this);
    EditTextString.OnTextChanged += std::bind(&TextProperties::StringChanged, this);
}

void TextProperties::StringChanged()
{
    Tool.Value.Value = EditTextString.Text.Value;
}

void TextProperties::FontSizeChanged()
{
    int64_t newFontSize = 0;
    if (EditTextFontSize.Text.Value.ToNumber(newFontSize) == ConversionError::NoErrors&& newFontSize > 0)
        Tool.Value.SetFontSize(newFontSize);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///