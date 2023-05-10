#include "Linux.h"

#include <exception>

#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

using namespace UtilLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

Pipe::Pipe()
{
    if (pipe(reinterpret_cast<int*>(&ReadDescriptor)) == -1)
        throw std::exception();
}

Pipe::~Pipe()
{
    if (close(ReadDescriptor) == -1 ||
        close(WriteDecriptor) == -1)
    {
        // Записать в лог файл сообщение с ошибкой.
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ssize_t UtilLib::ExecProcessAndWait(cptr cmd, char* const buffer, size_t bufferSize)
{
    Pipe pipe;

    pid_t id = fork();
    if (id == -1)
    {
        throw std::exception();
    }
    else if (id == 0) // Ребёнок
    {
        if (dup2(pipe.WriteDecriptor, STDOUT_FILENO) == -1)
            throw std::exception();
        pipe.~Pipe();
        
        int status = execlp("/bin/bash", "/bin/bash", "-c", cmd, NULL);
        if (status == -1)
            throw std::exception();
    }
    else // Родитель
    {
        int exitCode = 0;
        waitpid(id, &exitCode, 0);
        if (WEXITSTATUS(exitCode) == -1)
            throw std::exception();
    }

    ssize_t readCount = read(pipe.ReadDescriptor, buffer, bufferSize);
    return readCount;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///