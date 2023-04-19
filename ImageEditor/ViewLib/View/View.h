#pragma once

#include <cassert>

#include <SFML/Graphics.hpp>

#include <UtilLib/General.h>

#include "../Event/MouseEvent.h"
#include "../Event/KeyboardEvent.h"

#include "../Graphics/Drawable.h"
#include "../Graphics/Canvas.h"

#include "../General.h"
#include "../Measure.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	class View
	{
	public:
		View();
		
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

		virtual SizeType OnMeasure(const MeasureStruct& meas) = 0;

		virtual void OnLayout(const CoordType& coord);

		virtual void OnDraw(IRenderTarget& target);

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

		inline bool CheckInBounds(const CoordType& point);
		
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

		inline SizeType GetSize() const noexcept;

		inline void SetSize(const SizeType& newSize) noexcept;
		
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

		inline CoordType GetPosition();

		inline void SetPosition(const CoordType& newPos);

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

		virtual bool OnMouseEvent(const MouseEvent& event);

		virtual bool OnKeyboardEvent(const KeyboardEvent& event);
		
		void CaptureFocus();

		inline bool IsFocused();
		
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

	protected:

	public:
		Color  BackgroundColor;

		/// Вес компонента. Используется контейнерами для распределения места для компонентов.
		ViewLib::WeightType Weight {0, 0};

	protected:
		View* Parent;

		CanvasType Canvas;

		// Абсолютные координаты.
		CoordType Pos;
	private:
		SizeType Size;

		bool HasFocus = false;
		static View* FocusedView;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	bool View::CheckInBounds(const CoordType& point)
	{
		return (point.Hor >= Pos.Hor && point.Hor < Pos.Hor + Size.Hor && point.Ver >= Pos.Ver && point.Ver < Pos.Ver + Size.Ver);
	}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

	SizeType View::GetSize() const noexcept
	{
		return Size;
	}
	
	void View::SetSize(const SizeType& newSize) noexcept
	{
		Size = newSize;
		Canvas.SetSize(newSize);
	}

	CoordType View::GetPosition()
	{
		return Pos;
	}

	void View::SetPosition(const CoordType& newPos)
	{
		Pos = newPos;
		Canvas.Pos = newPos;
	}
	
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

	inline bool View::IsFocused()
	{
		return HasFocus;
	}
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///