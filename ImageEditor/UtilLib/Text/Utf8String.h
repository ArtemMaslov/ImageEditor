#pragma once

#include <string>
#include <iterator>
#include <cstddef>
#include <concepts>
#include <charconv>

#include <SFML/System.hpp>

#include "../General.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace UtilLib
{
    class Utf8Iterator;
    class Utf8Char;

    class Utf8String
    {
        friend bool operator == (const Utf8String& left, const Utf8String& right);
        
    public:
        Utf8String();
        
        Utf8String(cptr utf8Str);

        Utf8String(const std::string& utf8Str);

        Utf8String(std::string&& utf8Str);
        
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
        
        void operator += (cptr utf8Sym);

        void operator += (uint32_t utf8Sym);

        void operator += (const std::string& utf8Str);

        void Erase(size_t index, size_t length);

        void EraseBack();

        const char* GetRawData() const noexcept;
        
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

        enum class ConversionError
        {
            // Нет ошибок.
            NoErrors,
            // Найден не правильный символ.
            NotAllowedChar,
            // Знак числа указан несколько раз.
            DoubleSign,
            // Несколько раз встречен символ разделения целой и дробной частей ',' или '.'.
            DoubleSeparator,
            // Число слишком большое, переполнение.
            Overflow,
        };

        template <typename T>
        ConversionError ToNumber(T& result);

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

        Utf8Iterator Begin();

        Utf8Iterator End();
        
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

        operator sf::String() const;
        
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

    private:
        std::string Value;
        size_t Utf8SymCount = 0;
    };
    
    bool operator == (const Utf8String& left, const Utf8String& right);
    
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

    class Utf8Iterator
    {
        friend class Utf8String;
        friend bool operator == (const Utf8Iterator& left, const Utf8Iterator& right);
        friend std::strong_ordering operator <=> (const Utf8Iterator& left, const Utf8Iterator& right);
        
    private:
        Utf8Iterator(std::string::iterator begin, std::string::iterator end);

    public:
        Utf8Iterator();

        Utf8Char operator *() const;

        Utf8Iterator& operator ++();
        
        Utf8Iterator operator ++(int);

        Utf8Iterator& operator --();
        
        Utf8Iterator operator --(int);

        Utf8Iterator& operator += (csize_t utf8CharsCount);
        
        Utf8Iterator& operator -= (csize_t utf8CharsCount);

    private:
        // Найти начало символа
        void Previous();

        uint32_t Decode() const;

        void Next();

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::make_signed_t<size_t>;
        using value_type = Utf8Char;
        using pointer = Utf8Char*;
        using reference = Utf8Char&;

    private:
        std::string::iterator CurrentSymbol;
        std::string::iterator EndSymbol;
        static constexpr uint32_t Utf8InvalidChar = 0;
    };
    
    bool operator == (const Utf8Iterator& left, const Utf8Iterator& right);
    std::strong_ordering operator <=> (const Utf8Iterator& left, const Utf8Iterator& right);

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

    class Utf8Char
    {
        friend class Utf8Iterator;
    private:
        Utf8Char(uint32_t value);

    public:
        operator uint32_t() const;
        
    private:
        uint32_t Value = 0;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace UtilLib
{
    template <typename T>
    Utf8String::ConversionError Utf8String::ToNumber(T& result)
    {
        std::from_chars_result status = std::from_chars(Value.begin().base(), Value.end().base(), result);

        if (status.ptr == Value.end().base() && status.ec == std::errc())
            return ConversionError::NoErrors;
        else if (status.ec == std::errc::result_out_of_range)
            return ConversionError::Overflow;
        else //if (status.ec == std::errc::invalid_argument)
            return ConversionError::NotAllowedChar;
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///