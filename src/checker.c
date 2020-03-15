/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:45:54 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/15 21:52:30 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include "get_next_line.h"

static int	cmp(size_t a, size_t b)
{
	return (a > b);
}

static void	throw_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(0);
}

static void	throw_unexpected(void)
{
	ft_putendl_fd("Unexpected Error", STDERR_FILENO);
	exit(-1);
}

int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		pui_rv;
	int		debug;

	debug = 0;
	if (ac == 1)
		return (0);
	if (!(a = ps_crtlst(av + 1, ac - 1)))
		throw_error();
	b = NULL;
	//ps_debuginfo(a, b);
	if ((pui_rv = ps_procui(&a, &b, debug)) == 0)
	{
		if (ps_lstsorted(a, cmp) && b == NULL)
			ft_putendl("OK");
		else
			ft_putendl("KO");

	}
	else if (pui_rv == -1)
		throw_error();
	if (pui_rv == -2)
		throw_unexpected();
	ft_lstdel(&a, ps_del);
	ft_lstdel(&b, ps_del);
	return (0);
}
