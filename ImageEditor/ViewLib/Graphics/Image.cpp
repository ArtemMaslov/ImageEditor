#include "Image.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void Image::LoadFromFile(const std::string& filePath)
{
    sfImage.loadFromFile(filePath);
    sfTexture.loadFromImage(sfImage);
    sfSprite.setTexture(sfTexture);
}

void Image::Render(sf::RenderTarget& target)
{
    target.draw(sfSprite);
}

void Image::SetStretchSize(SizeType newSize)
{
    sf::Vector2u imageSize = sfImage.getSize();
    sfSprite.setScale((float)newSize.Hor / (float)imageSize.x, (float)newSize.Ver / (float)imageSize.y);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///