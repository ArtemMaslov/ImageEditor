#pragma once

#include <string>
#include <iterator>
#include <cstddef>
#include <concepts>

#include <SFML/System.hpp>

#include "../General.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace UtilLib
{
    class Utf8String
    {
        friend bool operator == (const Utf8String& left, const Utf8String& right);
        
    public:
        Utf8String();
        
        Utf8String(cptr utf8Str);

        Utf8String(const std::string& utf8Str);
        
        void operator += (cptr utf8Sym);

        void operator += (uint32_t utf8Sym);

        void operator += (const std::string& utf8Str);

        void Erase(size_t index, size_t length);

        void EraseBack();

        operator sf::String() const;

    private:
        // Найти начало символа
        template <typename Iter>
        Iter FindSymbolStart(Iter afterEndOfSym);

    private:
        std::string Value;
        size_t Utf8SymCount = 0;
    };
    
    bool operator == (const Utf8String& left, const Utf8String& right);
    
    class Utf8Iterator : std::bidirectional_iterator_tag
    {
    public:
        Utf8Iterator();

        uint32_t operator *() const;

        Utf8Iterator& operator ++();
        
        Utf8Iterator operator ++(int);

        Utf8Iterator& operator --();
        
        Utf8Iterator operator --(int);

        using difference_type = int;
        using value_type = uint32_t;        

    private:

    };

    bool operator == (const Utf8Iterator& left, const Utf8Iterator& right);

    static_assert(std::bidirectional_iterator<Utf8Iterator>);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace UtilLib
{
    template <typename Iter>
    Iter Utf8String::FindSymbolStart(Iter afterEndOfSym)
    {
        const char bitMask1 = 0b1000'0000;
        const char bitMask2 = 0b0100'0000;

        afterEndOfSym--;

        // Если 0b10xx_xxxx, то это не конец символа, сдвигаемся влево.
        while ((*afterEndOfSym & bitMask1) == bitMask1 && (*afterEndOfSym & bitMask2) == 0)
            afterEndOfSym--;
        
        return afterEndOfSym;
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///