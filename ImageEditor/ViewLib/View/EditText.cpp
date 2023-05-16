#include "EditText.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

EditText::EditText() :
    TextView(),
    OnTextChanged()
{
}

EditText::EditText(SimpleWindow* const hostWindow) :
    TextView(hostWindow),
    OnTextChanged()
{
}

bool EditText::OnKeyboardEvent(const KeyboardEvent& event)
{
    assert(HostWindow);
    
    if (!IsFocused())
        return false;

    if (event.Unicode == event.BACKSLASH)
    {
        auto lastSym = Text.Value.End();
        lastSym--;
        if (*lastSym == '\n')
        {
            Text.Value.EraseBack();
            HostWindow->MeasureChildren();
            HostWindow->LayoutChildren();
            Canvas.Clear();
            OnTextChanged.RaiseEvent();
            return true;
        }
        
        Text.Value.EraseBack();
        Canvas.Clear();
        OnTextChanged.RaiseEvent();
        return true;
    }

    // При нажатии enter событие содержит '\r' = 13 на Linux.
    if (event.Unicode == '\r' || event.Unicode == '\n')
    {
        Text.Value += '\n';
        HostWindow->MeasureChildren();
        HostWindow->LayoutChildren();
        OnTextChanged.RaiseEvent();
        return true;
    }

    Text.Value += event.Unicode;
    OnTextChanged.RaiseEvent();
    return true;
}

void EditText::OnDraw(IRenderTarget& target)
{
    TextView::OnDraw(target);

    DrawCursor(target);
}

void EditText::DrawCursor(IRenderTarget& target)
{

}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///