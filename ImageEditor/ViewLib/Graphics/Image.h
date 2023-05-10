#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "../Measure.h"
#include "../SizePair.h"

#include "Drawable.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    class Image : public IRender
    {
    public:
        void LoadFromFile(const std::string& filePath);

        virtual void Render(sf::RenderTarget& target) final;

        inline SizeType GetSize();

        void SetStretchSize(SizeType newSize);

    private:
        sf::Texture sfTexture;
        sf::Sprite  sfSprite;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    SizeType Image::GetSize()
    {
        return sfTexture.getSize();
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///