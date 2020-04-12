/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:42:55 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/12 11:50:58 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include "stdio.h"

static void		ftpna_algn(char *buf, char *ptr)
{
	while (buf != ptr + 1)
	{
		*buf = ' ';
		buf++;
	}
}

static int		ft_putnbralgn(int n)
{
	char	buf[21];
	char	*ptr;
	int		negative;
	ssize_t	written;

	ptr = buf + 20;
	negative = (n < 0 ? 1 : 0);
	*ptr-- = ft_abs(n % 10) + '0';
	n = ft_abs(n / 10);
	while (n)
	{
		*ptr-- = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		*ptr-- = '-';
	ftpna_algn(buf, ptr);
	if ((written = write(STDOUT_FILENO, buf, 21)) == -1)
		return (EOF);
	else
		return (written);
}

static void		show_stacks(t_push_swap *self)
{
	t_list	*ptr_a;
	t_list	*ptr_b;
	size_t	size_a;
	size_t	size_b;

	if (self)
	{
		ptr_a = self->a->top;
		ptr_b = self->b->top;
		size_a = self->a->size;
		size_b = self->b->size;
		if (self->color)
			ft_putstr("\033[32m");
		while (size_a > size_b)
		{
			ft_putnbralgn(((t_ps *)ptr_a->content)->val);
			ptr_a = ptr_a->next;
			size_a--;
			ft_putchar('\n');
		}
		while (size_b > size_a)
		{
			ft_putstr("                     \t");
			ft_putnbralgn(((t_ps *)ptr_b->content)->val);
			ptr_b = ptr_b->next;
			size_b--;
			ft_putchar('\n');
		}
		while (size_a)
		{
			ft_putnbralgn(((t_ps *)ptr_a->content)->val);
			ft_putchar('\t');
			ft_putnbralgn(((t_ps *)ptr_b->content)->val);
			ft_putchar('\n');
			ptr_a = ptr_a->next;
			ptr_b = ptr_b->next;
			size_a--;
		}
		if (self->color)
			ft_putstr("\033[34m");
		ft_putendl("---------------------\t---------------------");
		ft_putendl("          A           \t          B         \n");
		if (self->color)
			ft_putstr("\033[0m");
	}
}

static int		make_move(t_push_swap *self, char const *action)
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
	else if (!ft_strcmp(action, "rb"))
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
		return (-1); // wrong input
	if (self->visualize)
		show_stacks(self);
	return (0); // everything is OK
}

static void		destructor(t_push_swap **self)
{
	if ((*self)->a)
		(*self)->a->destructor(&((*self)->a));
	if ((*self)->b)
		(*self)->b->destructor(&((*self)->b));
	free(*self);
	*self = NULL;
}

static int		giveindex(t_list *top, t_list *ptr)
{
	while (top != ptr)
	{
		if (((t_ps *)ptr->content)->val < ((t_ps *)top->content)->val)
			((t_ps *)top->content)->index++;
		else if (((t_ps *)ptr->content)->val == ((t_ps *)top->content)->val)
			return (1);
		else
			((t_ps *)ptr->content)->index++;
		top = top->next;
	}
	return (0);
}

static t_list	*lstnew(int val)
{
	t_ps	new;

	new.val = val;
	new.index = 1;
	return (ft_lstnew(&new, sizeof(new)));
}

static int		fill_stack(t_stack *stk, char **src, int size)
{
	int			i;
	t_list		*ptr;
	long long	num;
	int			sign;
	char		*str;

	i = 0;
	while (i < size)
	{
		str = src[i++];
		while (*str)
		{
			while (ft_isspace(*str))
				++str;
			if (!*str)
				break;
			sign = (*str == '-' ? 1 : 0);
			str += (*str == '+' || *str == '-');
			if (!ft_isdigit(*str))
				return (-1); // wrong input
			num = 0;
			while (ft_isdigit(*str))
			{
				num = num * 10 + *str++ - '0';
				if ((!sign && num > INT_MAX) || (sign && num - 1 > INT_MAX))
					return (-1); // wrong input
			}
			stk->size++;
			if (stk->top)
			{
				if (!(ptr->next = lstnew(sign ? -num : num)))
					return (-2); // allocation error
				ptr = ptr->next;
				if (giveindex(stk->top, ptr))
					return (-1); // wrong input
			}
			else
			{
				if (!(stk->top = lstnew(sign ? -num : num)))
					return (-2); // allocation error
				ptr = stk->top;
			}
		}
	}
	return (0); // everything is OK
}

t_push_swap		*new_push_swap(char **arr, int size, char const vcq[3])
{
	t_push_swap	*new;

	if (!(new = calloc(1, sizeof(*new))))
		return (NULL);
	if (!(new->a = new_stack()) || !(new->b = new_stack()) || \
	fill_stack(new->a, arr, size))
	{
		destructor(&new);
		return (NULL);
	}
	new->a->maximum = new->a->size;
	new->a->minimum = 1;
	new->visualize = vcq[0];
	new->color = vcq[1];
	new->action = vcq[2];

	new->show_stacks = show_stacks;
	new->make_move = make_move;
	new->destructor = destructor;
	return (new);
}
