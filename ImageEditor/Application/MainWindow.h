#pragma once

#include <ViewLib/SimpleWindow.h>

#include "ToolsProperties/ToolsController.h"
#include "CanvasView.h"
#include "MainMenu.h"
#include "ToolsMenu.h"
#include "PropertiesMenu.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
	class ToolsController;

	class MainWindow
	{
	public:
		MainWindow();

		void Run();

	public:
		ViewLib::SimpleWindow Window;

		ImageEditor::PropertiesMenu PropertiesMenu;

		ImageEditor::ToolsController ToolsController;
		
		ViewLib::CanvasView CanvasView;

	private:
		ViewLib::LinearLayout RootLayout;
		/// Содержит меню настроек и CanvasView.
		ViewLib::LinearLayout LayoutPropertiesCanvas;
		
		ImageEditor::MainMenu  MainMenu;
		ImageEditor::ToolsMenu ToolsMenu;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///