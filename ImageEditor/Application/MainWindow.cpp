#include <cassert>

#include "MainWindow.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

MainWindow::MainWindow() : 
	Window(1000, 800, "Редактор изображений"),
	PropertiesMenu(*this),
	ToolsController(*this),
	CanvasView(Window, ToolsController),
	RootLayout(&Window, ViewLib::Direction::Vertical),
	LayoutPropertiesCanvas(&Window, ViewLib::Direction::Horizontal),
	MainMenu(*this),
	ToolsMenu(*this)
{
	Window.SetRootView(&RootLayout);

	RootLayout.AddChild(&MainMenu.Layout);
	RootLayout.AddChild(&ToolsMenu.Layout);
	RootLayout.AddChild(&LayoutPropertiesCanvas);

	RootLayout.SumWeight.Ver          = 21;
	MainMenu.Layout.Weight.Ver        = 1;
	ToolsMenu.Layout.Weight.Ver       = 4;
	LayoutPropertiesCanvas.Weight.Ver = 16;

	LayoutPropertiesCanvas.AddChild(&PropertiesMenu.Layout);
	LayoutPropertiesCanvas.AddChild(&CanvasView);

	LayoutPropertiesCanvas.SumWeight.Hor = 20;
	PropertiesMenu.Layout.Weight.Hor = 5;
	CanvasView.Weight.Hor = 15;

	ToolsController.ActivateNewTool(ToolType::Pencil);

	// Уже измерили ActivateNewTool();
}

void MainWindow::Run()
{
	while (Window.IsOpen())
	{
		Window.CheckEvents();
		Window.Render();
	}
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///