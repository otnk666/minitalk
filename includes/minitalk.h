/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:58:34 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/21 14:51:35 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <stdio.h>

typedef struct sigagtion   t_sa;

# define BITS_CHAR 7

void    error_handler(char *message, char *sub);

# ifdef __linux__
# define WAIT_TIME 2000
# endif

# ifdef __APPLE__
# define WAIT_TIME 50
# endif

#endif