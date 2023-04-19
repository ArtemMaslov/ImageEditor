#pragma once

#include <cassert>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <UtilLib/General.h>
#include "../SizePair.h"

#include "Drawable.h"
#include "Color.h"
#include "Text.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	class CanvasType : public IRender, public IRenderTarget
	{
	public:
		CanvasType();

		inline void SetSize(const SizeType& newSize);

		void DrawLine(const CoordType& p1, const CoordType& p2, const Color& color);
		
		void DrawCircle(CoordType center, cuint_t radius, const Color& color, 
						cuint_t pointsCount = DefaultCirclePointsCount);
		
		void DrawRectangle(const CoordType& leftTop, cint_t width, cint_t height, const Color& color);

		void DrawPoint(const CoordType& point, const Color& color);

		void Clear();

        virtual void Render(sf::RenderTarget& target) final;

		virtual void Render(IRender& drawable) final;

	public:
		static const cuint_t DefaultCirclePointsCount = 30; 

	public:
		CoordType Pos = {0, 0};

	private:
		SizeType Size = {0, 0};

		sf::RenderTexture Texture;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	void CanvasType::SetSize(const SizeType& newSize)
	{
		Size = newSize;
		Texture.create(Size.Hor, Size.Ver);
	}
}
		
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///