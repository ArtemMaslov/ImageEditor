#pragma once

#include "../Event/Event.h"

#include "TextView.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    class EditText : public TextView
    {
    public:
        EditText();

        EditText(SimpleWindow* const hostWindow);
        
		virtual ~EditText() = default;

        virtual bool OnKeyboardEvent(const KeyboardEvent& event) override;
        
		virtual void OnDraw(IRenderTarget& target) override;

    private:
        void DrawCursor(IRenderTarget& target);

        void RaiseTextChanged();

    public:
        EventHolder OnTextChanged;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///