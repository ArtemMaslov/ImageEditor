#include "ViewGroup/ViewGroup.h"
#include "SimpleWindow.h"

using ViewLib::SimpleWindow;
using ViewLib::ViewGroup;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

SimpleWindow::SimpleWindow(cdim_t width, cdim_t height, std::string HeaderText) :
	OnWindowClose(),
	Window(sf::VideoMode(width, height),
		   sf::String::fromUtf8(HeaderText.begin(), HeaderText.end()), 
		   sf::Style::Default,
		   sf::ContextSettings {0, 0, 8, 1, 1, 0, false}),
	RootView(nullptr),
	Width(Window.getSize().x),
	Height(Window.getSize().y)
{
	Window.setFramerateLimit(30);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void SimpleWindow::MeasureChildren()
{
	MeasureStruct meas = {};
	meas.Hor = MeasureUnit::ConstructLessThan(Width);
	meas.Ver = MeasureUnit::ConstructLessThan(Height);

	RootView->OnMeasure(meas);
}

void SimpleWindow::LayoutChildren()
{
	RootView->SetPosition(CoordType(0, 0));

	ViewGroup* const viewGroup = dynamic_cast<ViewGroup*>(RootView);
	if (viewGroup != nullptr)
		viewGroup->OnLayout(CoordType(0, 0));
}

void SimpleWindow::Render()
{
	Window.clear(sf::Color::White);
	RootView->OnDraw(*this);
	Window.display();
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

bool SimpleWindow::CheckEvents()
{
	sf::Event event = {};
	bool      eventsProcessed = false;
	while (Window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				OnWindowClose.RaiseEvent();
				Window.close();
				return true;

			case sf::Event::MouseButtonPressed:
			{
				MouseEventType type = MouseEventType::Null;
				switch (event.mouseButton.button)
				{
					case sf::Mouse::Button::Left:
						type = MouseEventType::LeftPressed;
						break;
						
					case sf::Mouse::Button::Right:
						type = MouseEventType::RightPressed;
						break;

					default: break;
				}

				if (type != MouseEventType::Null && RootView)
				{
					RootView->OnMouseEvent(MouseEvent{type, CoordType{event.mouseButton.x, event.mouseButton.y}});
					eventsProcessed = true;
				}
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				MouseEventType type = MouseEventType::Null;
				switch (event.mouseButton.button)
				{
					case sf::Mouse::Button::Left:
						type = MouseEventType::LeftReleased;
						break;
						
					case sf::Mouse::Button::Right:
						type = MouseEventType::RightReleased;
						break;
					
					default: break;
				}

				if (type != MouseEventType::Null && RootView)
				{
					RootView->OnMouseEvent(MouseEvent{type, CoordType{event.mouseButton.x, event.mouseButton.y}});
					eventsProcessed = true;
				}
				break;
			}
			case sf::Event::TextEntered:
			{
				if (RootView)
				{
					RootView->OnKeyboardEvent(KeyboardEvent{event.text.unicode});
				}
				break;
			}
			case sf::Event::MouseMoved:
			{
				MouseEventType type = MouseEventType::Moved;
				if (type != MouseEventType::Null && RootView)
				{
					RootView->OnMouseEvent(MouseEvent{type, CoordType{event.mouseMove.x, event.mouseMove.y}});
					eventsProcessed = true;
				}
				break;
			}
			case sf::Event::Resized:
			{
				if (RootView)
				{
					Width  = event.size.width;
					Height = event.size.height;
					sf::FloatRect view(0, 0, event.size.width, event.size.height);
    				Window.setView(sf::View(view));
					MeasureChildren();
					LayoutChildren();
				}
				break;
			}


			default: break;
		}
	}

	return eventsProcessed;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void SimpleWindow::Render(IRender& drawable)
{
	drawable.Render(Window);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///