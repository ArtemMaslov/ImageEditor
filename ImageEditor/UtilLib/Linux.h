#pragma once

#include <sys/types.h>

#include "General.h"

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace UtilLib
{
    class Pipe
    {
    public:
        Pipe();

        Pipe(const Pipe&) = delete;
        Pipe(Pipe&&) = delete;
        Pipe& operator = (const Pipe&) = delete;
        Pipe& operator = (Pipe&&) = delete;

        ~Pipe();

        bool CanRead();

    public:
        int ReadDescriptor = -1;
        int WriteDescriptor = -1;
    };

    ssize_t ExecProcessAndWait(cptr cmd, char* const buffer, size_t bufferSize);
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///