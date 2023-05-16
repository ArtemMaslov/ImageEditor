#pragma once
	
#include "General.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	struct SizePair
	{
        friend bool operator == (const SizePair& left, const SizePair& right);
        friend bool operator != (const SizePair& left, const SizePair& right);

		inline SizePair() noexcept {};

		inline SizePair(cdim_t hor, cdim_t ver) noexcept;

		inline SizePair(const sf::FloatRect& rect) noexcept;
		
		inline SizePair(const sf::Vector2u& vect) noexcept;

		inline SizePair(const sf::Vector2i& vect) noexcept;
		
		inline SizePair(const sf::Vector2f& vect) noexcept;

		inline operator sf::Vector2f() const noexcept;

		inline operator sf::Vector2u() const noexcept;

		inline dim_t& operator [] (const Direction direction) noexcept;
		
		inline const dim_t& operator [] (const Direction direction) const noexcept;

		inline void operator += (const SizePair& right);
		
		inline void operator -= (const SizePair& right);
		
		inline void operator *= (const SizePair& right);
		
		inline void operator /= (const SizePair& right);

		dim_t Hor = 0;
		dim_t Ver = 0;
	};
	
    inline bool operator == (const SizePair& left, const SizePair& right);
    inline bool operator != (const SizePair& left, const SizePair& right);

	using SizeType   = SizePair;
	using WeightType = SizePair;
	using CoordType  = SizePair;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	SizePair::SizePair(cdim_t hor, cdim_t ver) noexcept
	{
		Hor = hor;
		Ver = ver;
	}
	
	SizePair::SizePair(const sf::FloatRect& rect) noexcept
	{
		Hor = rect.width;
		Ver = rect.height;
	}
	
	SizePair::SizePair(const sf::Vector2u& vect) noexcept
	{
		Hor = vect.x;
		Ver = vect.y;
	}

	SizePair::SizePair(const sf::Vector2i& vect) noexcept
	{
		Hor = vect.x;
		Ver = vect.y;
	}
	
	SizePair::SizePair(const sf::Vector2f& vect) noexcept
	{
		Hor = vect.x;
		Ver = vect.y;
	}
	
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

	SizePair::operator sf::Vector2f() const noexcept
	{
		return sf::Vector2f(Hor, Ver);
	}

	SizePair::operator sf::Vector2u() const noexcept
	{
		return sf::Vector2u(Hor, Ver);
	}
		
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

	dim_t& SizePair::operator [] (const Direction direction) noexcept
	{
		return const_cast<dim_t&>(
			   const_cast<const SizePair&>(*this)[direction]);
	}
	
	const dim_t& SizePair::operator [] (const Direction direction) const noexcept
	{
		if (direction == Direction::Horizontal)
			return Hor;
		else
			return Ver;
	}
	
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
	
	void SizePair::operator += (const SizePair& right)
	{
		Hor += right.Hor;
		Ver += right.Ver;
	}
	
	void SizePair::operator -= (const SizePair& right)
	{
		Hor -= right.Hor;
		Ver -= right.Ver;
	}
	
	void SizePair::operator *= (const SizePair& right)
	{
		Hor *= right.Hor;
		Ver *= right.Ver;
	}
	
	void SizePair::operator /= (const SizePair& right)
	{
		Hor /= right.Hor;
		Ver /= right.Ver;
	}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

    bool operator == (const SizePair& left, const SizePair& right)
	{
		return left.Hor == right.Hor && left.Ver == right.Ver;
	}

    bool operator != (const SizePair& left, const SizePair& right)
	{
		return !(left == right);
	}
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///