#include <cassert>

#include "MouseEvent.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

IMouseClick::IMouseClick() :
    OnMouseLeftClick()
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

bool IMouseClick::ProcessMouseClick(const MouseEvent& event)
{
    static bool pressed = false;

    switch (event.Type)
    {
        case MouseEventType::LeftPressed:
            pressed = true;
            return true;

        case MouseEventType::LeftReleased:
            if (!pressed)
                return false;
            
            OnMouseLeftClick.RaiseEvent();
            pressed = false;
            return true;

        default:
            return false;
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///