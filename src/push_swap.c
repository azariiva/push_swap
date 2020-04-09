/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:44:57 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/09 15:35:31 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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
	if (!(ps = new_push_swap(av + 1, ac - 1, "\0\0\1")))
		throw_error();
	ps->make_move(ps, "sa");
	ps->make_move(ps, "sa");
	ps->destructor(&ps);
	return (0);
}
