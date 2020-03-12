/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:45:54 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 21:06:50 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include "get_next_line.h"

void	f_print(t_list *elem)
{
	if (elem)
	{
		ft_putnbr(elem->content_size);
		if (elem->next)
			ft_putchar(' ');
	}
	else
		ft_putstr("NULL");
}

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		puirv;

	if (ac == 1)
		return (0);
	if (!(a = ps_crtlst(av + 1, ac - 1)))
		ft_putendl_fd("Error", STDERR_FILENO);
	else
	{
		b = NULL;
		if ((puirv = ps_procui(&a, &b)) == -1)
			ft_putendl_fd("Error", STDERR_FILENO);
		else if (puirv == -2)
			ft_putendl_fd("Unexpected Error", STDERR_FILENO);
		else
			ft_lstiter(a, f_print);
		ft_lstdel_ic(&a);
		ft_lstdel_ic(&b);
	}
	return (0);
}
