#include "BrightnessFilterProperties.h"

#include "../MainWindow.h"

using namespace ImageEditor;
using ConversionError = UtilLib::Utf8String::ConversionError;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

BrightnessFilterProperties::BrightnessFilterProperties(ImageEditor::MainWindow& mainWindow,
                                                       ImageEditor::BrightnessFilter& filter) :
    IProperties(mainWindow.Window),
    
    MainWindow(mainWindow),
    Filter(filter),

    TextViewFilterName(&mainWindow.Window),
    TextViewDelta(&mainWindow.Window),
    EditTextDelta(&mainWindow.Window),

    ButtonsDialog(mainWindow, Filter)
{
    TextViewFilterName.Text.Value = "Фильтр яркости";
    TextViewDelta.Text.Value = "Введите изменение\n"
                               "яркости:";

    EditTextDelta.Text.Value = UtilLib::Utf8String(std::to_string(filter.Delta));
    EditTextDelta.OnTextChanged += std::bind(&BrightnessFilterProperties::DeltaChanged, this);

    Layout.AddChild(&TextViewFilterName);
    Layout.AddChild(&TextViewDelta);
    Layout.AddChild(&EditTextDelta);

    Layout.AddChild(&ButtonsDialog.Layout);
}

void BrightnessFilterProperties::DeltaChanged()
{   
    int newDelta = 0;
    if (EditTextDelta.Text.Value.ToNumber(newDelta) == ConversionError::NoErrors)
        Filter.Delta = newDelta;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///