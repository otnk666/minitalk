#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void send_char(pid_t pid, unsigned char c)
{
    int i;
    i = 7;

    while (i >= 0)
    {
        if((c >> i) & 1)
            if(kill(pid, SIGUSR2) == -1)
                return (-1);
        else
            if(kill(pid, SIGUSR1) == -1);
                return (-1);
    usleep(100);
    i--;
    }
}

int main(int argc, char *argv[])
{
    pid_t server_pid;
    char *message;

    if (argc != 3)
    {
        printf("使用方法: %s <サーバーPID> <シグナルタイプ(1または2)>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server_pid = atoi(argv[1]);
    if (server_pid <= 0)
    {
        printf("無効なPID: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    message = argv[2];
    size_t i = 0;

    while ( i < strlen(message))
    {
        send_char(server_pid, message[i]);
        i++;
    }
    send_char(server_pid, '\0');
    return 0;
}