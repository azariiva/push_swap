/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:23:12 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/09 15:13:45 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static void	swap(t_stack *self)
{
	if (self->size >= 2)
		ft_lstswptop(&(self->top));
}

static void	push(t_stack *self, t_stack *src)
{
	if (src->size != 0)
		ft_lsttrans(&(self->top), &(src->top));
	self->size++;
	src->size--;
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
	new->swap = swap;
	new->push = push;
	new->rotate = rotate;
	new->reverse_rotate = reverse_rotate;
	new->sorted = sorted;
	new->destructor = destructor;
	return (new);
}
