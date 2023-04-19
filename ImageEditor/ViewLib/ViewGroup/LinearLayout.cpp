#include <cassert>

#include "../Measure.h"
#include "LinearLayout.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///									  Конструкторы
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

LinearLayout::LinearLayout(::Direction direction) :
	Orientation(direction)
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///									   Измерение
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

SizeType LinearLayout::OnMeasure(const MeasureStruct& meas)
{
	assert(Orientation == Direction::Horizontal || Orientation == Direction::Vertical);

	SizeType newSize = {100, 100};

	if (Orientation == Direction::Horizontal)
		newSize = MeasureDirection<Direction::Horizontal>(meas);
	else
		newSize = MeasureDirection<Direction::Vertical>(meas);
	
	SetSize(newSize);
	return newSize;
}

template <Direction direction>
SizeType LinearLayout::MeasureDirection(const MeasureStruct& meas)
{
	SizeType newSize = {};

	csize_t childsCount = GetChildrenCount();

	if (meas[direction].Type == MeasureType::Infty)
	{
		MeasureStruct availableSpace = meas;

		// Веса не работают, так как не понятно, какому суммарному размеру должен соответствовать
		// суммарный вес.
		assert(SumWeight.Hor == 0 && SumWeight.Ver == 0);

		for (size_t st = 0; st < childsCount; st++)
		{
			View* const child = GetChild(st);
			const SizeType childDirSize = child->OnMeasure(availableSpace);

			newSize[ direction] += childDirSize[direction];
			newSize[!direction]  = std::max(newSize[!direction], childDirSize[!direction]);
		}
	}
	else
	{
		MeasureStruct availableSpace = {};
		availableSpace[!direction] = meas[!direction];
		availableSpace[ direction] = meas[ direction].ToLessThan();

		for (size_t st = 0; st < childsCount; st++)
		{
			View* const child = GetChild(st);

			MeasureStruct measChild = availableSpace;

			if (SumWeight[ direction] != 0 && child->Weight[ direction] != 0)
			{
				measChild[ direction].Size = meas[ direction].Size * child->Weight[ direction] / SumWeight[ direction];
				measChild[ direction].Type = MeasureType::Exactly;
			}
			if (SumWeight[!direction] != 0 && child->Weight[!direction] != 0)
			{
				measChild[!direction].Size = meas[!direction].Size * child->Weight[!direction] / SumWeight[!direction];
				measChild[!direction].Type = MeasureType::Exactly;
			}

			SizeType childDirSize = child->OnMeasure(measChild);

			// Не можем разместить ребёнка, не хватает места. Завершаем измерение.
			if (availableSpace[direction].Size < childDirSize[direction])
				break;
			
			newSize[ direction] += childDirSize[direction];
			newSize[!direction]  = std::max(newSize[!direction], childDirSize[!direction]);
			
			availableSpace[direction].Size -= childDirSize[direction];
		}
	}
	
	if (meas[!direction].Type == MeasureType::Exactly)
		newSize[!direction] = meas[!direction].Size;
	
	return newSize;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///									   Размещение
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void LinearLayout::OnLayout(const CoordType& coord)
{
	View::OnLayout(coord);
	if (Orientation == Direction::Vertical)
	{
		LayoutDirection<Direction::Vertical>(coord);
	}
	else if (Orientation == Direction::Horizontal)
	{
		LayoutDirection<Direction::Horizontal>(coord);
	}
	else
	{
		assert(!"Not implemented");
	}
}

template <Direction direction>
void LinearLayout::LayoutDirection(const CoordType& coord)
{
	CoordType childPos = Pos;
	const size_t childrenCount = GetChildrenCount();
	for (size_t st = 0; st < childrenCount; st++)
	{
		View* const child = GetChild(st);
		child->OnLayout(childPos);
		childPos[ direction] += child->GetSize()[ direction];
	}
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///								   Управление детьми
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void LinearLayout::AddChild(View* const child)
{
	Childs.push_back(child);
}

void LinearLayout::RemoveAllChildren()
{
	Childs.clear();
}

View* const LinearLayout::GetChild(csize_t index)
{
	return Childs.at(index);
}

size_t LinearLayout::GetChildrenCount() const
{
	return Childs.size();
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///