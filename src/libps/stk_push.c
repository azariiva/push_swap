/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 14:00:29 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/14 14:07:05 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps_stack.h"

static void	update_maximum(t_stack *stk)
{
	t_list	*ptr;

	if (stk->size == 0)
		stk->maximum = -1;
	else
	{
		ptr = stk->top;
		stk->maximum = ((t_ps *)ptr->content)->index;
		while ((ptr = ptr->next))
			if (stk->maximum < ((t_ps *)ptr->content)->index)
				stk->maximum = ((t_ps *)ptr->content)->index;
	}
}

static void	update_minimum(t_stack *stk)
{
	t_list	*ptr;

	if (stk->size == 0)
		stk->minimum = -1;
	else
	{
		ptr = stk->top;
		stk->minimum = ((t_ps *)ptr->content)->index;
		while ((ptr = ptr->next))
			if (stk->minimum > ((t_ps *)ptr->content)->index)
				stk->minimum = ((t_ps *)ptr->content)->index;
	}
}

void		stk_push(t_stack *self, t_stack *src)
{
	if (src->size != 0)
	{
		ft_lsttrans(&(self->top), &(src->top));
		self->size++;
		src->size--;
		if (((t_ps *)self->top->content)->index == src->maximum)
			update_maximum(src);
		if (((t_ps *)self->top->content)->index == src->minimum)
			update_minimum(src);
		if (self->maximum == (size_t)-1 || \
		((t_ps *)self->top->content)->index > self->maximum)
			self->maximum = ((t_ps *)self->top->content)->index;
		if (self->minimum == (size_t)-1 || \
		((t_ps *)self->top->content)->index < self->minimum)
			self->minimum = ((t_ps *)self->top->content)->index;
	}
}
