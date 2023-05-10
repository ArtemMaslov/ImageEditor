#include "ViewGroup.h"

using ViewLib::ViewGroup;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ViewGroup::ViewGroup() :
	View()
{
}

ViewGroup::ViewGroup(SimpleWindow* const hostWindow) :
	View(hostWindow)
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void ViewGroup::Draw(IRenderTarget& target)
{
	// Рисуем ViewGroup.
	View::Draw(target);
	// Рисуем детей.
	csize_t childrenCount = GetChildrenCount();
	for (size_t st = 0; st < childrenCount; st++)
		GetChild(st)->Draw(target);
}

void ViewGroup::OnDraw(IRenderTarget& target)
{
	Canvas.DrawRectangle(CoordType{0, 0}, GetSize().Hor, GetSize().Ver, BackgroundColor);
}

bool ViewGroup::OnMouseEvent(const MouseEvent& event)
{
	csize_t childrenCount = GetChildrenCount();
	for (size_t st = 0; st < childrenCount; st++)
	{
		if (GetChild(st)->OnMouseEvent(event))
			return true;
	}

	return false;
}

bool ViewGroup::OnKeyboardEvent(const KeyboardEvent& event)
{
	csize_t childrenCount = GetChildrenCount();
	for (size_t st = 0; st < childrenCount; st++)
	{
		if (GetChild(st)->OnKeyboardEvent(event))
			return true;
	}

	return false;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///