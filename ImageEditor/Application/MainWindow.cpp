#include <cassert>

#include "MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

MainWindow::MainWindow() : 
	CanvasView(),
	Window(1000, 800, "Редактор изображений"),
	RootLayout(ViewLib::Direction::Vertical),
	LayoutPropertiesCanvas(ViewLib::Direction::Horizontal),
	ToolsMenu(this),
	PropertiesMenu(this)
{
	Window.SetRootView(&RootLayout);

	RootLayout.AddChild(&ToolsMenu.Layout);
	RootLayout.AddChild(&LayoutPropertiesCanvas);

	RootLayout.SumWeight.Ver = 20;
	ToolsMenu.Layout.Weight.Ver = 4;
	LayoutPropertiesCanvas.Weight.Ver = 16;

	LayoutPropertiesCanvas.AddChild(&PropertiesMenu.Layout);
	LayoutPropertiesCanvas.AddChild(&CanvasView);

	LayoutPropertiesCanvas.SumWeight.Hor = 20;
	PropertiesMenu.Layout.Weight.Hor = 5;
	CanvasView.Weight.Hor = 15;

	SetActiveTool(ToolType::Pencil);

	// Уже измерили в SetActiveTool();
	//Window.MeasureChildren();
	//Window.LayoutChildren();
}

void MainWindow::Run()
{
	while (Window.IsOpen())
	{
		Window.CheckEvents();
		Window.Render();
	}
}

ToolType MainWindow::GetActiveTool()
{
	return CanvasView.ActiveTool;
}

void MainWindow::SetActiveTool(ToolType newTool)
{
	CanvasView.ActiveTool = newTool;
	switch (newTool)
	{
		case ToolType::Pencil:
			PropertiesMenu.InflatePencilLayout();
			break;
		
		default:
			PropertiesMenu.ClearLayout();
			break;
	}
	
	Window.MeasureChildren();
	Window.LayoutChildren();
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///