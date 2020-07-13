/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:55:31 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/13 20:06:20 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H

# define LIBPS_H

# include "libps_push_swap.h"
# include "libft.h"

# define ILLEGAL_OPT "checker: illegal option -- %c\n\
Try \'checker -h\' for more information."
# define HELP_MSG "Usage: checker [OPTION]... [NUMBERS]...\n\
-v\t show stacks after each action\n-c\t colorize stacks\n\
-q\t show every action\n-h\t display this help and exit\n\
-s\t clear console after each action\n"
# define FLAGS "vcqsh"

size_t			throw_right_median(t_push_swap *ps, size_t median);
size_t			throw_left_median(t_push_swap *ps, size_t median);
void			throw_left_sorted(t_push_swap *ps);
void			throw_right(t_push_swap *ps, size_t	q);

void			solve_push_swap(t_push_swap *ps);

#endif
