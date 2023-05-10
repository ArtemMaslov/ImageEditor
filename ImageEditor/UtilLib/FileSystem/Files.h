#pragma once

#include <stdio.h>

#include "../General.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace UtilLib
{
    class File
    {
    public:
        File(cptr filePath, cptr mode);

        File(const File&) = delete;
        File(File&&) = delete;
        File& operator = (const File&) = delete;
        File& operator = (File&&) = delete;

        ~File();

        inline size_t GetSize();

        inline FILE* GetRawPointer();

        void* Read();

    private:
        FILE* FilePtr = nullptr;
        char* Data    = nullptr;
        size_t Size   = 0;
    };
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace UtilLib
{
    FILE* File::GetRawPointer()
    {
        return FilePtr;
    }

    size_t File::GetSize()
    {
        return Size;
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///