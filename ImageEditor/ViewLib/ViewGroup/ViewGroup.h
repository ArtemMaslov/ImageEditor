#pragma once

#include "../View/View.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	class ViewGroup : public View
	{
	public:
		ViewGroup();

		virtual void AddChild(View* const child) = 0;
		
		virtual void RemoveAllChildren() = 0;

		virtual void OnDraw(IRenderTarget& target) override;
		
		virtual bool OnMouseEvent(const MouseEvent& event) override;

		virtual bool OnKeyboardEvent(const KeyboardEvent& event) override;

	protected:

		virtual View* const GetChild(csize_t index) = 0;

		virtual size_t GetChildrenCount() const = 0;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///