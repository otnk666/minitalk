/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:52:27 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/21 16:11:36 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int signal_handler(int signo)
{
    static unsigned char c;
    static int bit;

    c = 0;
    bit = 0;
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
    pid_t   pid;

    pid = getpid();
    
    ft_printf("Server PID: %d\n", pid);

    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL ) || sigaction(SIGUSR2, &sa, NULL))
        error_handler("sigaction error",NULL)
    
    while (1)
    {
        pause();
        usleep(WAIT_TIME);
    }
    return 0;
    
}