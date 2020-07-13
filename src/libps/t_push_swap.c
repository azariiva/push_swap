/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:42:55 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/13 20:04:48 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps_push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static int		help_make_move(t_push_swap *self, char const *action)
{
	if (self->action)
		ft_putendl(action);
	if (!ft_strcmp(action, "sa"))
		self->a->swap(self->a);
	else if (!ft_strcmp(action, "sb"))
		self->b->swap(self->b);
	else if (!ft_strcmp(action, "ss"))
	{
		self->a->swap(self->a);
		self->b->swap(self->b);
	}
	else if (!ft_strcmp(action, "pa"))
		self->a->push(self->a, self->b);
	else if (!ft_strcmp(action, "pb"))
		self->b->push(self->b, self->a);
	else if (!ft_strcmp(action, "ra"))
		self->a->rotate(self->a);
	else
		return (0);
	return (1);
}

static int		make_move(t_push_swap *self, char const *action)
{
	if (!help_make_move(self, action))
	{
		if (!ft_strcmp(action, "rb"))
			self->b->rotate(self->b);
		else if (!ft_strcmp(action, "rr"))
		{
			self->a->rotate(self->a);
			self->b->rotate(self->b);
		}
		else if (!ft_strcmp(action, "rra"))
			self->a->reverse_rotate(self->a);
		else if (!ft_strcmp(action, "rrb"))
			self->b->reverse_rotate(self->b);
		else if (!ft_strcmp(action, "rrr"))
		{
			self->a->reverse_rotate(self->a);
			self->b->reverse_rotate(self->b);
		}
		else
			return (WRONG_INPUT);
	}
	if (self->visualize)
		psw_show_stacks(self);
	if (self->step)
	{
		usleep(200000);
		system("clear");
	}
	return (OK);
}

static void		destructor(t_push_swap **self)
{
	if ((*self)->a)
		(*self)->a->destructor(&((*self)->a));
	if ((*self)->b)
		(*self)->b->destructor(&((*self)->b));
	ft_memdel((void **)self);
	*self = NULL;
}

t_push_swap		*new_push_swap(char **arr, int size, char const vcqs[4])
{
	t_push_swap	*new;

	if (!(new = (t_push_swap *)ft_memalloc(sizeof(t_push_swap))))
		return (NULL);
	if (!(new->a = new_stack()) || psw_fill_stack(new->a, arr, size) || \
	!(new->b = new_stack()))
	{
		destructor(&new);
		return (NULL);
	}
	new->a->maximum = new->a->size;
	new->a->minimum = 1;
	new->sorted = 0;
	new->visualize = vcqs[0];
	new->color = vcqs[1];
	new->action = vcqs[2];
	new->step = vcqs[3];
	new->show_stacks = psw_show_stacks;
	new->make_move = make_move;
	new->destructor = destructor;
	return (new);
}
