#include "ViewGroup.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ViewGroup::ViewGroup() :
	ViewGroup(nullptr)
{
}

ViewGroup::ViewGroup(SimpleWindow* const hostWindow) :
	View(hostWindow)
{
	DrawBorder = true;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void ViewGroup::Draw(IRenderTarget& target)
{
	View::Draw(target);

	// Рисуем детей.
	csize_t childrenCount = GetChildrenCount();
	for (size_t st = 0; st < childrenCount; st++)
		GetChild(st)->Draw(target);
}

void ViewGroup::OnDraw(IRenderTarget& target)
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

SizeType ViewGroup::OnMeasure(const MeasureStruct& meas)
{
	if (DrawBorder)
	{
		
	}

	return SizeType{0, 0};
}

void ViewGroup::OnLayout(const CoordType& coord)
{
	
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

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