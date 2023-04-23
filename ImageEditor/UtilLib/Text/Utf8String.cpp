#include <cassert>
#include <array>

#include "Utf8String.h"

using namespace UtilLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

static_assert(std::bidirectional_iterator<Utf8Iterator>);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnarrowing"
// Количество байт после первого.
// -1 - не правильная последовательность.
static const uint8_t Utf8TrailingBytesCount[256] =
{
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    3,  3,  3,  3,  3,  3,  3,  3, -1, -1, -1, -1, -1, -1, -1, -1,
};

static const uint8_t Utf8TrailingBytesInvalid = -1;
#pragma GCC diagnostic pop

static const uint32_t Utf8DecodeOffset[4] =
{
    0x00000000, 0x00003080, 0x000E2080, 0x03C82080
};

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

Utf8String::Utf8String() :
    Value()
{
}

Utf8String::Utf8String(cptr utf8Str) :
    Value(utf8Str),
    Utf8SymCount(sf::Utf8::count(Value.begin(), Value.end()))
{
}

Utf8String::Utf8String(const std::string& utf8Str) :
    Value(utf8Str),
    Utf8SymCount(sf::Utf8::count(Value.begin(), Value.end()))
{
}

void Utf8String::operator += (cptr utf8Str)
{
    size_t size1 = Value.size();
    Value.append(utf8Str);
    size_t size2 = Value.size();
    
    Utf8SymCount += sf::Utf8::count(Value.end() - (size2 - size1), Value.end());
}

void Utf8String::operator += (uint32_t utf8Sym)
{
    std::array<char, 4> encoded = {};
    auto end = sf::Utf8::encode(utf8Sym, encoded.begin());
    size_t s =  end - encoded.begin();

    Value.append(encoded.data(), s);
    Utf8SymCount++;
}

void Utf8String::operator += (const std::string& utf8Str)
{
    Value.append(utf8Str);
    Utf8SymCount += sf::Utf8::count(utf8Str.begin(), utf8Str.end());
}

void Utf8String::Erase(size_t index, size_t length)
{
    assert(index < Utf8SymCount);
    assert(index + length <= Utf8SymCount);

    Utf8Iterator eraseStart = Begin();
    eraseStart += index;
    Utf8Iterator eraseEnd = eraseStart;
    eraseEnd += length;

    Value.erase(eraseStart.CurrentSymbol, eraseEnd.CurrentSymbol);
    Utf8SymCount -= length;
}

void Utf8String::EraseBack()
{
    if (Value.size() == 0)
        return;
    
    Utf8Iterator end = End();
    end.Previous();

    Value.erase(end.CurrentSymbol, end.EndSymbol);
    Utf8SymCount--;
}

cptr Utf8String::GetRawData() const noexcept
{
    return Value.data();
}

int64_t Utf8String::ToInt()
{
    Utf8Iterator current = Begin();
    Utf8Iterator end = End();
    for (; current < end; current++)
    {

    }

    return 0;
}

Utf8Iterator Utf8String::Begin()
{
    return Utf8Iterator(Value.begin(), Value.end());
}

Utf8Iterator Utf8String::End()
{
    return Utf8Iterator(Value.end(), Value.end());
}

Utf8String::operator sf::String() const
{
    return sf::String::fromUtf8(Value.begin(), Value.end());
}

bool UtilLib::operator == (const Utf8String& left, const Utf8String& right)
{
    return left.Value == right.Value;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

Utf8Iterator::Utf8Iterator(std::string::iterator begin, std::string::iterator end) :
    CurrentSymbol(begin),
    EndSymbol(end)
{
}

Utf8Iterator::Utf8Iterator()
{
    assert(!"Check state");
}

Utf8Char Utf8Iterator::operator *() const
{
    uint32_t utf8Char = Decode(CurrentSymbol);
    return Utf8Char(utf8Char);
}

Utf8Iterator& Utf8Iterator::operator ++()
{
    Next();
    return *this;
}

Utf8Iterator Utf8Iterator::operator ++(int)
{
    Utf8Iterator current = *this;
    Next();
    return current;
}

Utf8Iterator& Utf8Iterator::operator --()
{
    Previous();
    return *this;
}

Utf8Iterator Utf8Iterator::operator --(int)
{
    Utf8Iterator current = *this;
    Previous();
    return current;
}

Utf8Iterator& Utf8Iterator::operator += (csize_t utf8CharsCount)
{
    for (size_t st = 0; st < utf8CharsCount; st++)
        Next();
    return *this;
}

Utf8Iterator& Utf8Iterator::operator -= (csize_t utf8CharsCount)
{
    for (size_t st = 0; st < utf8CharsCount; st++)
        Previous();
    return *this;
}

void Utf8Iterator::Previous()
{
    for (size_t bytesCount = 0; bytesCount < 4; bytesCount++)
    {
        CurrentSymbol--;
        uint8_t trailingBytes = Utf8TrailingBytesCount[static_cast<uint8_t>(*CurrentSymbol)];
        if (trailingBytes != Utf8TrailingBytesInvalid && CurrentSymbol + trailingBytes < EndSymbol)
            return; // Нашли верную последовательность байт, образующих utf8 символ.
    }

    // Поддерживается кодировка, содержащая только 4 байта.
    throw std::exception();
}

void Utf8Iterator::Next()
{
    uint32_t result = 0;
    uint8_t trailingBytes = Utf8TrailingBytesCount[static_cast<uint8_t>(*CurrentSymbol)];

    if (trailingBytes == Utf8TrailingBytesInvalid || CurrentSymbol + trailingBytes >= EndSymbol)
        throw std::exception();

    CurrentSymbol += 1 + trailingBytes;
}

uint32_t Utf8Iterator::Decode(std::string::iterator symStart) const
{
    uint32_t result = 0;
    uint8_t trailingBytes = Utf8TrailingBytesCount[static_cast<uint8_t>(*symStart)];

    if (trailingBytes == Utf8TrailingBytesInvalid || symStart + trailingBytes >= EndSymbol)
    {
        // Не верная последовательность символов.
        throw std::exception();
    }

    // Декодируем utf8 символ.
    switch (trailingBytes)
    {
        case 4:
            result += static_cast<uint8_t>(*symStart++); 
            result <<= 6;
            [[fallthrough]];
        case 3:
            result += static_cast<uint8_t>(*symStart++); 
            result <<= 6;
            [[fallthrough]];
        case 2:
            result += static_cast<uint8_t>(*symStart++); 
            result <<= 6;
            [[fallthrough]];
        case 1:
            result += static_cast<uint8_t>(*symStart++); 
            result <<= 6;
            [[fallthrough]];
        case 0:
            result += static_cast<uint8_t>(*symStart++);
    }

    result -= Utf8DecodeOffset[trailingBytes];

    return result;
}

bool UtilLib::operator == (const Utf8Iterator& left, const Utf8Iterator& right)
{
    if (left.EndSymbol != right.EndSymbol)
        throw new std::exception();

    return left.CurrentSymbol == right.CurrentSymbol;
}

std::strong_ordering UtilLib::operator <=> (const Utf8Iterator& left, const Utf8Iterator& right)
{
    if (left.EndSymbol != right.EndSymbol)
        throw new std::exception();

    return left.CurrentSymbol <=> right.CurrentSymbol;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

Utf8Char::Utf8Char(uint32_t value) :
    Value(value)
{
}

Utf8Char::operator uint32_t() const
{
    return Value;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///