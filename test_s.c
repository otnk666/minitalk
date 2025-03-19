#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void signal_handler(int signo)
{
    static unsigned char c = 0;
    static int bit = 0;

    if (signo == SIGUSR1)
        c = c << 1;
    else if (signo == SIGUSR2)
        c = c << 1 | 1;
    
    bit++;

    if (bit == 8)
    {
        if (c == 0)
            write(STDOUT_FILENO, "\n", 1);
        else
            write(STDOUT_FILENO, &c, 1);

        bit = 0;
        c = 0;
    }
}

int main(void)
{
    struct sigaction sa;


    printf("プロセスID: %d\n", getpid());

    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
    {
        perror("ハンドラの設定に失敗");
        exit(EXIT_FAILURE);
    }

    printf("シグナル待機中...\n");

    while (1)
        pause();
    return 0;
    
}