/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:55:31 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/09 15:32:50 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H

# define LIBPS_H

# include "libft.h"
# include "get_next_line.h"
# include <limits.h>

# define ASCENDING 1
# define DESCENDING 2
# define UNSORTED 0

typedef struct	s_ps
{
	int		val;
	size_t	index;
}				t_ps;

typedef struct	s_stack
{
	size_t	size;
	t_list	*top;

	void	(*swap)(struct s_stack *self);
	void	(*push)(struct s_stack *self, struct s_stack *source);
	void	(*rotate)(struct s_stack *self);
	void	(*reverse_rotate)(struct s_stack *self);
	int		(*sorted)(struct s_stack *self);
	void	(*destructor)(struct s_stack **self);
}				t_stack;

typedef struct	s_push_swap
{
	t_stack	*a;
	t_stack	*b;

	int		visualize:1;
	int		color:1;
	int		action:1;

	void	(*show_stacks)(struct s_push_swap *self);
	int		(*make_move)(struct s_push_swap *self, char const *action);
	void	(*destructor)(struct s_push_swap **self);
}				t_push_swap;

t_stack			*new_stack(void);
t_push_swap		*new_push_swap(char **string_array, int array_size, \
char const vcq[3]);

#endif
