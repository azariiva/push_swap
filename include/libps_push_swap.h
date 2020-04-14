/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps_push_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 14:10:41 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/14 14:18:24 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_PUSH_SWAP

# define LIBPS_PUSH_SWAP

# include "libps_stack.h"
# include "get_next_line.h"
# include <limits.h>

# define WRONG_INPUT -1
# define OK 0
# define ALLOCATION_ERROR -2

typedef struct	s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	size_t	sorted;

	int		visualize:1;
	int		color:1;
	int		action:1;

	void	(*show_stacks)(struct s_push_swap *self);
	int		(*make_move)(struct s_push_swap *self, char const *action);
	void	(*destructor)(struct s_push_swap **self);
}				t_push_swap;

int			psw_fill_stack(t_stack *stk, char **src, int size);
void		psw_show_stacks(t_push_swap *self);

t_push_swap	*new_push_swap(char **string_arr, int size, char const vcq[3]);

#endif