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
    sfText.setStyle(sf::Text::Underlined);
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

    size_t   textHeight    = GetLineHeight();
    size_t   linesCount    = GetLinesCount();
    dim_t    desiredHeight = linesCount * textHeight;
    textRect.height = desiredHeight;

    return textRect;
}

void Text::Render(sf::RenderTarget& target)
{
    UpdateString();

    float lineSpacing = Font::GetFont().sfFont.getLineSpacing(sfText.getCharacterSize());
    float underlinePosition = Font::GetFont().sfFont.getUnderlinePosition(sfText.getCharacterSize());
    float underlineThickness = Font::GetFont().sfFont.getUnderlineThickness(sfText.getCharacterSize());

    sf::Vector2f pos = sfText.getPosition();
    sf::FloatRect textRect = sfText.getLocalBounds();
    textRect.width  += textRect.left * 2;
    textRect.left    = 0;
    textRect.height += textRect.top * 2;
    textRect.top     = 0;
    sf::RectangleShape* l1 = new sf::RectangleShape(sf::Vector2f(textRect.width, textRect.height));
    l1->setFillColor(sf::Color(200, 160, 200));
    l1->setPosition(textRect.left, textRect.top);
    target.draw(*l1);

    float h2 = 1;
    for (size_t st = 0; st < 9; st++)
    {
        h2 += lineSpacing;
        sf::RectangleShape* l2 = new sf::RectangleShape(sf::Vector2f(1000, h2));
        l2->setFillColor(sf::Color(100, 40 * (st + 1), 100));
        l2->setPosition(pos.x, pos.y);
        //target.draw(*l2);
        pos.y = h2;
    }

    target.draw(sfText);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///