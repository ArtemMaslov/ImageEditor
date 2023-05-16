#include <cmath>

#include <SFML/Graphics.hpp>

#include <ViewLib/SizePair.h>

#include "Filter.h"

using namespace ImageEditor;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

BrightnessFilter::BrightnessFilter(int defaultDelta) :
    Delta(defaultDelta)
{
}

BlurFilter::BlurFilter(uint_t defaultSquareSize) :
    SquareSize(defaultSquareSize)
{
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void BrightnessFilter::Apply(ViewLib::CanvasType& canvas)
{
    sf::Image image = canvas.GetTexture().copyToImage();

    ViewLib::SizePair imageSize = image.getSize();
    for (size_t y = 0; y < static_cast<size_t>(imageSize.Ver); y++)
    {
        for (size_t x = 0; x < static_cast<size_t>(imageSize.Hor); x++)
        {
            ViewLib::Color pixelColor = image.getPixel(x, y);
            pixelColor += Delta;
            image.setPixel(x, y, pixelColor);
        }
    }

    sf::RenderTexture& texture = canvas.GetRenderTexture();
    sf::Texture newTexture;
    newTexture.loadFromImage(image);
    sf::Sprite sprite(newTexture, sf::IntRect{0, 0, imageSize.Hor, imageSize.Ver});
    texture.draw(sprite);
    texture.display();
}

void BlurFilter::Apply(ViewLib::CanvasType& canvas)
{
    sf::Image image    = canvas.GetTexture().copyToImage();
    sf::Image newImage = image;

    const size_t boundaryOffset = SquareSize / 2;
    const size_t boundaryDelta  = boundaryOffset % 2;

    ViewLib::SizePair imageSize = image.getSize();
    for (size_t curY = 0; curY < static_cast<size_t>(imageSize.Ver); curY++)
    {
        for (size_t curX = 0; curX < static_cast<size_t>(imageSize.Hor); curX++)
        {
            // left, top - начало квадрата усреднения.
            // right, bottom - первый пиксель за квадратом.
            ssize_t left = static_cast<ssize_t>(curX) - static_cast<ssize_t>(boundaryOffset);
            if (left < 0)
                left = 0;

            // + boundaryDelta, потому что если 5 пикселей, то boundaryOffset = 2, тогда ширина будет 4, а должна быть 5.
            // curX - boundaryOffset = 3 - 2 = 1
            //   ^  curX = 3
            //   |   ^
            //   |   |  curX + boundaryOffset + boundaryDelta = 3 + 2 + 1 = 6
            //   |   |     ^
            // 0 * * * * * 0
            // 0 * * * * * 0
            //      ...
            // 0 * * * * * 0
            // 0 1 2 3 4 5 6

            size_t right = curX + boundaryOffset + boundaryDelta;
            if (right > static_cast<size_t>(imageSize.Hor))
                right = static_cast<size_t>(imageSize.Hor);

            ssize_t top = static_cast<ssize_t>(curY) - static_cast<ssize_t>(boundaryOffset);
            if (top < 0)
                top = 0;

            size_t bottom = curY + boundaryOffset + boundaryDelta;
            if (bottom > static_cast<size_t>(imageSize.Ver))
                bottom = static_cast<size_t>(imageSize.Ver);

            size_t meanR = 0;
            size_t meanG = 0;
            size_t meanB = 0;
            size_t pixelsCount = 0;

            for (size_t squareY = top; squareY < bottom; squareY++)
            {
                for (size_t squareX = left; squareX < right; squareX++)
                {
                    ViewLib::Color color = image.getPixel(squareX, squareY);
                    meanR += color.R;
                    meanG += color.G;
                    meanB += color.B;
                    pixelsCount++;
                }
            }

            meanR = std::round(static_cast<float>(meanR) / static_cast<float>(pixelsCount));
            meanG = std::round(static_cast<float>(meanG) / static_cast<float>(pixelsCount));
            meanB = std::round(static_cast<float>(meanB) / static_cast<float>(pixelsCount));

            newImage.setPixel(curX, curY, sf::Color{static_cast<sf::Uint8>(meanR), 
                                                    static_cast<sf::Uint8>(meanG), 
                                                    static_cast<sf::Uint8>(meanB)});
        }
    }

    sf::RenderTexture& texture = canvas.GetRenderTexture();
    sf::Texture newTexture;
    newTexture.loadFromImage(newImage);
    sf::Sprite sprite(newTexture, sf::IntRect{0, 0, imageSize.Hor, imageSize.Ver});
    texture.draw(sprite);
    texture.display();    
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///