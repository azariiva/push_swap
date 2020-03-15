/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_showstcks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:02:01 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/15 17:04:35 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static void		ftpna_algn(char *buf, char *ptr)
{
	while (buf != ptr + 1)
	{
		*buf = ' ';
		buf++;
	}
}

static int		ft_putnbralgn_fd(int n, int fd)
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
	ftpna_algn(buf, ptr);
	if ((written = write(fd, buf, 21)) == -1)
		return (EOF);
	else
		return (written);
}

static int		ft_putnbralgn(int n)
{
	return (ft_putnbralgn_fd(n, STDOUT_FILENO));
}

void	ps_showstcks(t_psab *stacks)
{
	t_list	*a;
	t_list	*b;

	if (stacks->color)
		ft_putstr(GREEN_FONT);
	if (stacks)
	{
		a = stacks->a;
		b = stacks->b;
		while (a || b)
		{
			if (a)
			{
				ft_putnbralgn(((t_ps *)(a->content))->val);
				ft_putstr("\t");
				a = a->next;
			}
			else
				ft_putstr("                     \t");
			if (b)
			{
				ft_putnbralgn(((t_ps *)(b->content))->val);
				b = b->next;
			}
			else
				ft_putstr("                     ");
			ft_putchar('\n');
		}
		if (stacks->color)
			ft_putstr(BLUE_FONT);
		ft_putendl("---------------------\t---------------------");
		ft_putendl("          A           \t          B         \n");
	}
	if (stacks->color)
		ft_putstr(RESET_CONSOLE);
}
