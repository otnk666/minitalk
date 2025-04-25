/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:58:34 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/23 09:26:55 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include "ft_printf.h"
# include <signal.h>
# include <stdio.h>

typedef struct sigagtion   t_sa;

# define BITS_CHAR 7

void    error_handler(char *message, char *sub);


# define WAIT_TIME 2000

#endif