#include "Text.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

bool Font::Loaded = false;
sf::Font Font::sfFont;

Font Font::GetFont()
{
    if (!Loaded)
        LoadFromFile("Liberation Sans/LiberationSans-Regular.ttf");
    
    return {};
}

void Font::LoadFromFile(const std::string& FilePath)
{
    sfFont.loadFromFile(FilePath);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

Text::Text() :
    Value(),
    sfText()
{
    SetFont(Font::GetFont());
    SetFontSize(20);
    SetColor(Color(0, 0, 0));
}

void Text::UpdateString()
{
    sfText.setString(Value);
}

SizeType Text::MeasureSize()
{
    UpdateString();

    // Библиотека измеряет текст впритык. При этом, например, линия подчёркивания вылезает
    // за границу измеренной области. Поля left и top не равны 0, чтобы скомпенсировать 
    // возможное вылезание некоторых штрихов за границы текста считаем, что поля принадлежат
    // тексту, поэтому прибавляем размер полей с двух сторон.
    sf::FloatRect textRect = sfText.getLocalBounds();
    textRect.width  += textRect.left * 2;
    
    const sf::Font* font = sfText.getFont();
    unsigned int fontSize = sfText.getCharacterSize();

    textRect.height = font->getLineSpacing(fontSize) * GetLinesCount() + 
                      font->getUnderlinePosition(fontSize) + 
                      font->getUnderlineThickness(fontSize);

    return textRect;
}

void Text::FillBoundaries(sf::RenderTarget& target)
{
    UpdateString();
    
    sf::FloatRect textRect = sfText.getLocalBounds();
    textRect.width  += textRect.left * 2;
    textRect.left    = 0;
    textRect.height += textRect.top * 2;
    textRect.top     = 0;
    sf::RectangleShape l1 = sf::RectangleShape(sf::Vector2f(textRect.width, textRect.height));
    l1.setFillColor(sf::Color(200, 160, 200));
    l1.setPosition(textRect.left, textRect.top);
    target.draw(l1);
}

void Text::Render(sf::RenderTarget& target)
{
    UpdateString();
    FillBoundaries(target);

    target.draw(sfText);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///