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

		ViewGroup(SimpleWindow* const hostWindow);
		
		virtual ~ViewGroup() = default;

		virtual void AddChild(View* const child) = 0;
		
		virtual void RemoveAllChildren() = 0;
		
		virtual SizeType OnMeasure(const MeasureStruct& meas) override;

		virtual void OnLayout(const CoordType& coord) override;

	private:
		// Системная функция начала рисования View.
		virtual void Draw(IRenderTarget& target) override final;

	public:
		virtual void OnDraw(IRenderTarget& target) override;
		
		virtual bool OnMouseEvent(const MouseEvent& event) override;

		virtual bool OnKeyboardEvent(const KeyboardEvent& event) override;

	protected:

		virtual View* GetChild(csize_t index) = 0;

		virtual size_t GetChildrenCount() const = 0;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///