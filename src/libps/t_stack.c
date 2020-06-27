/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:23:12 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/14 14:07:19 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps_stack.h"

static void	swap(t_stack *self)
{
	if (self->size >= 2)
		ft_lstswptop(&(self->top));
}

static void	rotate(t_stack *self)
{
	if (self->size >= 2)
		ft_lstshftup(&(self->top));
}

static void	reverse_rotate(t_stack *self)
{
	if (self->size >= 2)
		ft_lstshftdown(&(self->top));
}

t_stack		*new_stack(void)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(*new))))
		return (NULL);
	new->size = 0;
	new->top = NULL;
	new->maximum = -1;
	new->minimum = -1;
	new->swap = swap;
	new->push = stk_push;
	new->rotate = rotate;
	new->reverse_rotate = reverse_rotate;
	new->sorted = stk_sorted;
	new->destructor = stk_destructor;
	return (new);
}
