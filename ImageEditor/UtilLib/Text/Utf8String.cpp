#include <cassert>
#include <array>

#include "Utf8String.h"

using namespace UtilLib;

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
    assert(length > 0);
    assert(index < Utf8SymCount);
    assert(index + length <= Utf8SymCount);

    uint32_t errCode = 0;
    auto iter = Value.begin();
    auto end  = Value.end();

    std::string::iterator eraseStart;
    std::string::iterator eraseEnd;    

    // Перемещаемся на позицию index.
    for (size_t st = 0; st < index; st++)
    {
        sf::Utf8::decode(iter, end, errCode);
        if (errCode == 0)
            throw std::exception();
    }
    eraseStart = iter;

    // Перемещаемся на позицию index + length.
    for (size_t st = 0; st < length; st++)
    {
        sf::Utf8::decode(iter, end, errCode);
        if (errCode == 0)
            throw std::exception();
    }
    eraseEnd = iter;

    Value.erase(eraseStart, eraseEnd);
    Utf8SymCount -= length;
}

void Utf8String::EraseBack()
{
    assert(Value.size() > 0);
    auto lastSymStart = FindSymbolStart(Value.end());

    Value.erase(lastSymStart, Value.end());
    Utf8SymCount--;
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