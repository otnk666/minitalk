/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:02:41 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/23 09:58:43 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_char(pid_t pid, unsigned char c)
{
    int i;
    i = 7;
    
    while (i >= 0)
    {
        if((c & (1 << i )) == 0)
        {
            if(kill(pid, SIGUSR1) == -1)
                error_handler("Kill error", "SIGUSER1");
        }
        else
        {
            if(kill(pid, SIGUSR2) == -1)
                error_handler("Kill error", "SIGUSER2");
        }
        usleep(WAIT_TIME);
        i--;
    }
}

int main(int argc, char *argv[])
{
    pid_t server_pid;
    size_t i = 0;
    char *message;

    if (argc != 3)
        error_handler("Invalid arguments", "Usage: ./client [PID][message]");

    server_pid = atoi(argv[1]);
    if (server_pid <= 0)
        error_handler("Invalid PID", "PID must be a positive integer");
    
    message = argv[2];

    while ( i < strlen(message))
    {
        send_char(server_pid, message[i]);
        i++;
    }
    send_char(server_pid, '\n');
    return 0;
}