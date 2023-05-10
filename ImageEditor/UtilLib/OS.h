#pragma once

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

#if defined(MSVC)
    #define FUNCT_NAME __FUNCSIG__
    #define FILE_NAME  __FILE__
    #define LINE       __LINE__
#elif defined(GCC) || defined(CLANG)
    #define FUNCT_NAME __PRETTY_FUNCTION__
    #define FILE_NAME  __FILE__
    #define LINE       __LINE__
#else
    #error Not unknow complier
#endif

#if defined(LINUX)
    #include "Linux.h"
#else
    #error Not unknow target OS
#endif

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///