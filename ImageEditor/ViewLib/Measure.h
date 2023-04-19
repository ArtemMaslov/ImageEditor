#pragma once

#include <cassert>

#include <SFML/Graphics.hpp>

#include "General.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	enum class MeasureType
	{
		// View может быть настолько большим, насколько захочет.
		Infty,
		// View должен быть меньше указанного размера.
		LessThan,
		// View должен быть указанного размера.
		Exactly,
	};
	
	/**
	* @brief Структура для измерения View.
	*/
	struct MeasureUnit
	{
	public:
		MeasureType Type;
		dim_t       Size;

		static inline MeasureUnit ConstructInfty() noexcept;

		static inline MeasureUnit ConstructExactly(cdim_t size) noexcept;

		static inline MeasureUnit ConstructLessThan(cdim_t size) noexcept;

		/**
		 * @brief  Преобразует режим измерения по правилам:
		 *             Infty    -> Infty
		 *             Exactly  -> LessThan
		 *             LessThan -> LessThan
		 * @return Преобразованный режим измерения.
		 */
		inline MeasureUnit ToLessThan() const noexcept;
	};

	struct MeasureStruct
	{
		// Горизонтальный размер.
		MeasureUnit Hor;
		// Вертикальный размер.
		MeasureUnit Ver;

		inline MeasureUnit& operator [] (const Direction direction) noexcept;
		
		inline const MeasureUnit& operator [] (const Direction direction) const noexcept;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	MeasureUnit MeasureUnit::ConstructInfty() noexcept
	{
		return MeasureUnit
		{
			.Type = MeasureType::Infty,
			.Size = (dim_t)-1
		};
	}
	
	MeasureUnit MeasureUnit::ConstructExactly(cdim_t size) noexcept
	{
		return MeasureUnit
		{
			.Type = MeasureType::Exactly,
			.Size = size
		};
	}

	MeasureUnit MeasureUnit::ConstructLessThan(cdim_t size) noexcept
	{
		return MeasureUnit
		{
			.Type = MeasureType::LessThan,
			.Size = size
		};
	}

	MeasureUnit MeasureUnit::ToLessThan() const noexcept
	{
		if (Type == MeasureType::Infty)
		{
			return *this;
		}
		else
		{
			return MeasureUnit
			{
				.Type = MeasureType::LessThan,
				.Size = Size
			};
		}
	} 

	MeasureUnit& MeasureStruct::operator [] (const Direction direction) noexcept
	{
		return const_cast<MeasureUnit&>(
			   const_cast<const MeasureStruct&>(*this)[direction]);
	}
	
	const MeasureUnit& MeasureStruct::operator [] (const Direction direction) const noexcept
	{
		if (direction == Direction::Horizontal)
			return Hor;
		else
			return Ver;
	}
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///