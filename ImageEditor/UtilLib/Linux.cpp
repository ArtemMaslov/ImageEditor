#include "Linux.h"

#include <cstdio>
#include <cstdlib>

#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>

using namespace UtilLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

Pipe::Pipe()
{
    if (pipe(reinterpret_cast<int*>(&ReadDescriptor)) == -1)
    {
        fprintf(stderr, "Ошибка открытия pipe()\n");
        std::abort();
    }
}

Pipe::~Pipe()
{
    if (close(ReadDescriptor) == -1 ||
        close(WriteDescriptor) == -1)
    {
        fprintf(stderr, "Ошибка закрытия pipe.\n");
        std::abort();
    }
}

bool Pipe::CanRead()
{
    struct pollfd fd = 
    {
        .fd      = ReadDescriptor,
        .events  = POLLIN,
        .revents = 0
    };

    if (poll(&fd, 1, 0) == -1)
    {
        fprintf(stderr, "Ошибка выполнения poll().\n");
        std::abort(); 
    }

    if ((fd.revents & POLLERR) > 0)
    {
        fprintf(stderr, "Ошибка внутри pipe. Возможно дескриптор чтения был закрыт перед дескриптором записи.\n");
        std::abort(); 
    }
    if ((fd.revents & POLLNVAL) > 0)
    {
        fprintf(stderr, "Не правильный запрос. Дескриптор файла закрыт.\n");
        std::abort(); 
    }

    return (fd.revents & POLLIN) > 0;
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

ssize_t UtilLib::ExecProcessAndWait(cptr cmd, char* const buffer, size_t bufferSize)
{
    Pipe pipe;

    pid_t id = fork();
    if (id == -1)
    {
        fprintf(stderr, "Ошибка fork(). Не удалось создать дочерний процесс.\n");
        std::abort();
    }
    else if (id == 0) // Ребёнок
    {
        if (dup2(pipe.WriteDescriptor, STDOUT_FILENO) == -1)
        {
            fprintf(stderr, "Ошибка dup2() перенаправления pipe.WriteDescriptor на stdout.\n");
            std::abort();
        }
        pipe.~Pipe();
        
        int status = execlp("/bin/bash", "/bin/bash", "-c", cmd, NULL);
        if (status == -1)
        {
            fprintf(stderr, "Ошибка вызова execlp().\n");
            std::abort();
        }
        // Не достигается.
        return 0;
    }
    else // Родитель
    {
        int exitCode = 0;
        waitpid(id, &exitCode, 0);
        if (WEXITSTATUS(exitCode) == -1)
        {
            fprintf(stderr, "Ошибка завершения дочернего процесса.\n");
            std::abort();
        }

        size_t readCount = 0;
        // Читаем результат выполнения дочернего процесса, если он успешно завершен.
        // Если пользователь не выбрал файл в файловом диалоге zenity, то процесс ничего
        // не пишет в pipe, происходит зависание.

        if (pipe.CanRead())
            readCount = read(pipe.ReadDescriptor, buffer, bufferSize);
        return readCount;
    }
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///