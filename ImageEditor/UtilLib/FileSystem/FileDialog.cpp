#include "../Linux.h"
#include "FileDialog.h"

using namespace UtilLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

void UtilLib::OpenFileDialog(char* const filePathBuffer, const size_t bufferSize)
{
    ssize_t readCount = ExecProcessAndWait("zenity --file-selection", filePathBuffer, bufferSize);
    // Функция read добавляет \n в конец пути. Убираем его.
    filePathBuffer[readCount - 1] = '\0';
}

void UtilLib::SaveFileDialog(char* const filePathBuffer, const size_t bufferSize)
{
    ssize_t readCount = ExecProcessAndWait(
        "zenity --file-selection --confirm-overwrite --save --filename=untitled.png",
        filePathBuffer, bufferSize);
    // Функция read добавляет \n в конец пути. Убираем его.
    filePathBuffer[readCount - 1] = '\0';
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///