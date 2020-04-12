/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:23:12 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/12 11:30:30 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static void	swap(t_stack *self)
{
	if (self->size >= 2)
		ft_lstswptop(&(self->top));
}

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

static void update_minimum(t_stack *stk)
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

static void	push(t_stack *self, t_stack *src)
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

static void	del(void *content, size_t size)
{
	if (size && content)
		free(content);
}

static int	ascending(t_list *cur, t_list *next)
{
	return (((t_ps *)cur->content)->index < ((t_ps *)next->content)->index);
}

static int	descending(t_list *cur, t_list *next)
{
	return (((t_ps *)cur->content)->index < ((t_ps *)next->content)->index);
}

static int	sorted(t_stack *self)
{
	t_list	*ptr;
	int		(*cmp)(t_list *, t_list *);

	ptr = self->top;
	if (!ptr || !ptr->next)
		return (ASCENDING | DESCENDING);
	cmp = (ascending(ptr, ptr->next) ? ascending : descending);
	ptr = ptr->next;
	while (ptr->next)
	{
		if (!cmp(ptr, ptr->next))
			return (UNSORTED);
		ptr = ptr->next;
	}
	return (cmp == ascending ? ASCENDING : DESCENDING);
}

static void	destructor(t_stack **self)
{
	if ((*self)->size)
		ft_lstdel(&((*self)->top), del);
	free(*self);
	*self = NULL;
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
	new->push = push;
	new->rotate = rotate;
	new->reverse_rotate = reverse_rotate;
	new->sorted = sorted;
	new->destructor = destructor;
	return (new);
}
