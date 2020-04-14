/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps_stack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 13:50:21 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/14 14:12:23 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_STACK_H

# define LIBPS_STACK_H

#include "libft.h"

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
	size_t	maximum;
	size_t	minimum;

	void	(*swap)(struct s_stack *self);
	void	(*push)(struct s_stack *self, struct s_stack *source);
	void	(*rotate)(struct s_stack *self);
	void	(*reverse_rotate)(struct s_stack *self);
	int		(*sorted)(struct s_stack *self);
	void	(*destructor)(struct s_stack **self);
}				t_stack;

void			stk_push(t_stack *self, t_stack *src);
int				stk_sorted(t_stack *self);
void			stk_destructor(t_stack **self);

t_stack			*new_stack(void);

# endif
