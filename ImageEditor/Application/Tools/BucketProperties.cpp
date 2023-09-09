#include "BucketProperties.h"

#include "../MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

BucketProperties::BucketProperties(ImageEditor::MainWindow& mainWindow, ImageEditor::Bucket& tool) :
    IProperties(mainWindow.Window),
    MainWindow(mainWindow),

    Tool(tool),
    TextViewToolName(&mainWindow.Window),
    
    ColorPicker(&mainWindow.Window, tool.Color)
{
    TextViewToolName.Text.Value = "Ведро";
    
    Layout.AddChild(&TextViewToolName);
    Layout.AddChild(&ColorPicker.Layout);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///