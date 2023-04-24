#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <UtilLib/General.h>
#include "Graphics/Drawable.h"
#include "Graphics/Canvas.h"
#include "Graphics/Text.h"

#include "View/View.h"
#include "Event/Event.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	class IRender;
	class View;

	class SimpleWindow : public IRenderTarget
	{
	public:
		SimpleWindow(cdim_t width, cdim_t height, std::string HeaderText);

		void MeasureChildren();

		void LayoutChildren();

		void Render();

        virtual void Render(IRender& drawable) override;

		bool CheckEvents();

		inline bool IsOpen() const noexcept;

		inline void SetRootView(View* const view) noexcept;

		inline const sf::RenderWindow& GetWindow() const noexcept;
		
	public:
		EventHolder  OnWindowClose;

	private:
		sf::RenderWindow Window;
		View*            RootView;
		dim_t            Width;
		dim_t            Height;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	bool SimpleWindow::IsOpen() const noexcept
	{
		return Window.isOpen();
	}

	void SimpleWindow::SetRootView(View* const view) noexcept
	{
		RootView = view;
	}
	
	const sf::RenderWindow& SimpleWindow::GetWindow() const noexcept
	{
		return Window;
	}
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///