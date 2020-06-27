/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_show_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 14:15:28 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/14 19:23:50 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps_push_swap.h"

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

static size_t	help(t_list **ptr, size_t size1, size_t size2)
{
	while (size1 > size2)
	{
		ft_putnbralgn(((t_ps *)(*ptr)->content)->val);
		*ptr = (*ptr)->next;
		size1--;
		ft_putchar('\n');
	}
	return (size2);
}

void			psw_show_stacks(t_push_swap *self)
{
	t_list	*ptr_a;
	t_list	*ptr_b;
	size_t	size;

	if (!self)
		return ;
	ptr_a = self->a->top;
	ptr_b = self->b->top;
	self->color ? ft_putstr("\033[32m") : 0;
	size = (self->a->size > self->b->size ? \
	help(&ptr_a, self->a->size, self->b->size) : \
	help(&ptr_b, self->b->size, self->a->size));
	while (size--)
	{
		ft_putnbralgn(((t_ps *)ptr_a->content)->val);
		ft_putchar('\t');
		ft_putnbralgn(((t_ps *)ptr_b->content)->val);
		ft_putchar('\n');
		ptr_a = ptr_a->next;
		ptr_b = ptr_b->next;
	}
	self->color ? ft_putstr("\033[34m") : 0;
	ft_putendl("---------------------\t---------------------");
	ft_putendl("          A           \t          B         \n");
	self->color ? ft_putstr("\033[0m") : 0;
}
