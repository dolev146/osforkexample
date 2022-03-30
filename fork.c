#include <iostream>
#include <sys/wait.h> // for wait()
#include <unistd.h>   // for fork()

int main()
{

    pid_t parent = getpid();
    pid_t pid = fork();

    if (pid == -1)
    {
        // error, failed to fork()
        perror("can't fork");
        exit(1);
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        printf("status: %d", status);
    }
    else
    {
        // we are the child

        execv("/bin/ls",NULL);
        _exit(EXIT_FAILURE); // exec never returns
    }
    
    return 0;
}
