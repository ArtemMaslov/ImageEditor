#include "View.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

View* View::FocusedView = nullptr;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

View::View() :
	View(nullptr)
{
}

View::View(SimpleWindow* const hostWindow) :
	Parent(nullptr),
	HostWindow(hostWindow),
	Canvas()
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void View::Draw(IRenderTarget& target)
{
	if (DrawBackground)
		FillBackground();

	// Рисуем View.
	OnDraw(target);

	// Граница компонента.
	if (DrawBorder)
		DrawBoundaries();
	
	target.Render(Canvas);
}

void View::FillBackground()
{
	Canvas.DrawRectangle(CoordType{0, 0}, GetSize().Hor, GetSize().Ver, ColorBackground);
}

void View::DrawBoundaries()
{
	Canvas.DrawLine(CoordType(0, 0), CoordType(Size.Hor, 0), ColorBorder);
	Canvas.DrawLine(CoordType(1, 0), CoordType(1, Size.Ver - 1), ColorBorder);
	Canvas.DrawLine(CoordType(Size.Hor, 0), CoordType(Size.Hor, Size.Ver), ColorBorder);
	Canvas.DrawLine(CoordType(0, Size.Ver - 1), CoordType(Size.Hor, Size.Ver - 1), ColorBorder);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void View::OnLayout(const CoordType& coord)
{
	SetPosition(coord);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

bool View::OnMouseEvent(const MouseEvent& event)
{
	static bool pressed = false;
	if (!CheckInBounds(event.Pos))
		return false;

	switch (event.Type)
	{
		case MouseEventType::LeftPressed:
			pressed = true;
			break;
		case MouseEventType::LeftReleased:
			if (pressed)
			{
				CaptureFocus();
				pressed = false;
			}
			break;
		default:
			pressed = false;
			break;
	}
	
	return true;
}

bool View::OnKeyboardEvent(const KeyboardEvent& event)
{
	return false;
}

void View::CaptureFocus()
{
	if (FocusedView)
		FocusedView->HasFocus = false;
	HasFocus    = true;
	FocusedView = this;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///