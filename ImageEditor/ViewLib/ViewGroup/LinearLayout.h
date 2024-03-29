#pragma once

#include <vector>

#include "ViewGroup.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	class LinearLayout : public ViewGroup
	{
	public:
		LinearLayout();

		LinearLayout(SimpleWindow* const hostWindow, Direction direction);
		
		virtual ~LinearLayout() = default;

		virtual void AddChild(View* const child) final;
		
		virtual void RemoveAllChildren() final;

		virtual SizeType OnMeasure(const MeasureStruct& meas) override;

		virtual void OnLayout(const CoordType& coord) override;

	protected:

		virtual View* GetChild(csize_t index) final;

		virtual size_t GetChildrenCount() const final;	

	private:
		template <Direction direction>
		SizeType MeasureDirection(const MeasureStruct& measure);
		
		template <Direction direction>
		void LayoutDirection(const CoordType& coord);

	public:
		/// Сумма весов компонентов, которая соответствует размеру LinearLayout.
		ViewLib::WeightType SumWeight = {0, 0};

	private:
		std::vector<View*> Childs;
		const Direction Orientation;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///