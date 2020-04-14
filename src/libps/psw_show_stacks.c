/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_show_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 14:15:28 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/14 14:16:15 by blinnea          ###   ########.fr       */
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

void			psw_show_stacks(t_push_swap *self)
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
