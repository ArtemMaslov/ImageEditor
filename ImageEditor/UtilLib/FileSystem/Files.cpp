#include <exception>

#include "Files.h"

using namespace UtilLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

File::File(cptr filePath, cptr mode)
{
    FilePtr = fopen(filePath, mode);
    if (!FilePtr)
    {
        throw std::exception();
    }

    fseek(FilePtr, 0, SEEK_END);
    Size = ftell(FilePtr);
    fseek(FilePtr, 0, SEEK_SET);
}

File::~File()
{
    fclose(FilePtr);
    if (Data)
        delete [] Data;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void* File::Read()
{
    Data = new char[Size + 1];
    fread(Data, 1, Size, FilePtr);
    return Data;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///