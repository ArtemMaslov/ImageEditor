#include "ViewGroup.h"

using ViewLib::ViewGroup;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ViewGroup::ViewGroup() : View()
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void ViewGroup::OnDraw(IRenderTarget& target)
{
	// Рисование детей.
	csize_t childrenCount = GetChildrenCount();
	for (size_t st = 0; st < childrenCount; st++)
		GetChild(st)->OnDraw(target);
	
	// Рисование ViewGroup.
	View::OnDraw(target);
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