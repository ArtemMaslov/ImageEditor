#pragma once

#include <SFML/Graphics.hpp>

#include <UtilLib/General.h>
#include <UtilLib/Text/Utf8String.h>

#include "../Measure.h"
#include "../SizePair.h"

#include "Drawable.h"
#include "Color.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    class Text;

    class Font
    {
        friend class Text;
    public:
        static Font GetFont();

    private:
        static void LoadFromFile(const std::string& FilePath);

    private:
        static bool     Loaded;
        static sf::Font sfFont;
    };
    
    class Text : public IRender
    {
    public:
        Text();

        inline void SetFont(const Font& font);

        inline size_t GetFontSize();

        inline dim_t GetLineHeight();

        inline void SetFontSize(csize_t size);

        inline void SetColor(const Color& color);

        SizeType MeasureSize();
        
    private:
        virtual void Render(sf::RenderTarget& target) final;
        
        void UpdateString();

    public:
        UtilLib::Utf8String Value;

    private:
        sf::Text sfText;
        size_t LineHeight = 0;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
    void Text::SetFont(const Font& font)
    {
        sfText.setFont(font.sfFont);
        
        LineHeight = font.sfFont.getLineSpacing(GetFontSize());
    }

    size_t Text::GetFontSize()
    {
        return sfText.getCharacterSize();
    }

    dim_t Text::GetLineHeight()
    {
        return LineHeight;
    }
    
    void Text::SetFontSize(csize_t size)
    {
        sfText.setCharacterSize(size);
        
        const sf::Font* const fontPtr = sfText.getFont();
        if (fontPtr)
            LineHeight = fontPtr->getLineSpacing(GetFontSize());
    }

    void Text::SetColor(const Color& color)
    {
        sfText.setFillColor(color);
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///