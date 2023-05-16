#include "ButtonsDialog.h"

#include "../MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ButtonsDialog::ButtonsDialog(MainWindow& mainWindow, IFilter& filter) :
    Layout(&mainWindow.Window, ViewLib::Direction::Horizontal),

    ButtonCancel(&mainWindow.Window),
    ButtonApply(&mainWindow.Window)
{
    ButtonCancel.Text.Value = "Отмена";
    ButtonApply.Text.Value  = "Применить";

    ButtonCancel.Weight.Hor = 1;
    ButtonApply.Weight.Hor  = 1;
    Layout.SumWeight.Hor    = 2;

    ButtonApply.OnMouseLeftClick += 
        std::bind(&IFilter::Apply, &filter, std::ref(mainWindow.CanvasView.DrawingCanvas));

    ButtonCancel.OnMouseLeftClick += 
        std::bind(&PropertiesMenu::RestorePreviousProperties, &mainWindow.PropertiesMenu);

    Layout.AddChild(&ButtonCancel);
    Layout.AddChild(&ButtonApply);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///