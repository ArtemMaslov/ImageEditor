#pragma once

#include <ViewLib/SimpleWindow.h>

#include "CanvasView.h"
#include "MainMenu.h"
#include "Tools/ToolsMenu.h"
#include "Properties/PropertiesMenu.h"

#include "Tools/ToolsController.h"
#include "Filters/FiltersController.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
	//class ToolsController;
	//class FiltersController;

	class MainWindow
	{
	public:
		MainWindow();

		void Run();

	public:
		ViewLib::SimpleWindow Window;

		ImageEditor::PropertiesMenu PropertiesMenu;

		ImageEditor::ToolsController ToolsController;
		ImageEditor::FiltersController FiltersController;
		
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