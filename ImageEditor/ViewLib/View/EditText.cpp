#include "EditText.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

EditText::EditText() :
    TextView()
{
}

bool EditText::OnKeyboardEvent(const KeyboardEvent& event)
{
    if (!IsFocused())
        return false;

    if (event.Unicode == event.BACKSLASH)
    {
        Text.Value.EraseBack();
        Canvas.Clear();
        return true;
    }

    Text.Value += event.Unicode;
    return true;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///