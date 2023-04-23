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
    
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
    
    class Text : public IRender
    {
    public:
        Text();

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

        inline size_t GetFontSize();

        inline void SetFontSize(csize_t size);

        inline void SetFont(const Font& font);

        inline void SetColor(const Color& color);
        
        inline dim_t GetLineHeight();
        
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

        inline size_t GetLinesCount();

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

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
    size_t Text::GetFontSize()
    {
        return sfText.getCharacterSize();
    }

    void Text::SetFontSize(csize_t size)
    {
        sfText.setCharacterSize(size);
        
        const sf::Font* const fontPtr = sfText.getFont();
        if (fontPtr)
            LineHeight = fontPtr->getLineSpacing(GetFontSize());
    }

    void Text::SetFont(const Font& font)
    {
        sfText.setFont(font.sfFont);
        
        LineHeight = font.sfFont.getLineSpacing(GetFontSize());
    }

    void Text::SetColor(const Color& color)
    {
        sfText.setFillColor(color);
    }
    
    dim_t Text::GetLineHeight()
    {
        return LineHeight;
    }

    size_t Text::GetLinesCount()
    {
        return std::count(Value.Begin(), Value.End(), '\n') + 1;
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///