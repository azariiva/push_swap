/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:44:57 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/08 17:03:11 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libps.h"
#include <limits.h>
#include <stdio.h>

static void	throw_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(0);
}

int	main(int ac, char **av)
{
	t_push_swap	*ps;

	if (ac == 1)
		return (0);
	if (!(ps = new_push_swap(av + 1, ac - 1, 1, 1, 0)))
		throw_error();
	ps->show_stacks(ps);
	ps->make_move(ps, "sa");
	ps->make_move(ps, "ra");
	ps->make_move(ps, "rra");
	ps->make_move(ps, "pb");
	ps->make_move(ps, "pb");
	return (0);
}
