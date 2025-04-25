/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:52:27 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/23 09:25:59 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int sig)
{
    static unsigned char c;
    static int bit;
    
    if (sig == SIGUSR1)
        c = (c << 1) | 0;
    else if (sig == SIGUSR2)
        c = (c << 1) | 1;
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
    pid_t   pid;

    pid = getpid();
    
    ft_printf("Server PID: %d\n", pid);

    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
   
    if (sigaddset(&sa.sa_mask, SIGUSR1) == -1 || sigaddset(&sa.sa_mask, SIGUSR2) == -1)
        error_handler("sigaddset error", NULL);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL ) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
        error_handler("sigaction error",NULL);

    
    while (1)
    {
        pause();
        usleep(WAIT_TIME);
    }
    return 0;
}