#pragma once

#include "../General.h"
#include "../SizePair.h"

#include "Event.h"
#include "MouseEvent.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    enum class MouseEventType
    {
        Null,
        LeftPressed,
        RightPressed,
        LeftReleased,
        RightReleased,
        Moved,
    };

    struct MouseEvent
    {
        MouseEventType Type;
        CoordType      Pos;

        inline MouseEvent ToLocalCoords(CoordType& viewPos) const noexcept;
    };

    class IMouseClick
    {
    public:
        IMouseClick();

    protected:
        bool ProcessMouseClick(const MouseEvent& event);

    public:
        EventHolder OnMouseLeftClick;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    MouseEvent MouseEvent::ToLocalCoords(CoordType& viewPos) const noexcept
    {
        assert(Pos.Hor >= viewPos.Hor && Pos.Ver >= viewPos.Ver);
        return MouseEvent
        {
            .Type = this->Type,
            .Pos{Pos.Hor - viewPos.Hor, Pos.Ver - viewPos.Ver}
        };
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///