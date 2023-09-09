#include <cstdlib>

#include "Files.h"

using namespace UtilLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

File::File(cptr filePath, cptr mode)
{
    FilePtr = fopen(filePath, mode);
    if (!FilePtr)
    {
        fprintf(stderr, "Ошибка открытия файла с помощью fopen().\n");
        std::abort();
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