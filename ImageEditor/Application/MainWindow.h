#pragma once

#include <ViewLib/SimpleWindow.h>

#include "CanvasView.h"
#include "ToolsMenu.h"
#include "PropertiesMenu.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ImageEditor
{
	class MainWindow
	{
	public:
		MainWindow();

		void Run();

		ToolType GetActiveTool();

		void SetActiveTool(ToolType newTool);

	public:
		ViewLib::CanvasView CanvasView;

	private:
		ViewLib::SimpleWindow Window;

		ViewLib::LinearLayout RootLayout;
		/// Содержит меню настроек и CanvasView.
		ViewLib::LinearLayout LayoutPropertiesCanvas;
		
		ImageEditor::ToolsMenu ToolsMenu;
		ImageEditor::PropertiesMenu PropertiesMenu;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///