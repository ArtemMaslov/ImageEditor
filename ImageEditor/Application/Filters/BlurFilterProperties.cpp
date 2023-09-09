#include "BlurFilterProperties.h"

#include "../MainWindow.h"

using namespace ImageEditor;
using ConversionError = UtilLib::Utf8String::ConversionError;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

BlurFilterProperties::BlurFilterProperties(ImageEditor::MainWindow& mainWindow,
                                           ImageEditor::BlurFilter& filter) :
    IProperties(mainWindow.Window),

    MainWindow(mainWindow),
    Filter(filter),

    TextViewFilterName(&mainWindow.Window),
    TextViewSquareSize(&mainWindow.Window),
    EditTextSquareSize(&mainWindow.Window),

    ButtonsDialog(mainWindow, Filter)
{
    TextViewFilterName.Text.Value = "Фильтр размытия";
    TextViewSquareSize.Text.Value = "Введите длину стороны\n"
                                    "квадрата, по которому\n"
                                    "проводить усреднение:";

    EditTextSquareSize.Text.Value = UtilLib::Utf8String(std::to_string(filter.SquareSize));
    EditTextSquareSize.OnTextChanged += std::bind(&BlurFilterProperties::SquareSizeChanged, this);
    
    Layout.AddChild(&TextViewFilterName);
    Layout.AddChild(&TextViewSquareSize);
    Layout.AddChild(&EditTextSquareSize);

    Layout.AddChild(&ButtonsDialog.Layout);
}

void BlurFilterProperties::SquareSizeChanged()
{
    uint_t newSquareSize = 0;
    if (EditTextSquareSize.Text.Value.ToNumber(newSquareSize) == ConversionError::NoErrors)
        Filter.SquareSize = newSquareSize;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///