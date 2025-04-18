/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:48:02 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/17 18:37:58 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    error_handler(char *message, char *sub)
{
    ft_printf("Error: %s", message);
    if (sub)
        ft_printf("(%s)\n", sub);
    exit(EXIT_FAILURE);
} 
    