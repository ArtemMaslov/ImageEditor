#include "View.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

View* View::FocusedView = nullptr;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

View::View() :
	HostWindow(nullptr)
{
}

View::View(SimpleWindow* const hostWindow) :
	BackgroundColor(),
	Parent(nullptr),
	HostWindow(hostWindow),
	Canvas()
{
}

void View::Draw(IRenderTarget& target)
{
	// Рисуем View.
	OnDraw(target);

	// После рисования View.
	Color borderColor(220, 20, 20);
	Canvas.DrawLine(CoordType(0, 0), CoordType(Size.Hor, 0), borderColor);
	Canvas.DrawLine(CoordType(1, 0), CoordType(1, Size.Ver - 1), borderColor);
	Canvas.DrawLine(CoordType(Size.Hor, 0), CoordType(Size.Hor, Size.Ver), borderColor);
	Canvas.DrawLine(CoordType(0, Size.Ver - 1), CoordType(Size.Hor, Size.Ver - 1), borderColor);

	target.Render(Canvas);
}

void View::OnLayout(const CoordType& coord)
{
	SetPosition(coord);
}

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